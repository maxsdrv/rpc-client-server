import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

import echoClient 1.0



Window {
    id: root
    visible: true
    maximumHeight: 1024
    maximumWidth: 800
    minimumHeight: 1024
    minimumWidth: 800
    title: "Kometa Client"
    color: "white"
    Rectangle {
        color: "#800020"
        anchors.fill: parent
    }
    // Load operators from Client
//    Component.onCompleted: EchoClient.get_operators()
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
//                                EchoClient.operator_selected(model.name)
                                EchoClient.operator_selected(model)
                            }
                        }
                        Connections {
                            target: EchoClient
                            function onOperator_selected(model) {
                                EchoClient.handle_operator_selected2(model)
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
    } // Rectangle description

    Rectangle {
        id: resultArea
        width: 300
        height: 300
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        color: "#424242"
        radius: 20
        border.width: 1
        border.color: "#E91E63"
        Column {
            anchors.fill: parent
            anchors.margins: 10
            spacing: 10
            Text {
                text: "Response:"
                font.pointSize: 14
                color: "#ffffff"
                font.underline: true
            }
        }
    } // Rectangle for display result of operator


    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.right: parent.left / 2
        spacing: 10
        Rectangle {
            id: spacer
        }
        RoundButton {
            text: "Run"
            onClicked: {

            }
        }

    } // RowLayout for Run button

    ColumnLayout {
        spacing: 10
        anchors.fill: parent
        Rectangle {
            id: tickerRect
            Layout.fillWidth: true
            Layout.preferredHeight: 40
            color: "white"
            radius: 5
            border.width: 1
            border.color: "black"

            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: "red"
                }
                GradientStop {
                    id: gradientStop
                    position: 1
                    color: "blue"
                }
            }

            Behavior on gradient {
                PropertyAnimation {
                    target: gradientStop
                    property: "position"
                    from: 1
                    to: 0
                    duration: 2000
                    loops: Animation.Infinite
                    running: true
                }

            }
        } // Animated Rectangle
    } // Split Down

}















