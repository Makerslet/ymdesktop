#ifndef USER_H
#define USER_H

#include <IUserInfo.h>

class User : public IUserInfo
{
public:
    User();
    bool isLoggedIn() const override;

public slots:
    void oauthTokenReceived(const QString&) override;
    void userInfoReceived(const ymlcpp::server_access::UserInfo&) override;

private:
    QString _oauthToken;
    ymlcpp::server_access::UserInfo _userInfo;
};

#endif // USER_H
