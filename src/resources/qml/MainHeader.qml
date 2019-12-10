import QtQuick 2.8
import QtQuick.Controls 2.6

Rectangle {
    color: "lightgrey"

    signal infoCliecked()

    Button {
        text: "Info"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 5
        onClicked: infoCliecked()
    }
}

