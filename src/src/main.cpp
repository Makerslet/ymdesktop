#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Application.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Application ymdesctop;

    app.exec();
}
