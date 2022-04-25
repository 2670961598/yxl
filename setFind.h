#pragma once
#ifndef SETFIND_H
#define SETFIND_H

#include <QWidget>
#include <QGuiApplication>
#include <QApplication>
#include <QtGui>
#include <QScreen>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QTabWidget>
#include <QListWidget>
#include <QScroller>
#include <QComboBox>
#include <QPushButton>
#include <QTime>
#include "set.h"
#include <QMessageBox>
#include <QDebug>

//写一个结构体，在这里相互传送数据，
//之后如果联网，只需要对结构体进行操作即可
typedef struct info{
    int*** number;
    bool findedSet = false;
    set* takeset;
    int minute;
    int second;
    int msec;
}info;
//因为头文件相互包含，所以这边声明类，并在cpp中包含相关头文件即可
class MainWindow;

class setFind : public QWidget
{
    Q_OBJECT
public:
    //屏幕大小
    int screenW;
    int screenH;

    //找座位的页面
    QWidget* setwindow;

    //下拉列表
    QComboBox* floor;


    //QLabel* test;
    //每一层楼的座位（二维数组）因为每次只显示一部分
    set** scatter;
    //当前显示的区域的座位情况
    int nowNumber[7][7];
    //当前的区域编号
    int now = 0;
    //与主页面相互通信的结构体
    info* myinfo;
    MainWindow* mainwindow;

    QImage* image;
    QIcon*  icon;


    QPushButton* AP;
    QPushButton* BP;
    QPushButton* CP;
    QPushButton* BGP;



    QWidget* AW;
    QWidget* BW;
    QWidget* CW;

public:
    setFind(const int W,const int H,info* acceptinfo,MainWindow* window);
    ~setFind();
    //总体UI
    void setupUI();

    //因为继承了widget，所以写一个show函数
    void show();
    //连接所有的信号与槽函数
    void connectAll();
    //制作座位数组
    void makeset();
    //将数组与实际显示座位联系起来
    void planset();
    //void makeAll();
    //更改之后，将所有的东西同步一下
    void changeSet(int x,const QString& test);
    //将座位上的信息反映射到数组中。
    void setnumChange();

public slots:
    //下拉列表的更改触发的槽函数
    void comboboxChanged(const QString& text);
    //检查座位信息是否符合要求，并且作出相应的信息变动与提示
    void checkset();

    void showA();
    void showB();
    void showC();


};

#endif // SET_H
