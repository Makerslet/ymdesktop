#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Application.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Application ymdesctop;
    QQmlApplicationEngine qmlEngine;
    ymdesctop.registerContext(qmlEngine);
    qmlEngine.load("qrc:/main.qml");

    app.exec();
}
