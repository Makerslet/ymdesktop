#include "Authorization.h"
#include <QDebug>

Authorization::Authorization(bool isLoggedIn, QObject* parent) :
    QObject(parent),
    _isLoggedIn(isLoggedIn)
{}

bool Authorization::isLoggedIn() const
{
    return _isLoggedIn;
}

void Authorization::loginResponse(bool result, const QString& errMessage)
{
    qDebug() << "auth result" << result << errMessage;
    if(result != _isLoggedIn)
    {
        _isLoggedIn = result;
        emit loggedInChanged();
    }

    if(!result)
        qDebug() << "authorization failed" << "errMessage:" << errMessage;
}
