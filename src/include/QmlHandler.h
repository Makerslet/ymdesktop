#ifndef QMLHANDLER_H
#define QMLHANDLER_H

#include "ICore.h"
#include "Authorization.h"

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

public:
    Authorization* getAuthController();

private:
    void createConnections();
    void registerQmlTypes();

private:
    // core objects
    std::shared_ptr<ICore> _core;
    std::shared_ptr<QQmlApplicationEngine>  _qmlEngine;

    // handlers objects
    std::unique_ptr<Authorization> _authorization;
};

#endif // QMLHANDLER_H
