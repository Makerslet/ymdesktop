#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include "INetworkManager.h"

#include <QObject>

class NetworkManager : public QObject, public INetworkManager
{
    Q_OBJECT
public:
    NetworkManager(QObject* parent = nullptr);
};

#endif // NETWORKMANAGER_H
