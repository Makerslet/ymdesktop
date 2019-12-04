#include "Core.h"
#include "User.h"
#include "NetworkManager.h"

Core::Core() :
    _currentUser(std::make_shared<User>()),
    _netManager(std::make_shared<NetworkManager>())
{}

std::shared_ptr<IUserInfo> Core::currentUser()
{
    return _currentUser;
}

std::shared_ptr<INetworkManager> Core::networkManager()
{
    return _netManager;
}
