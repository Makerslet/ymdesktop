#ifndef APPLICATION_H
#define APPLICATION_H

#include "ICore.h"
#include "QmlHandler.h"

#include <QObject>
#include <QQmlApplicationEngine>
#include <memory>


class Application : public QObject
{
public:
    Application();

private:
    std::shared_ptr<ICore>  _coreApp;
    std::shared_ptr<QQmlApplicationEngine> _qmlAppEngine;
    std::shared_ptr<QmlHandler> _qmlHandler;
};


#endif // APPLICATION_H
