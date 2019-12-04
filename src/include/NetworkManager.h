#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include "INetworkManager.h"
#include "managers/ServerAccessManager.h"
#include "commands/common_and_base/base_requests_responses/IServerResponse.h"

#include <QObject>
#include <QSharedPointer>
#include <memory>

class NetworkManager : public INetworkManager
{
public:
    NetworkManager();

public slots:
    void tryLogin(const QString&, const QString&) override;

private slots:
    void responseReceived(QSharedPointer<ymlcpp::server_access::IServerResponse>);

private:
    std::unique_ptr<ymlcpp::server_access::ServerAccessManager> _accessManager;
};

#endif // NETWORKMANAGER_H
