#ifndef QMLHANDLER_H
#define QMLHANDLER_H

#include "ICore.h"
#include "Authorization.h"
#include "UserHelper.h"

#include <QQmlApplicationEngine>
#include <memory>

class QmlHandler : public QObject
{
    Q_OBJECT
public:
    QmlHandler(std::shared_ptr<ICore>,
               std::shared_ptr<QQmlApplicationEngine>,
               QObject* parent = nullptr);
    Q_PROPERTY(Authorization* authController READ getAuthController CONSTANT)
    Q_PROPERTY(UserHelper* userHelper   READ getUserHelper CONSTANT)

public:
    Authorization* getAuthController();
    UserHelper* getUserHelper();

private:
    void createConnections();
    void registerQmlTypes();

private:
    // core objects
    std::shared_ptr<ICore> _core;
    std::shared_ptr<QQmlApplicationEngine>  _qmlEngine;

    // handlers objects
    std::unique_ptr<Authorization>  _authorization;
    std::unique_ptr<UserHelper>     _userInfo;
};

#endif // QMLHANDLER_H
