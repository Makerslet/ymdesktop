#ifndef INETWORKMANAGER_H
#define INETWORKMANAGER_H

#include <QObject>

class INetworkManager : public QObject
{
    Q_OBJECT
public:
    virtual ~INetworkManager() = default;

public slots:
    virtual void tryLogin(const QString&, const QString&) = 0;

signals:
    void loginResult(bool, const QString&);
};

#endif // INETWORKMANAGER_H
