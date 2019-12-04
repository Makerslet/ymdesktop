#ifndef ICORE_H
#define ICORE_H

#include <memory>

class IUserInfo;
class INetworkManager;

class ICore {
public:
    virtual ~ICore() = default;
    virtual std::shared_ptr<IUserInfo> currentUser() = 0;
    virtual std::shared_ptr<INetworkManager> networkManager() = 0;
};

#endif // ICORE_H
