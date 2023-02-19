import QtQuick
import QtQuick.Controls 2.15


/**************************************************************************************/
//Lesson2

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Lesson2")

    property bool isLoading: true
//    BusyIndicator {
//        width: 50
//        height: 50
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.top: parent.top
//        running: comboBox.popup.visible
//    }
//    Button {
//        id: button
//        width: 300
//        height: 45
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.top: parent.top
//        anchors.topMargin: 60
//        text: "click"
//        onClicked: comboBox.popup.open()
//    }

//    ComboBox {
//        id: comboBox
//        width: 300
//        height: 45
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.top: parent.top
//        anchors.topMargin: 150
//        model: ["one", "two", "three"]
//    }

//    Dial {
//        width: 300
//        height: 45
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.top: parent.top
//        anchors.topMargin: 250
//        from: 1
//        to: 10
//        inputMode: Dial.Circular
//        onValueChanged: print(value)
//        snapMode: Dial.SnapAlways
//        stepSize: 1
//    }

//    Switch {
//        width: 300
//        height: 45
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.top: parent.top
//        anchors.topMargin: 350
//        text: "Turn on music"
//    }

    Rectangle {
        id: rect
        anchors.verticalCenter: parent.verticalCenter
        height: 40
        width: 40
        color: "red"
        x: 0
        }
    PropertyAnimation {
            duration: 5000
            target: rect
            property: "x"
            to: root.width - 40
            easing.type: Easing.OutInQuad
            running: true
        }
}
/****************************************************************************************************/
/****************************************************************************************************/
//Lesson 3


//Window {
//    height: 640
//    width: 480
//    visible: true
//    title: qsTr("Lesson3")

//Item {
//    anchors.fill: parent

//    ListModel{
//        id: users
//        ListElement {
//            group: "Администратор"
//            name: "Kek$ik"
//            messagesCnt: 2481
//            registrationDate: "16.03.2019"
//        }
//        ListElement {
//            group: "Модератор"
//            name: "Volk"
//            messagesCnt: 314
//            registrationDate: "31.03.2021"
//        }
//        ListElement {
//            group: "Модератор"
//            name: "Zloi"
//            messagesCnt: 5712
//            registrationDate: "1.02.2017"
//        }
//        ListElement {
//            group: "Пользователь"
//            name: "Булка"
//            messagesCnt: 122
//            registrationDate: "12.02.2021"
//        }
//        ListElement {
//            group: "Пользователь"
//            name: "Цымбалина Виталюк"
//            messagesCnt: 2123
//            registrationDate: "11.12.2016"
//        }
//        ListElement {
//            group: "Пользователь"
//            name: "Димас"
//            messagesCnt: 23
//            registrationDate: "11.03.2023"
//        }
//    }
//    ListView {
//        id: list
//        anchors.fill: parent
//        model: users
//        spacing: 1
//        // Хэдер
//        header: Rectangle {
//            width: parent.width
//            height: 20
//            color: "darkblue"
//            Text {
//                anchors.centerIn: parent
//                text: "HEADER"
//                color: "white"
//            }
//        }
//        // Футер
//        footer: Rectangle {
//            width: parent.width
//            height: 20
//            color: "darkgreen"
//            Text {
//                anchors.centerIn: parent
//                text: "FOOTER"
//                color: "white"
//            }
//        }
//        // Секции по группам пользователей
//        section.delegate: Rectangle {
//            width: parent.width
//            height: 20
//            color: "lightblue"
//            Text {
//                anchors.centerIn: parent
//                text: section
//                color: "darkblue"
//                font.weight: Font.Bold
//            }
//        }
//        section.property: "group"
//        // Сами элементы
//        delegate: Rectangle {
//            width: list.width
//            height: 50
//            radius: 3
//            border.width: 1
//            border.color: "darkgray"
//            color: "lightgray"
//            MouseArea {
//                anchors.fill: parent
//                onDoubleClicked: {
//                    list.model.remove(index)
//                }
//            }
//            Column {
//                anchors.fill: parent
//                Row {
//                    anchors.horizontalCenter: parent.horizontalCenter
//                    Text { text: "Пользователь"; font.weight: Font.Bold}
//                    Text { text: name }
//                    spacing: 20
//                }
//                Row {
//                    anchors.horizontalCenter: parent.horizontalCenter
//                    Text { text: "Количество сообщений"; font.weight: Font.Bold}
//                    Text { text: messagesCnt }
//                    spacing: 20
//                }
//                Row {
//                    anchors.horizontalCenter: parent.horizontalCenter
//                    Text { text: "Дата регистрации"; font.weight: Font.Bold}
//                    Text { text: registrationDate }
//                    spacing: 20
//                }
//            } // Column
//        }// Rectangle
//        focus: true
//        // Анимация появления элементов модели
//        populate: Transition {
//            NumberAnimation { properties: "x,y"; duration: 1500; easing.type: Easing.OutExpo}
//        }
//        // Анимация добавления элементов
//        add: Transition {
//            NumberAnimation { property: "opacity"; from: 0; to: 1.0; duration: 400 }
//            NumberAnimation { property: "scale"; from: 0; to: 1.0; duration: 100 }
//        }
//        // Удаление элемента
//        remove: Transition {
//            PropertyAnimation{ property: "opacity"; to: 0; duration: 1000}
//        }
//        // Вставка дефолтного пользователя при нажатии на пробел
//        Keys.onSpacePressed: model.insert(1, { group: "Пользователь",
//                                              name: "user", messagesCnt: 0,
//                                              registrationDate: "01.01.1970"})
//    }// ListView
//}// Item

//}





























/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/