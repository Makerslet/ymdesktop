import QtQuick 2.8
import QtQuick.Controls 2.1

Rectangle {
    color: "lightgrey"
    Row {
        anchors.centerIn: parent
        spacing: 20
        Image {
            source: "/Icons/PrevTrack"
            sourceSize.width: 30
            sourceSize.height: 30
        }
        Image {
            source: "/Icons/Play"
            sourceSize.width: 30
            sourceSize.height: 30
        }
        Image {
            source: "/Icons/NextTrack"
            sourceSize.width: 30
            sourceSize.height: 30
        }
    }

    Row {
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 30

        Image {
            source: "/Icons/DecreaseVolume"
            sourceSize.width: 20
            sourceSize.height: 20
        }

        Slider {
            width: 100
            height: 20
            from: 1
            value: 25
            to: 100
        }

        Image {
            source: "/Icons/IncreaseVolume"
            sourceSize.width: 20
            sourceSize.height: 20
        }
    }

}
