#include "QmlHandler.h"

QmlHandler::QmlHandler(std::shared_ptr<ICore> core,
                       std::shared_ptr<QQmlApplicationEngine> qmlEngine,
                       QObject *parent) :
    QObject(parent),
    _core(core),
    _qmlEngine(qmlEngine),
    _authorization(std::make_unique<Authorization>(_core->currentUser()))
{
}

void QmlHandler::registerQmlTypes()
{
}

Authorization* QmlHandler::getAuthController()
{
    return _authorization.get();
}
