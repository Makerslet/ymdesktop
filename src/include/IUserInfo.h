#ifndef IUSERINFO_H
#define IUSERINFO_H

#include <QObject>
#include "commands/info_commands/user/UserInfoResponse.h"

class IUserInfo : public QObject
{
    Q_OBJECT
public:
    virtual ~IUserInfo() = default;
    virtual bool isLoggedIn() const = 0;

signals:
    void getUserInfo(const QString&);

public slots:
    virtual void oauthTokenReceived(const QString&) = 0;
    virtual void userInfoReceived(const ymlcpp::server_access::UserInfo&) = 0;
};

#endif // IUSERINFO_H
