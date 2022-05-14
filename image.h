#ifndef IMAGE_H
#define IMAGE_H

#include <QObject>
#include <QByteArray>
#include <QString>

#include <QImage>
#include <QIODevice>
#include <QBuffer>
#include <QTextCodec>

class Image : public QObject
{
    Q_OBJECT
public:
    explicit Image(QObject *parent = 0);

    // Base64格式
    static QString ImageToBase64(QString imgPath);

signals:

public slots:
};

#endif // IMAGE_H

