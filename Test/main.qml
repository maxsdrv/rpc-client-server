import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import qtprotobuf.testrpc 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Client Testing")

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
                    ServerMKO.request(request);
                    text = ""
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
                text: echo_engine.response.message
            }
        }

    }
}
