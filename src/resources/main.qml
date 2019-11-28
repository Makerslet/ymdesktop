
import QtQuick 2.8
import QtQuick.Controls 2.6

ApplicationWindow
{
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("YMDesktop")

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
    }

    Authorization {
        anchors.fill: parent
    }

}
