#include "UserHelper.h"

UserHelper::UserHelper()
{}

void UserHelper::userInfoReceived(const ymlcpp::server_access::UserInfo& fromYml)
{
    _userInfo.login = fromYml.account.login;
    _userInfo.fullName = fromYml.account.fullName;
    _userInfo.firstNmae = fromYml.account.firstName;
    _userInfo.secondName = fromYml.account.secondName;
    _userInfo.displayName = fromYml.account.displayName;
    _userInfo.createTime = fromYml.account.createTime;
    _userInfo.defaultEmail = fromYml.defaultEmail;

    emit uiInfoChanged();
}

QString UserHelper::getLogin() const
{
    return _userInfo.login;
}

QString UserHelper::getFullName() const
{
    return _userInfo.fullName;
}

QString UserHelper::getFirstName() const
{
    return _userInfo.firstNmae;
}

QString UserHelper::getSecondName() const
{
    return _userInfo.secondName;
}

QString UserHelper::getDisplayName()const
{
    return _userInfo.displayName;
}

QDateTime UserHelper::getCreateTime() const
{
    return _userInfo.createTime;
}

QString UserHelper::getEmail() const
{
    return _userInfo.defaultEmail;
}
