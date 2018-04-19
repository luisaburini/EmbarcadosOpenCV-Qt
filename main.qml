import QtQuick 2.9
import QtQuick.Window 2.2
import QtMultimedia 5.9
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.0

Window {
    visible: true
    width: Screen.width
    height: Screen.height


    Camera{
        id: camera
        deviceId: "/dev/video1"
        captureMode: Camera.CaptureStillImage
        imageCapture.onImageCaptured: {
            imagem.source = ""
            detectFace.processImage(camera.imageCapture.capturedImagePath, "/home/root/imagemProcessada.jpg")
            imagem.source = "file:///home/root/imagemProcessada.jpg"
            imagem.state = "PhotoPreview"
        }
    }

    VideoOutput{
        id: videoOutput
        source: camera
        visible: imagem.state == "CaptureMode"
        RoundButton{
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            width: Screen.width/5
            height: Screen.height/5
            text: "Tirar Foto!"
            onClicked: camera.imageCapture.capture()
        }
    }


    Image{
        id: imagem
        cache: false
        anchors.fill: parent
        state: "CaptureMode"
        visible: imagem.state == "PhotoPreview"
        states: [
            State{
                name: "CaptureMode"
            },
            State{
                name: "PhotoPreview"
            }
        ]

        MouseArea{
            anchors.fill: imagem
            onClicked: imagem.state = "CaptureMode"
        }
    }

}
