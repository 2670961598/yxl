#pragma once

#include <QtWidgets/QWidget>
#
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QList>
#include <QDebug>
#include <QImage>

class Test1 : public QWidget
{
    Q_OBJECT

public:
    Test1(QWidget *parent = Q_NULLPTR);
public slots:
    void ShowTheCapture();
    void SavePicture();
    void DisplayImage(int, QImage image);
    void Start();
    void Exit();
private:
    Ui::Test1Class ui;
    std::unique_ptr<QCamera> m_camera;                      // 摄像头
    std::unique_ptr<QCameraViewfinder> m_viewfinder;        // 摄像头取景器,用于显示摄像头数据
    std::unique_ptr<QCameraImageCapture> m_imageCapture;    // 截图部件，获取摄像头当前帧
};
