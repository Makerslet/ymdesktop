#ifndef ICORE_H
#define ICORE_H

#include "INetworkManager.h"
#include "IUserInfo.h"

#include <memory>

class ICore {
public:
    virtual ~ICore() = default;
    virtual std::shared_ptr<IUserInfo> currentUser() = 0;
    virtual std::shared_ptr<INetworkManager> networkManager() = 0;
};

#endif // ICORE_H
