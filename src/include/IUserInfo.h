#ifndef IUSERINFO_H
#define IUSERINFO_H

#include <QObject>

class IUserInfo : public QObject
{
    Q_OBJECT
public:
    virtual ~IUserInfo() = default;
    virtual bool isLoggedIn() const = 0;
//    virtual void logIn(const QString&, const QString&) = 0;

//public slots:
//    virtual void authorizationResult(bool authorized, QString msg = "") = 0;

//signals:
//    void loggedInChanged();
//    void logInSignal(const QString&, const QString&);
};

#endif // IUSERINFO_H
