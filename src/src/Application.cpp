#include "Application.h"

#include <QQmlContext>

Application::Application() :
    _netManager(std::make_unique<NetworkManager>()),
    _currentUser(std::make_unique<YMusicUser>())
{
}

void Application::registerContext(QQmlApplicationEngine& engine)
{
    engine.rootContext()->setContextProperty("userModel", _currentUser.get());
}
