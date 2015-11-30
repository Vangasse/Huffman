import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    id: vader;
    width: 500
    height: 500

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
//            Qt.quit();
        }
    }
    Rectangle{
        width: vader.width
        height: vader.height
        color: "steelblue"

        TextField{
            id: text1
            placeholderText: qsTr("Original File Adress")
            width: vader.width/2
            height: vader.height/20
            x: vader.width/4
            y: vader.height/1.6
        }
        TextField{
            id: text2
            placeholderText: qsTr("New File Address")
            width: vader.width/2
            height: vader.height/20
            x: text1.x
            y: text1.y + 2*height
        }

        Button{
            id: compress
            width: text1.width/2.5
            height: text1.height
            text: "Compress"
            x: text1.x
            y: text2.y + 2*height
            onClicked: {
                _huffman.startCompression(text1.text, text2.text)
            }
        }
        Button{
            id: decompress
            width: text1.width/2.5
            height: text1.height
            text: "Decompress"
            x: text1.x + text1.width - width
            y: text2.y + 2*height
            onClicked: {
                if(text2.text == "")
                    _huffman.startDeCom(text1.text)
                else
                    _huffman.startDeCom(text1.text, text2.text)
            }
        }
    }
}

