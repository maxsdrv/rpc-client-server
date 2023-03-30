import QtQuick 2.4
import echoClient 1.0
import qtprotobuf.testrpc 1.0

Rectangle {
    id: root
    anchors.fill: parent
    color: "#303030"
    visible: true 
    MouseArea {
        anchors.fill: parent
    }

    ListView {
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        model: OperatorsModel

        delegate: Item {
            height: _someWrapper.height + 10
            width: root.width
            Item {
                id: _someWrapper
                height: _opColumn.height + 20
                width: parent.width / 2 - 20
                property bool ownOperator: EchoClient.message === model.modelData.from
                anchors {
                    right: _someWrapper.ownOperator ? parent.right : undefined
                    left: _someWrapper.ownOperator ? undefined : parent.left
                    rightMargin: _someWrapper.ownOperator ? 0 : 10
                    verticalCenter: parent.verticalCenter
                }
                Rectangle {
                    anchors.fill: parent
                    radius: 20
                    color: "#424242"
                    border.color: _someWrapper.ownOperator ? "#E91E63" : "#F48FB1"
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
                        id: _opName
                        property string from: _someWrapper.ownOperator ? qsTr("You") :
                        model.modelData.from
                        anchors.left: parent.left
                        anchors.right: parent.right
                        font.pointSize: 12
                        font.weight: Font.bold
                        color: "#ffffff"
                        text: _opName.from + ": "
                    }

                    Loader {
                        id: delegateLoader
                        anchors.left: parent.left
                        anchors.right: parent.right
                        height: item ? item.height : 0
                    }

                }

            }

        }

    }


}
