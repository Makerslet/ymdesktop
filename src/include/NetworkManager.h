#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <memory>
#include "managers/ServerAccessManager.h"

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    NetworkManager();

public slots:
    void tryLogIn(const QString&, const QString&);
    void responseReceived(QSharedPointer<ymlcpp::server_access::IServerResponse>);

signals:
    void authorizationResult(bool, QString);
private:
    std::unique_ptr<ymlcpp::server_access::ServerAccessManager> _sam;
};

#endif // NETWORKMANAGER_H
