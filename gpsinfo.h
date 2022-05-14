#ifndef GPSINFO_H
#define GPSINFO_H

#include <QWidget>
#include <QGeoPositionInfoSource>
#include <QtDebug>

class GPSInfo : public QWidget
{
    Q_OBJECT
public:
    double nowGroundSpeed=0.0;
    double nowVerticalSpeed=0.0;
    double nowMagneticVariation=0.0;
    double nowHorizontalAccuracy=0.0;
    double nowVerticalAccuracy=0.0;
    double nowLongitude=0.0;
    double nowLatitude=0.0;
    double nowDirection=0.0;
    QString nowTimes="";
public:
    GPSInfo(QWidget *parent = 0)
        : QWidget(parent)
    {
        QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
        if (source) {
            connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                    this, SLOT(positionUpdated(QGeoPositionInfo)));
            source->setUpdateInterval(20);//设置刷新时间 单位毫秒
            source->startUpdates();//启动设备
        }
    }

private slots://槽函数中实现了GPS部分信息的读取
    void positionUpdated(const QGeoPositionInfo &info)
    {
        this->nowLongitude = info.coordinate().longitude();//经度
        this->nowLatitude = info.coordinate().latitude();//纬度
        nowDirection = info.attribute(QGeoPositionInfo::Direction);
        nowGroundSpeed = info.attribute(QGeoPositionInfo::GroundSpeed);
        nowVerticalSpeed = info.attribute(QGeoPositionInfo::VerticalSpeed);
        nowMagneticVariation = info.attribute(QGeoPositionInfo::MagneticVariation);
        nowHorizontalAccuracy = info.attribute(QGeoPositionInfo::HorizontalAccuracy);
        nowVerticalAccuracy = info.attribute(QGeoPositionInfo::VerticalAccuracy);
        nowTimes = info.timestamp().toString();

        qDebug() << (QString::number(this->nowLongitude, 10, 9)) << (QString::number(this->nowLatitude, 10, 9));
    }
};

#endif // GPSINFO_H
