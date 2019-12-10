#include "QmlHandler.h"
#include "INetworkManager.h"

QmlHandler::QmlHandler(std::shared_ptr<ICore> core,
                       std::shared_ptr<QQmlApplicationEngine> qmlEngine,
                       QObject *parent) :
    QObject(parent),
    _core(core),
    _qmlEngine(qmlEngine),
    _authorization(std::make_unique<Authorization>(false)),
    _userInfo(std::make_unique<UserHelper>())
{
    registerQmlTypes();
    createConnections();
}

Authorization* QmlHandler::getAuthController()
{
    return _authorization.get();
}

UserHelper* QmlHandler::getUserHelper()
{
    return _userInfo.get();
}

void QmlHandler::createConnections()
{
    auto networkManager = _core->networkManager();
    connect(_authorization.get(), &Authorization::tryToLogIn, networkManager.get(), &INetworkManager::tryLogin);
    connect(networkManager.get(), &INetworkManager::loginResult, _authorization.get(), &Authorization::loginResponse);
    connect(networkManager.get(), &INetworkManager::userInfoReceived, _userInfo.get(), &UserHelper::userInfoReceived);
}


void QmlHandler::registerQmlTypes()
{

}
