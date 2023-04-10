import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

import qtprotobuf.testrpc 1.0
import echoClient 1.0



Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: "Kometa Client"
    color: "white"
    Rectangle {
        color: "#800020"
        anchors.fill: parent
    }
    // Load operators from Client
    Component.onCompleted: EchoClient.get_operators()
    // Value for store operator description
    property var descOperator: []
    ListView {
        id: listView
        model: EchoClient.operators
        anchors.top: parent.top
        anchors.bottom: descriptionArea.top
        anchors.left: parent.left
        anchors.right: parent.right
        topMargin: 5
        spacing: 2
        delegate: Item {
            height: itemWrapper.height + 10
            width: root.width
            Item {
                id: itemWrapper
                height: operatorColumn.height
                width: parent.width / 2 - 20
                anchors {
                    right: parent.right
                    left: parent.left
                    leftMargin: 10
                    rightMargin: 10
                    verticalCenter: parent.verticalCenter
                }

                Rectangle {
                    height: operatorColumn.height + 10
                    width: parent.width / 2 - 40
                    radius: 20
                    color: "#424242"
                    border.color: "#E91E63"
                    border.width: 1
                    anchors {
                        leftMargin: 10
                        rightMargin: 10
                        verticalCenter: parent.verticalCenter
                    }
                }
                Column {
                    id: operatorColumn
                    anchors {
                        left: parent.left
                        right: parent.right
                        leftMargin: 10
                        rightMargin: 10
                        verticalCenter: parent.verticalCenter
                    }
                    Text {
                        id: operatorName
                        anchors.left: parent.left
                        anchors.right: parent.right
                        font.pointSize: 12
                        font.weight: Font.Bold
                        color: "#ffffff"
                        text: model.name + ": " + model.command

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                root.descOperator = model.description
                                //for debugging
                                console.log(root.descOperator)
                                console.log(typeof root.descOperator)
                            }
                        }
                    }

                } // Column

            } // Item

        } // delegate

    } // ListView


    Rectangle {
        id: descriptionArea
        width: 300
        height: 300
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
                text: "Description: "
                font.pointSize: 14
                color: "#ffffff"
                font.underline: true
            }
            Repeater {
                model: descOperator
                Text {
                    text: modelData
                    font.pointSize: 12
                    color: "#ffffff"
                }
            }
        }
    } // Rectangle

    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        Rectangle {
            id: spacer
            Layout.fillWidth: true
        }

        RoundButton {
            text: "Run"
            onClicked: {

            }
        }
    }

}















