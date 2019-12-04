#include "Authorization.h"
#include <QDebug>

Authorization::Authorization(std::shared_ptr<IUserInfo> userInfo, QObject *parent) :
    QObject(parent),
    _userInfo(userInfo)
{}

bool Authorization::isLoggedIn() const
{
    return _userInfo->isLoggedIn();
}

void Authorization::tryToLogIn(const QString& login, const QString& password)
{
    qDebug() << "tryToLogIn" << login << password;
}
