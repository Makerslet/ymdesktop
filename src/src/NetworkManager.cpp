#include "NetworkManager.h"
#include "commands/authorization_commands/AuthorizationRequest.h"
#include "commands/authorization_commands/AuthorizationResponse.h"
#include "commands/common_and_base/common_enums/AppResponseTypes.h"

#include <QDebug>

NetworkManager::NetworkManager() :
    _accessManagerThread(std::make_unique<QThread>()),
    _accessManager(std::make_unique<ymlcpp::server_access::ServerAccessManager>())
{
    registerMetaTypes();

    _accessManager->moveToThread(_accessManagerThread.get());
    connect(_accessManager.get(), &ymlcpp::server_access::ServerAccessManager::responseReceived,
            this, &NetworkManager::responseReceived);
    connect(this, &NetworkManager::sendRequest,
            _accessManager.get(), &ymlcpp::server_access::ServerAccessManager::sendRequest);

    _accessManagerThread->start();
}

void NetworkManager::tryLogin(const QString& login, const QString& password)
{
    auto authCommand = QSharedPointer<ymlcpp::server_access::AuthorizationRequest>::create(
                login, password);

    emit _accessManager->sendRequest(authCommand);
}

void NetworkManager::responseReceived(QSharedPointer<ymlcpp::server_access::IServerResponse> response)
{
    if(response->appResponseType() == ymlcpp::server_access::AppResponseType::AuthorizationResponse)
    {
        auto authResponse = response.dynamicCast<ymlcpp::server_access::AuthorizationResponse>();
        if(authResponse->status() == ymlcpp::server_access::ResponseResult::Succes)
            emit loginResult(true, "");
        else
            emit loginResult(false, authResponse->errorDescriprion());
    }
}


void NetworkManager::registerMetaTypes()
{
    qRegisterMetaType<QSharedPointer<ymlcpp::server_access::IServerResponse>>
            ("QSharedPointer<IServerResponse>");
    qRegisterMetaType<QSharedPointer<ymlcpp::server_access::IServerRequest>>
            ("QSharedPointer<IServerRequest>");
}
