#include "facedetect.h"

FaceDetect::FaceDetect(QObject *parent) : QObject(parent)
{

}

void FaceDetect::processImage(const QString &source, const QString &dest){
    Mat src, gray;

    QString mySource = source;

    string myConvertedSrc = mySource.remove(QRegExp("(file:/)")).toStdString();


    src = imread(myConvertedSrc,CV_LOAD_IMAGE_COLOR);

    if(!src.data)
        qDebug() << "Failed to load image!";

    CascadeClassifier faceCascade;

    string faceClassifierPath = "/home/root/haarcascade_frontalface_alt.xml";

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

        double aspectRatio = r.width/r.height;

        if(0.75 < aspectRatio && aspectRatio < 1.3){
            center.x = cvRound(r.x + r.width*0.5);
            center.y = cvRound(r.y + r.height*0.5);
            radius = cvRound((r.width + r.height)*0.25);
            circle(src, center, radius, Scalar(255, 0, 0), 3, 8, 0);
            qDebug() << "TINY FACE ASPECT RATIO OF FACES IS " + QString::number(center.x) + " " + QString::number(center.y);

        } else{
            rectangle(src, cvPoint(cvRound(r.x), cvRound(r.y)),
                      cvPoint(cvRound(r.x+r.width), cvRound(r.y+r.height)), Scalar(255, 0, 0), 3, 8, 0);

            qDebug() << "HUGE FACE ASPECT RATIO OF FACES IS "  + QString::number(r.width) + " " + QString::number(r.height);
        }
    }


    string myConvertedDest = dest.toStdString();
    imwrite(myConvertedDest, src);

}
