#include "image.h"

Image::Image(QObject *parent) : QObject(parent)
{

}

QString Image::ImageToBase64(QString imgPath)
{
    QImage img(imgPath);
    QByteArray ba;
    QBuffer buf(&ba);
    buf.open(QIODevice::WriteOnly);
    img.save(&buf,"JPG");       // 把img写入QBuffer

    QByteArray base64 = ba.toBase64();    // 对图片做base64编码(不包含编码头)

//    QTextCodec * codec = QTextCodec::codecForName("UTF-8");
//    // 对图片urlencode
//    QByteArray imgData = codec->fromUnicode(base64).toPercentEncoding();

    QString imgData = QString(base64);
    return imgData;
}

