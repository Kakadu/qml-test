// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 360
    height: 360

/*    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }*/
    ListView {
        model: mainModel
        spacing: 5
        orientation: ListView.Horizontal
/*
        delegate: Rectangle {
            width: 50
            height: 20
            color: "red"
        }*/
        delegate: Text {
            text:"asdf"
            Component.onCompleted: console.log("Text created")
        }
        Component.onCompleted: {
            console.log("Items count = " + mainModel.dataLen() );
        }
    }
}
