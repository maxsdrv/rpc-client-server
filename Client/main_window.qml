import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

import qtprotobuf.testrpc 1.0
import echoClient 1.0

/*

*In this code, we add a ColumnLayout to organize the interface
*elements vertically. We replace the Text element displaying the
*list of operators with a ListView element that uses a ListModel
*as its data source.
*The delegate property of the ListView is set to a Text element 
*that displays the name and command of each operator in the model.
*We also modify the "Get Operators" button's onClicked handler to call
*the getOperators method of the client object and populate the 
*operatorsModel with the response. The visible property of the 
*operatorsLabel is set to true when the button is clicked, so that
 the label is displayed along with the list of operators.

*/


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
            text: "Operators:"
            font.bold: true
            font.pixelSize: 16
            visible: operatorsLabel.visible
        }

        ListView {
            id: operatorsListView
            model: operatorsModel
            Layout.fillWidth: true
            Layout.fillHeight: true
            delegate: Text {
                text: model.name + " (" + model.command + ")"
            }
        }

        Button {
            text: "Get Operators"
            background: Rectangle {
                color: "#696969"
                radius: 10
            }
            onClicked: {
                EchoClient.get_operators 
                // ().then(function(response) {
                //     operatorsModel.clear()

                //     for (var i = 0; i < response.operators.length; ++i) {
                //         operatorsModel.append(response.operators[i])
                //     }
                //     opearatorsLabel.visible = true
                // })


            }
        }
    }

    ListModel {
        id: operatorsModel
    }
}

