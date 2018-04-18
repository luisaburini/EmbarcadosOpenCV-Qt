#ifndef FACEDETECT_H
#define FACEDETECT_H

#include <QObject>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <stdlib.h>
#include <QDebug>

using namespace cv;
using namespace std;

class FaceDetect : public QObject
{
    Q_OBJECT
public:
    explicit FaceDetect(QObject *parent = nullptr);


    Q_INVOKABLE void processImage(const QString &source, const QString &dest);

signals:

public slots:
};

#endif // FACEDETECT_H
