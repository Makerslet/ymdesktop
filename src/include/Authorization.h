#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include "IUserInfo.h"

#include <QObject>
#include <memory>

class Authorization : public QObject
{
    Q_OBJECT
public:
    Authorization(std::shared_ptr<IUserInfo>, QObject* parent = nullptr);
    Q_PROPERTY(bool loggedIn READ isLoggedIn NOTIFY loggedInChanged)

    Q_INVOKABLE void tryToLogIn(const QString& login, const QString& password);

public slots:
    bool isLoggedIn() const;

signals:
    void loggedInChanged();

private:
    std::shared_ptr<IUserInfo> _userInfo;
};

#endif // AUTHORIZATION_H
