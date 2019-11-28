#ifndef APPLICATION_H
#define APPLICATION_H

#include "NetworkManager.h"
#include "YMusicUser.h"

#include <QObject>
#include <QQmlApplicationEngine>
#include <memory>


class Application : public QObject
{
public:
    Application();
    void registerContext(QQmlApplicationEngine&);

private:
    std::unique_ptr<NetworkManager> _netManager;
    std::unique_ptr<YMusicUser>     _currentUser;
};


#endif // APPLICATION_H
