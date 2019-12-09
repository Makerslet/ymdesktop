#ifndef CORE_H
#define CORE_H

#include <ICore.h>

class Core : public ICore
{
public:
    Core();

    std::shared_ptr<IUserInfo> currentUser() override;
    std::shared_ptr<INetworkManager> networkManager() override;

private:
    void connectSignals();

private:
    std::shared_ptr<IUserInfo> _currentUser;
    std::shared_ptr<INetworkManager> _netManager;
};

#endif // CORE_H
