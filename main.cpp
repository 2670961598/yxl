#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QtAndroidExtras/QtAndroid>
#include <QThread>
#include <QTime>
#include <QtAndroid>

bool requestPermission1()
{
    QtAndroid::PermissionResult r = QtAndroid::checkPermission("android.permission.WRITE_EXTERNAL_STORAGE");
    if(r == QtAndroid::PermissionResult::Denied) {
        QtAndroid::requestPermissionsSync(QStringList()<<"android.permission.WRITE_EXTERNAL_STORAGE");
        r = QtAndroid::checkPermission("android.permission.WRITE_EXTERNAL_STORAGE");
        if(r == QtAndroid::PermissionResult::Denied) {
             return false;
        }
   }
   return true;
}


bool requestPermission2()
{
    QtAndroid::PermissionResult r = QtAndroid::checkPermission("android.permission.READ_EXTERNAL_STORAGE");
    if(r == QtAndroid::PermissionResult::Denied) {
        QtAndroid::requestPermissionsSync(QStringList()<<"android.permission.READ_EXTERNAL_STORAGE");
        r = QtAndroid::checkPermission("android.permission.READ_EXTERNAL_STORAGE");
        if(r == QtAndroid::PermissionResult::Denied) {
             return false;
        }
   }
   return true;
}



bool requestPermission3()
{
    QtAndroid::PermissionResult r = QtAndroid::checkPermission("android.permission.CAMERA");
    if(r == QtAndroid::PermissionResult::Denied) {
        QtAndroid::requestPermissionsSync(QStringList()<<"android.permission.CAMERA");
        r = QtAndroid::checkPermission("android.permission.CAMERA");
        if(r == QtAndroid::PermissionResult::Denied) {
             return false;
        }
   }
   return true;
}
void sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    qDebug() << "===========================1";
    MainWindow w;
    qDebug() << "===========================3";
    w.wait->show();
    sleep(2000);
    w.wait->hide();
    qDebug() << "===========================4";
    login in;
    qDebug() << "===========================5";
    in.window = w.mainwindow;
    in.hhh();

    qDebug() << "1"<< requestPermission1();
    qDebug() << "2"<<requestPermission2();
    qDebug() << "3"<< requestPermission3();


    //w.mainwindow->show();
    return a.exec();
}

/*
在安卓构建里面有一个build android apk 里面点击create templates可以生成
app相关信息的配置文件



*/
