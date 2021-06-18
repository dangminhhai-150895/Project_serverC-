import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property bool running: false

    Rectangle{
        id: containerRectId
        anchors.fill: parent
        color: "beige"

        Rectangle{
            id: containedRectId
            width: 100
            height: 100
            x: 50
            y: 50
            color: "dodgerblue"

            PropertyAnimation on x {
                to: 530
                duration: 2000
                running: root.running
            }

            NumberAnimation on y {
                to: 300
                duration: 2000
                running: root.running
            }

            RotationAnimator on rotation{
                to: 600
                duration: 2000
                running: root.running
            }
        }

        NumberAnimation{
            target: containedRectId
            property: y
            to: 200
            duration: 2000

        }

        MouseArea{
            anchors.fill: parent
            onPressed: {
                root.running = true
            }
            onReleased: {
                root.running = false
            }
        }
        Rectangle{
            id: hainguyet
            x: 100
            y: 200
            width: 200
            height: 300
            color: "red"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    hainguyet.color = "green"
                }
            }
        }




    }
}
