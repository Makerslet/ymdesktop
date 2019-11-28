#include "YMusicUser.h"
#include <QDebug>

YMusicUser::YMusicUser()
{

}

bool YMusicUser::getIsLoggedIn() const
{
    return _isLoggedIn;
}

void YMusicUser::tryToLogIn(const QString& login, const QString& pass)
{
    qDebug() << "try to log in with login:" << login << " pass:" << pass;
}
