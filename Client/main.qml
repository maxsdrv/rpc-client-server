import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import qtprotobuf.testrpc 1.0
import echoClient 1.0



ApplicationWindow {
    id: root
    width: 600
    height: 400
    visible: true
    title: "Operators List"

    Connections {
        target: EchoClient
        onOperators_list_changed: {
            OperatorsModel.clear
            for (var i = 0; i < EchoClient.operators_list.length; i++) {
                var operator = EchoClient.operators_list[i]
                console.log("LooLoooLoo: ", operator)
                OperatorsModel.append({
                    name: operator.name,
                    command: operator.command,
                    description: operator.description
                })
            }
        }
    }
    Component.onCompleted: EchoClient.get_operators()


    ListView {
        id: listView
        anchors.fill: parent
        model: EchoClient.operators
        delegate: Text {

        }
    }

}

