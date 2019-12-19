import QtQuick 2.8
import QtQuick.Controls 2.6

Rectangle {
    color: "lightgrey"

    signal infoCliecked()

    Row {
        visible: !qmlHandler.userHelper.empty

        height: parent.height
        leftPadding: 20
        spacing: 50

        Image {
            source: "/Icons/User"
            sourceSize.width: parent.height
            sourceSize.height: parent.height

            MouseArea {
                anchors.fill: parent
                onClicked: infoCliecked()
            }
        }

        TextField {
            id: loginTextInput
            width: 200
            height: parent.height
            placeholderText: "Поиск"
            font.pixelSize: 18
        }
    }
}

