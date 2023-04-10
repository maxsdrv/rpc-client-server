import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import qtprotobuf.testrpc 1.0
import echoClient 1.0



ApplicationWindow {
    id: root
    width: 640
    height: 480
    visible: true
    title: "Operators List"

    Rectangle {
        //color: "#1E90FF"
        color: "#800020"
        //color: "#4B0082"
        //color: "#008080"
        //color: "#808000"
        anchors.fill: parent
        z: -1
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
//        anchors.fill: parent
        anchors.top: parent.top
        anchors.bottom: descriptionArea.top
        anchors.left: parent.left
        anchors.right: parent.right
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
                    Text {
                       id: _nameOp
                       anchors.left: parent.left
                       anchors.right: parent.right
                       font.pointSize: 12
                       font.weight: Font.Bold
                       color: "#ffffff"
                       text: model.name + ": " +  model.command

                       MouseArea {
                           anchors.fill: parent
                           onClicked: {
//                               selectedOperator = model
                               root.selectedOperator.push(model.description)
                               console.log(root.selectedOperator)
//                               console.log(selectedOperator.description)
                           }
                       }
                    } // Text
                } // Column
            } // Item
        } // delegate Item
        clip: true
    } // ListView

    property var selectedOperator: []


    Rectangle {
        id: descriptionArea
        width: listView.width / 2
        height: root.height - listView.height
        anchors.bottom: parent.bottom
        color: "#424242"
        radius: 20
        border.color: "#E91E63"
        border.width: 1
        Column {
            anchors.fill: parent
            anchors.margins: 10
            spacing: 10

            Text {
                text: "Description"
                font.pointSize: 14
                color: "#ffffff"
            }
            Repeater {
                model: root.selectedOperator
                Text{
                    text: modelData
                    font.pointSize: 12
                    color: "#ffffff"
                }
            }
        }
    }
}








