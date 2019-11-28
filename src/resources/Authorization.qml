import QtQuick 2.8
import QtQuick.Controls 2.5

Rectangle {
    Column{
        spacing: 5
        anchors {
            verticalCenter: parent.verticalCenter
            horizontalCenter: parent.horizontalCenter
        }

        Rectangle {
            width: 300
            height: 30

            Text {
                anchors {
                    left: parent.left
                    verticalCenter: parent.verticalCenter
                }

                text: "Логин"
                font.pixelSize: 25
            }

            Rectangle {
                width: 200
                height: parent.height
                anchors {
                    right: parent.right
                }
                border.color: "lightgreen"
                border.width: 1
                radius: 8
                TextInput {
                    anchors.fill: parent
                    text: ""
                    font.pixelSize: 20
                }
            }
        }

        Rectangle {
            width: 300
            height: 30

            Text {
                anchors {
                    left: parent.left
                    verticalCenter: parent.verticalCenter
                }

                text: "Пароль"
                font.pixelSize: 25
            }

            Rectangle {
                width: 200
                height: parent.height
                anchors {
                    right: parent.right
                }
                border.color: "lightgreen"
                border.width: 1
                radius: 8
                TextInput {
                    anchors.fill: parent
                    text: ""
                    font.pixelSize: 20
                }
            }
        }
        Rectangle {
            width: 300
            height: 30

            Button {
                flat: true
                text: "Войти"
                font.pixelSize: 25
            }
        }


    }

    //color: userModel.isLoggedIn ? "lightgreen" : "lightgrey"
}
