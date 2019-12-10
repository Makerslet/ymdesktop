import QtQuick 2.8
import QtQuick.Controls 2.5

Dialog {
    property var userInfo
    x: (applicationWindow.width - width) / 2
    y: (applicationWindow.height - height) / 2

    width: 400
    height: 180

    visible: false
}
