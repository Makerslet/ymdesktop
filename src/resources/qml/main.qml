
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

    Authorization {
        authController: qmlHandler.authController
    }

    UserInfoDialog {
        id: userInfoDialog
        userInfo: qmlHandler.userHelper
    }

    footer: PlayerControl{
        width: applicationWindow.width
        height: 70
    }

    header: MainHeader {
        id: header
        width: applicationWindow.width
        height: 50
    }

    Connections {
        target: header
        onInfoCliecked: userInfoDialog.visible = true
    }

}
