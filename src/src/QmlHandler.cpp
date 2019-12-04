#include "QmlHandler.h"
#include "INetworkManager.h"

QmlHandler::QmlHandler(std::shared_ptr<ICore> core,
                       std::shared_ptr<QQmlApplicationEngine> qmlEngine,
                       QObject *parent) :
    QObject(parent),
    _core(core),
    _qmlEngine(qmlEngine),
    _authorization(std::make_unique<Authorization>(false))
{
    registerQmlTypes();
    createConnections();
}

Authorization* QmlHandler::getAuthController()
{
    return _authorization.get();
}

void QmlHandler::createConnections()
{
    auto networkManager = _core->networkManager();
    connect(_authorization.get(), &Authorization::tryToLogIn, networkManager.get(), &INetworkManager::tryLogin);
    connect(networkManager.get(), &INetworkManager::loginResult, _authorization.get(), &Authorization::loginResponse);
}


void QmlHandler::registerQmlTypes()
{

}
