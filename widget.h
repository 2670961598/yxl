#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QTime>
#include <QApplication>
#include <QtAndroid>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QAndroidJniEnvironment>
#include <QAndroidActivityResultReceiver>
#include <QDateTime>
#include <QFile>
#include <QMessageBox>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QWidget* mainwindow;


public slots:
    void onLaunch();
    void onGetActivityInfo();
    void onCapture();
    void sleep(unsigned int msec);

private:
    QLineEdit *m_actionEdit;
    QLabel*m_activityInfo;
    QLabel *m_capturedImage;
};

#endif // WIDGET_H
