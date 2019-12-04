import QtQuick 2.8
import QtQuick.Controls 2.5

Dialog {
    property var authController

    x: (applicationWindow.width - width) / 2
    y: (applicationWindow.height - height) / 2

    width: 325
    height: 130

    visible: authController ? !authController.loggedIn : false
    modal: true
    closePolicy: Popup.NoAutoClose

    contentItem: Item {
        Column{
            spacing: 5

            TextField {
                id: loginTextInput
                width: 300
                height: 30
                placeholderText: "Логин"
                font.pixelSize: 20
            }

            TextField {
                id: passwordTextInput
                width: 300
                height: 30
                placeholderText: "Пароль"
                echoMode: TextInput.Password
                font.pixelSize: 20
            }

            Rectangle {
                width: 300
                height: 30

                Button {
                    flat: true
                    text: "Войти"
                    font.pixelSize: 20
                    onClicked: authController.tryToLogIn(loginTextInput.text, passwordTextInput.text)
                }
            }
        }

        Keys.onPressed: {
            if (event.key === Qt.Key_Enter || event.key === Qt.Key_Return)
                authController.tryToLogIn(loginTextInput.text, passwordTextInput.text)
        }
    }
}
