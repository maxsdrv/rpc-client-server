import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import qtprotobuf.testrpc 1.0
import echoClient 1.0



ApplicationWindow {
    id: root
    width: 600
    height: 400
    visible: true
    title: "Operators List"

    MouseArea {
        anchors.fill: parent
    }

    Connections {
        target: EchoClient
        onOperators_list_changed: {
            OperatorsModel.clear
            for (var i = 0; i < EchoClient.operators_list.length; i++) {
                var operator = EchoClient.operators_list[i]
                console.log("LooLoooLoo: ", operator)
            }
        }
    }
    Component.onCompleted: EchoClient.get_operators()


    ListView {
        id: listView
        anchors.fill: parent
        model: EchoClient.operators
        delegate: Item {
            height: _someWrapper.height + 10
            width: root.width
            Item {
                id: _someWrapper
                height: _opColumn.height
                width: parent.width/2 - 20
                anchors {
                    right: parent.right
                    left: parent.left
                    rightMargin: 10
                    leftMargin: 10
                    verticalCenter: parent.verticalCenter
                }

                Rectangle {
                    anchors.fill: parent
                    radius: 20
                    color: "#424242"
                    border.color: "#E91E63"
                    border.width: 1
                }
                Column {
                    id: _opColumn
                    anchors {
                        left: parent.left
                        right: parent.right
                        leftMargin: 10
                        rightMargin: 10
                        verticalCenter: parent.verticalCenter
                    }
                }
                Text {
                    id: _nameOp
                    anchors.left: parent.left
                    anchors.right: parent.right
                    font.pointSize: 12
                    font.pixelSize: 20
                    font.weight: Font.Bold
                    color: "black"
                    text: model.name + ": "
                    wrapMode: Text.WordWrap
                    width: parent.width
                    height: contentHeight
                    padding: 5
                }
            }
        }

//        delegate: Text {
//            text: model.name + " " + "( " + model.command + " )" + " " + model.description
//            font.pixelSize: 20
//            color: "black"
//            verticalAlignment: Text.AlignVCenter
//            horizontalAlignment: Text.AlignHCenter
//            wrapMode: Text.WordWrap
//            width: parent.width
//            height: contentHeight
//            padding: 5
//        }
        clip: true

    }

}

