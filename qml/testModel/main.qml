import QtQuick 1.1

Rectangle {
    width: 800
    height: 360

    ListView {
        model: mainModel
        spacing: 5
        anchors.fill: parent
        orientation: ListView.Vertical
        //property alias model1: model
        delegate: ListView {
            model: homm
            height: 30

            orientation: ListView.Horizontal
            delegate: Text {
                //text: name + " " + sort
                text: "asfd"//model.name + " " + model.sort
                width: 50

                Component.onCompleted: console.log("Text created")
            }
            Component.onCompleted: {
                console.log("Inner ListView created");
                console.log(homm);
                //console.log(homm.itemsCount());
            }
        }
        Component.onCompleted: {
            console.log("Items count = " + mainModel.dataLen() );
        }
    }
}
