import QtQuick 1.0

Rectangle {
    width: 1000
    height: 700

    ListView {
        /* This view will contain subviews for current module hierarchy
         */
        //id: ocamlAPIView
        width: 1000
        height: 400
        anchors.fill: parent
        orientation: ListView.Horizontal
        model: ocamlAPIViewModel
        delegate: Rectangle {
            anchors.rightMargin: 1
            anchors.bottomMargin: 1
            anchors.leftMargin: 1
            anchors.topMargin: 1
            height: 20
            width: 40
            ListView {
                model: modelData.sons
                orientation: ListView.Vertical
                delegate: Rectangle {

                    Text {
                        text: modelData.name

                    }

                }
            }
        }
    }
    Rectangle {
        y: 400
        width:1000
        height:300
        border.color: "green"
        border.width: 2
        Text {
            id: value_viewer
            text: "<html><h2>bla</h2></html>"
            anchors.fill: parent
        }
    }
}
