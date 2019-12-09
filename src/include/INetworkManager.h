#ifndef INETWORKMANAGER_H
#define INETWORKMANAGER_H

#include "commands/common_and_base/base_requests_responses/IServerRequest.h"
#include "commands/common_and_base/base_requests_responses/IServerResponse.h"
#include "commands/info_commands/user/UserInfoResponse.h"

#include <QObject>
#include <QSharedPointer>

class INetworkManager : public QObject
{
    Q_OBJECT
public:
    virtual ~INetworkManager() = default;

public slots:
    virtual void tryLogin(const QString&, const QString&) = 0;
    virtual void getUserInfo(const QString&) = 0;

protected slots:
    virtual void responseReceived(QSharedPointer<ymlcpp::server_access::IServerResponse>) = 0;

signals:
    void sendRequest(QSharedPointer<ymlcpp::server_access::IServerRequest>);
    void loginResult(bool, const QString&);
    void oauthTokenReceived(const QString&);
    void userInfoReceived(const ymlcpp::server_access::UserInfo&);
};

#endif // INETWORKMANAGER_H
