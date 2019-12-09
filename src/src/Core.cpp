#include "Core.h"
#include "User.h"
#include "NetworkManager.h"

#include <QObject>

Core::Core() :
    _currentUser(std::make_shared<User>()),
    _netManager(std::make_shared<NetworkManager>())
{
    connectSignals();
}

void Core::connectSignals()
{
    QObject::connect(_netManager.get(), &INetworkManager::oauthTokenReceived,
            _currentUser.get(), &IUserInfo::oauthTokenReceived);
    QObject::connect(_currentUser.get(), &IUserInfo::getUserInfo,
                     _netManager.get(), &INetworkManager::getUserInfo);
    QObject::connect(_netManager.get(), &INetworkManager::userInfoReceived,
                     _currentUser.get(), &IUserInfo::userInfoReceived);
}

std::shared_ptr<IUserInfo> Core::currentUser()
{
    return _currentUser;
}

std::shared_ptr<INetworkManager> Core::networkManager()
{
    return _netManager;
}
