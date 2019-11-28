#include "Application.h"

#include <QQmlContext>

Application::Application() :
    _netManager(std::make_unique<NetworkManager>()),
    _currentUser(std::make_unique<YMusicUser>())
{
    connect(_currentUser.get(), &YMusicUser::tryLogIn,
            _netManager.get(), &NetworkManager::tryLogIn);
    connect(_netManager.get(), &NetworkManager::authorizationResult,
            _currentUser.get(), &YMusicUser::onAuthorzationResult);
}

void Application::registerContext(QQmlApplicationEngine& engine)
{
    engine.rootContext()->setContextProperty("userModel", _currentUser.get());
}
