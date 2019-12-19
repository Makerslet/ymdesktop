import QtQuick 2.8
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Dialog {
    property var userInfo
    x: (applicationWindow.contentItem.width - width) / 2
    y: (applicationWindow.contentItem.height - height) / 2

    width: 400
    height: 160

    GridLayout {
        columns: 2

        property int fontPixelSize: 18

        Label {text: "Логин:"; font.pixelSize: parent.fontPixelSize;}
        Label {
            text: userInfo? (userInfo.empty? "нд" : userInfo.login) : "нд"
            font.pixelSize: parent.fontPixelSize
        }

        Label {text: "Полное имя:"; font.pixelSize: parent.fontPixelSize;}
        Label {
            text: userInfo? (userInfo.empty? "нд" : userInfo.fullName) : "нд"
            font.pixelSize: parent.fontPixelSize
        }

        Label {text: "Имя:"; font.pixelSize: parent.fontPixelSize;}
        Label {
            text: userInfo? (userInfo.empty? "нд" : userInfo.firstName) : "нд"
            font.pixelSize: parent.fontPixelSize
        }

        Label {text: "Фамилия:"; font.pixelSize: parent.fontPixelSize;}
        Label {
            text: userInfo? (userInfo.empty? "нд" : userInfo.secondName) : "нд"
            font.pixelSize: parent.fontPixelSize
        }

        Label {text: "Почта:"; font.pixelSize: parent.fontPixelSize;}
        Label {
            text: userInfo? (userInfo.empty? "нд" : userInfo.email) : "нд"
            font.pixelSize: parent.fontPixelSize
        }
    }

    visible: false

}
