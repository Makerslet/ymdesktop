#include "Application.h"
#include "Core.h"

#include <QQmlContext>

Application::Application() :
    _coreApp(std::make_shared<Core>()),
    _qmlAppEngine(std::make_shared<QQmlApplicationEngine>(this)),
    _qmlHandler(std::make_shared<QmlHandler>(_coreApp, _qmlAppEngine))
{
    _qmlAppEngine->rootContext()->setContextProperty("qmlHandler", _qmlHandler.get());
    _qmlAppEngine->load("qrc:/Qml/main.qml");
}
