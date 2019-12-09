#include "NetworkManager.h"
#include "commands/authorization_commands/AuthorizationRequest.h"
#include "commands/authorization_commands/AuthorizationResponse.h"
#include "commands/info_commands/user/UserInfoRequest.h"
#include "commands/common_and_base/common_enums/AppResponseTypes.h"

Q_DECLARE_METATYPE(QSharedPointer<ymlcpp::server_access::IServerResponse>)
Q_DECLARE_METATYPE(QSharedPointer<ymlcpp::server_access::IServerRequest>)

NetworkManager::NetworkManager() :
    _accessManagerThread(std::make_unique<QThread>()),
    _accessManager(std::make_unique<ymlcpp::server_access::ServerAccessManager>())
{
    registerMetaTypes();

    _accessManager->moveToThread(_accessManagerThread.get());
    connect(this, &NetworkManager::sendRequest,
            _accessManager.get(), &ymlcpp::server_access::ServerAccessManager::sendRequest);
    connect(_accessManager.get(), &ymlcpp::server_access::ServerAccessManager::responseReceived,
            this, &NetworkManager::responseReceived);

    _accessManagerThread->start();
}

NetworkManager::~NetworkManager()
{
    _accessManagerThread->exit();
    _accessManagerThread->wait();
}

void NetworkManager::tryLogin(const QString& login, const QString& password)
{
    auto authCommand = QSharedPointer<ymlcpp::server_access::AuthorizationRequest>::create(
                login, password);
    emit sendRequest(authCommand);
}

void NetworkManager::getUserInfo(const QString& oauthToken)
{
    auto getUserInfoCmd = QSharedPointer<ymlcpp::server_access::UserInfoRequest>::create(oauthToken);
    emit sendRequest(getUserInfoCmd);
}

void NetworkManager::responseReceived(QSharedPointer<ymlcpp::server_access::IServerResponse> response)
{
    if(response->appResponseType() == ymlcpp::server_access::AppResponseType::AuthorizationResponse)
    {
        auto authResponse = response.dynamicCast<ymlcpp::server_access::AuthorizationResponse>();
        if(authResponse->status() == ymlcpp::server_access::ResponseResult::Succes)
        {
            emit loginResult(true, "");
            emit oauthTokenReceived(authResponse->oauthToken());
        }
        else
            emit loginResult(false, authResponse->errorDescriprion());
    }
    else if(response->appResponseType() == ymlcpp::server_access::AppResponseType::UserInfoResponse)
    {
        auto userInfoResponse = response.dynamicCast<ymlcpp::server_access::UserInfoResponse>();
        if(userInfoResponse->status() == ymlcpp::server_access::ResponseResult::Succes)
            emit userInfoReceived(userInfoResponse->userInfo());
    }
}


void NetworkManager::registerMetaTypes()
{
    qRegisterMetaType<QSharedPointer<ymlcpp::server_access::IServerResponse>>
            ("QSharedPointer<IServerResponse>");
    qRegisterMetaType<QSharedPointer<ymlcpp::server_access::IServerRequest>>
            ("QSharedPointer<IServerRequest>");
}
