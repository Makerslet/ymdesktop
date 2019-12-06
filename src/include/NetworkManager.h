#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include "INetworkManager.h"
#include "managers/ServerAccessManager.h"
#include "commands/common_and_base/base_requests_responses/IServerResponse.h"

#include <QObject>
#include <QSharedPointer>
#include <QThread>
#include <memory>

class NetworkManager : public INetworkManager
{
    Q_OBJECT
public:
    NetworkManager();
    ~NetworkManager() override;

public slots:
    void tryLogin(const QString&, const QString&) override;

private slots:
    void responseReceived(QSharedPointer<ymlcpp::server_access::IServerResponse>);

signals:
    void sendRequest(QSharedPointer<ymlcpp::server_access::IServerRequest>);

private:
    void registerMetaTypes();

private:
    std::unique_ptr<QThread> _accessManagerThread;
    std::unique_ptr<ymlcpp::server_access::ServerAccessManager> _accessManager;
};

#endif // NETWORKMANAGER_H
