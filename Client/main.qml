import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import qtprotobuf.testrpc 1.0

Window {
    id: root

    width: 640
    height: 480
    visible: true
    title: qsTr("Client Testing")
    color: "#faebd7"

    EchoRequest {
        id: request

        message: messageInput.text
    }

    Column {
        spacing: 20

        Row {
            spacing: 20

            Text {
                anchors.verticalCenter: parent.verticalCenter
                text: "Enter request message: "
            }

            TextField {
                id: messageInput

                anchors.verticalCenter: parent.verticalCenter
                width: 400
                onAccepted: {
                    ClientMKO.request(request);
                    text = "";
                }
            }

        }

        Row {
            spacing: 20

            Text {
                anchors.verticalCenter: parent.verticalCenter
                text: "Server respond:"
            }

            Text {
                anchors.verticalCenter: parent.verticalCenter
                text: ClientMKO.response.message
            }

        }

    }

    Rectangle {
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width
        height: 20
        radius: 3
        border.width: 1
        border.color: "darkgray"
        color: "lightgray"
        Text {
            anchors.centerIn: parent
            text: "List Operators"
            color: "black"
        }

        Column {
            spacing: 20
            y: parent.height + 20
            width: parent.width
            height: 20

            Row {
                spacing: 20
                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: "Commands:"
                    color: "black"
                }
                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: ClientMKO.response.message
                }
                
            }

        }
    }

    

}
