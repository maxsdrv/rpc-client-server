import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import qtprotobuf.testrpc 1.0

// Window {
//     id: root
//     width: 640
//     height: 480
//     visible: true
//     title: qsTr("Client Testing")
//     color: "#faebd7"

//     EchoRequest {
//       id: request
//       message: messageInput.text
//     }

// /*ListModel and ListView */
//     ListModel {
//         id: commands
//         ListElement {
//            group: "group"
//            name: "Add"
//         }
//     }
//     ListView {
//         id: list
//         anchors.fill: parent
//         model: commands
//         spacing: 1

//         header: Rectangle {
//             width: parent.width
//             height: 20
//             color: "darkblue"
//             Text {
//                 anchors.centerIn: parent
//                 text: "List Operators"
//                 color: "white"
//             }
//         }

//         delegate: Rectangle {
//             width: list.width
//             height: 20
//             radius: 3
//             border.width: 1
//             border.color: "darkgray"
//             color: "lightblue"
//             Text {
//                 anchors.centerIn: parent
//                 text: "Enter request message: "
//             }
         
//             Column {
//                 anchors.fill: root
//                 Row {
//                     anchors.horizontalCenter: parent.horizontalCenter
//                     Text {
//                         text: "Test"
//                         font.weight: Font.Bold
//                     }
//                     spacing: 20
//                 }
//             }
              
//         } // delegate Rectangle
  
//     } // ListView


    // Column {
    //     spacing: 20
    //     Row {
    //         spacing: 20
    //         Text {
    //             anchors.verticalCenter: parent.verticalCenter
    //             text: "Enter request message:"
    //         }

    //         TextField {
    //             id: messageInput
    //             anchors.verticalCenter: parent.verticalCenter
    //             width: 400
    //             onAccepted: {
    //                 ClientMKO.request(request);
    //                 text = ""
    //             }
    //         }
    //     }
    //     Row {
    //         id: respond
    //         spacing: 20
    //         Text {
    //             anchors.verticalCenter: parent.verticalCenter
    //             text: "Server respond:"
    //         }
    //         Text {
    //             anchors.verticalCenter: parent.verticalCenter
    //             text: ClientMKO.response.message
    //         }
    //     }

        /*Column {
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
        }*/

        /*ListModel and ListView */

    //}

// }



Item {
    height: 450
    width: 330
    ListModel {
        id: operators
        ListElement {
            group: 
        }
    }
}

