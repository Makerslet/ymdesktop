#ifndef USERHELPER_H
#define USERHELPER_H

#include "commands/info_commands/user/UserInfoResponse.h"
#include <QObject>

class UserHelper : public QObject
{
    Q_OBJECT

    struct UiUserInfo {
        bool empty;
        QString login;
        QString fullName;
        QString firstNmae;
        QString secondName;
        QString displayName;
        QDateTime createTime;
        QString defaultEmail;
    };

public:
    UserHelper();
    Q_PROPERTY(bool empty           READ getEmpty   NOTIFY uiInfoChanged)
    Q_PROPERTY(QString login        READ getLogin   NOTIFY uiInfoChanged)
    Q_PROPERTY(QString fullName     READ getFullName NOTIFY uiInfoChanged)
    Q_PROPERTY(QString firstName    READ getFirstName   NOTIFY uiInfoChanged)
    Q_PROPERTY(QString secondName   READ getSecondName  NOTIFY uiInfoChanged)
    Q_PROPERTY(QString displayName  READ getDisplayName NOTIFY uiInfoChanged)
    Q_PROPERTY(QDateTime createTime READ getCreateTime  NOTIFY uiInfoChanged)
    Q_PROPERTY(QString email        READ getEmail       NOTIFY uiInfoChanged)

public slots:
    void userInfoReceived(const ymlcpp::server_access::UserInfo&);

    bool getEmpty() const;
    QString getLogin() const;
    QString getFullName() const;
    QString getFirstName() const;
    QString getSecondName() const;
    QString getDisplayName()const;
    QDateTime getCreateTime() const;
    QString getEmail() const;

signals:
    void uiInfoChanged();

private:
    UiUserInfo _userInfo;
};

#endif // USERHELPER_H
