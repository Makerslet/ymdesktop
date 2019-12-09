#include "User.h"
#include <QDebug>

User::User()
{
}

bool User::isLoggedIn() const
{
    return !_oauthToken.isEmpty();
}

void User::oauthTokenReceived(const QString& oauthToken)
{
    _oauthToken = oauthToken;
    getUserInfo(_oauthToken);
}

void User::userInfoReceived(const ymlcpp::server_access::UserInfo& ui)
{
    _userInfo = ui;
    qDebug() << _userInfo.account.firstName;
}
