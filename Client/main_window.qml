import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import qtprotobuf.testrpc 1.0

ApplicationWindow {
    id: main_window
    visible: true
    width: 640
    height: 480
    title: qsTr("MKOClient")
//    Rectangle {
//        id: background
//        anchors.fill: parent
//        color: "#303030"
//    }

//    Rectangle {
//        id: operators
//        visible: true
//        color: "#00ffff"
//        anchors.top: parents.top
//        width: main_window.width / 2
//        height: main_window.height
//    }

    ListView {
       height: main_window.height
       width: main_window.width / 2
       model:
    }
}
