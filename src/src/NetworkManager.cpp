#include "NetworkManager.h"
#include "commands/authorization_commands/AuthorizationRequest.h"
#include "commands/authorization_commands/AuthorizationResponse.h"

NetworkManager::NetworkManager() :
    _sam(std::make_unique<ymlcpp::server_access::ServerAccessManager>())
{
    connect(_sam.get(), &ymlcpp::server_access::ServerAccessManager::responseReceived,
            this, &NetworkManager::responseReceived);
}

void NetworkManager::tryLogIn(const QString& login, const QString& password)
{
    auto loginCommand = QSharedPointer<ymlcpp::server_access::AuthorizationRequest>::create(
                login, password);

    _sam->sendRequest(loginCommand);
}

void NetworkManager::responseReceived(QSharedPointer<ymlcpp::server_access::IServerResponse> response)
{
    if(response->appResponseType() == ymlcpp::server_access::AppResponseType::AuthorizationResponse)
    {
        auto authorizatioResponse = response.dynamicCast<ymlcpp::server_access::AuthorizationResponse>();
        if(authorizatioResponse->status() == ymlcpp::server_access::ResponseResult::Succes)
            emit authorizationResult(true, "");
        else
            emit authorizationResult(false, authorizatioResponse->errInfo().message);

    }
}
