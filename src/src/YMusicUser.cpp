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
    emit tryLogIn(login, pass);
}

void YMusicUser::onAuthorzationResult(bool succes, const QString& message)
{
    if(_isLoggedIn != succes)
    {
        _isLoggedIn = succes;
        emit isLoggedInChanged();
    }

    if(!succes)
        qDebug() << "error message: " << message;
}
