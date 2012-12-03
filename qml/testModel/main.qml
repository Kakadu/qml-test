// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 360
    height: 360


    ListView {
        model: mainModel
        spacing: 5
        orientation: ListView.Horizontal


        delegate: Text {
            text: objectName
            Component.onCompleted: console.log("Text created")
        }
        Component.onCompleted: {
            console.log("Items count = " + mainModel.dataLen() );
        }
    }
}
