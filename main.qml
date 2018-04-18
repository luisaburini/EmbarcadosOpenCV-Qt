import QtQuick 2.9
import QtQuick.Window 2.2
import QtMultimedia 5.9
import QtQuick.Dialogs 1.0

Window {
    visible: true
    width: Screen.width
    height: Screen.height


    FileDialog{
        id: fileDialog
        title: "Escolha a foto para detecção facial"
        folder: shortcuts.home
        nameFilters: ["Image files (*.jpg *.png)"]

        onAccepted: {
            console.log("A foto escolhida: " + fileDialog.fileUrl)
            detectFace.processImage(fileDialog.fileUrl.toString(), "/home/root/imagemProcessada.jpg")
            imagem.source = "file:///home/root/imagemProcessada.jpg"

        }
        onRejected: {
            console.log("Cancelado")
            Qt.quit()
        }
        Component.onCompleted: visible = true
    }

    Image{
        id: imagem
        anchors.fill: parent
    }


}
