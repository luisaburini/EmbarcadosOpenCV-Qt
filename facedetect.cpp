#include "facedetect.h"

FaceDetect::FaceDetect(QObject *parent) : QObject(parent)
{

}

void FaceDetect::processImage(const QString &source, const QString &dest){
    Mat src, gray;

    string myConvertedSrc = source.toStdString();

    src = imread(myConvertedSrc,CV_LOAD_IMAGE_COLOR);

    if(!src.data)
        qDebug() << "Failed to load image!";

    CascadeClassifier faceCascade;

    string faceClassifierPath = "/usr/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml";

    if(!faceCascade.load(faceClassifierPath))
        qDebug() << "Failed to load classifier!";

    cvtColor(src, gray, CV_BGR2GRAY);

    equalizeHist(gray, gray);

    vector<Rect> faces;

    faceCascade.detectMultiScale(gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30,30));

    for(int i=0; i<faces.size(); i++){
        Rect r = faces[i];

        Point center;

        int radius;

        center.x = cvRound(r.x + r.width*0.5);
        center.y = cvRound(r.y + r.height*0.5);
        radius = cvRound((r.width + r.height)*0.25);
        circle(src, center, radius, Scalar(255, 0, 0), 3, 8, 0);

    }


    string myConvertedDest = dest.toStdString();
    imwrite(myConvertedDest, src);

}
