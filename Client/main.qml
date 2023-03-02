import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

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
                text: "Enter request message:"
            }

            TextField {
                id: messageInput
                anchors.verticalCenter: parent.verticalCenter
                width: 400
                onAccepted: {
                    ClientMKO.request(request);
                    text = ""
                }
            }
        }
        Row {
            id: respond
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

        Column {
            spacing: 50
            Row {
                spacing: 50
                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: "List Operators:"
                }

                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: //TODO operator list from server .json
                          ""
                }
            }
        }

    }
}





















