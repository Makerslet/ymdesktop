#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include "IUserInfo.h"

#include <QObject>
#include <memory>

class Authorization : public QObject
{
    Q_OBJECT
public:
    Authorization(bool isLoggedIn, QObject* parent = nullptr);
    Q_PROPERTY(bool loggedIn READ isLoggedIn NOTIFY loggedInChanged)

public slots:
    bool isLoggedIn() const;
    void loginResponse(bool, const QString&);

signals:
    void loggedInChanged();
    void tryToLogIn(const QString& login, const QString& password);

private:
    bool _isLoggedIn;
};

#endif // AUTHORIZATION_H
