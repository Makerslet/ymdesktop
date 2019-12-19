import QtQuick 2.8
import QtQuick.Controls 2.5

Dialog {
    property var authController

    x: (applicationWindow.contentItem.width - width) / 2
    y: (applicationWindow.contentItem.height - height) / 2

    width: 400
    height: 180

    visible: authController ? !authController.loggedIn : false
    modal: true
    closePolicy: Popup.NoAutoClose

    contentItem: Item {
        Column{
            spacing: 5

            TextField {
                id: loginTextInput
                width: 300
                height: 45
                placeholderText: "Логин"
                font.pixelSize: 20
            }

            TextField {
                id: passwordTextInput
                width: 300
                height: 45
                placeholderText: "Пароль"
                echoMode: TextInput.Password
                font.pixelSize: 20
            }

            Row {
                spacing: 50

                Button {
                    flat: true
                    text: "Войти"
                    font.pixelSize: 20
                    onClicked: authController.tryToLogIn(loginTextInput.text, passwordTextInput.text)
                }

                Button {
                    flat: true
                    text: "Отмена"
                    font.pixelSize: 20
                    onClicked: close()
                }
            }
        }

        Keys.onPressed: {
            if (event.key === Qt.Key_Enter || event.key === Qt.Key_Return)
                authController.tryToLogIn(loginTextInput.text, passwordTextInput.text)
        }
    }
}
