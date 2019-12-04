
import QtQuick 2.8
import QtQuick.Controls 2.6
import QtQuick.Controls.Material 2.12

ApplicationWindow
{
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("YMDesktop")

    Material.theme: Material.Light


    /*
    menuBar: Rectangle {
        height: 50
        color: "lightgreen"
    }

    header: Rectangle {
        height: 50
        color: "red"
    }

    footer: Rectangle {
        height: 50
        color: "yellow"
    }*/

    Authorization {
        authController: qmlHandler.authController
    }

}
