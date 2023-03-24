import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

import qtprotobuf.testrpc 1.0
import echoClient 1.0



ApplicationWindow {
    visible: true
    width: 400
    height: 500
    title: "Kometa Client"
    color: "white"


    EchoRequest {
        id: request
        message: echoField.text
    }


    ColumnLayout {
        TextField {
            id: echoField
            placeholderText: "Enter text to echo"
            Layout.fillWidth: true
            onAccepted: {
                EchoClient.request(request)
                text = ""
            }
        }

        Text {
            id: responseText
            text: ""
            font.pixelSize: 14
            visible: false
        }

        Button {
            text: "Echo"
            background: Rectangle {
                color: "#696969"
                radius: 10
            }
            
            onClicked: {
                var response = EchoClient.response.message
                responseText.text = EchoClient.response.message
                responseText.visible = true
                console.log(response)
            }
        }

        Text {
            id: operatorsLabel
            text: "Operators: " + EchoClient.operators_list.join(", ")
            font.bold: true
            font.pixelSize: 16
            visible: EchoClient.operators_list.length > 0
        }

        

        Button {
            text: "Get Operators"
            background: Rectangle {
                color: "#696969"
                radius: 10
            }
            onClicked: {
                EchoClient.get_operators()
            }
        }

        Connections {
            target: EchoClient
            onSend_operators: {
                console.log("Received operators: " + EchoClient.operators_list)
            }
        }
        
            
    }
    

}
