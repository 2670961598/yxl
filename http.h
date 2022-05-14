#ifndef HTTP_H
#define HTTP_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QByteArray>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QEventLoop>

class Http : public QObject
{
    Q_OBJECT
public:
    explicit Http(QObject *parent = 0);

    static bool post_sync(QString url,QMap<QString,QString> header,QByteArray & requestData,QByteArray & replyData);
signals:

public slots:
};

#endif // HTTP_H

