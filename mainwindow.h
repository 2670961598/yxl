#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
#include "setFind.h"
#include <QScroller>
#include "friends.h"
#include "gcarouselfigurewidget.h"
#include <QList>
#include <QString>
#include <QTextEdit>
#include <QPropertyAnimation>
#include "widget.h"
#include <QTimer>



class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    //窗口大小
    int W;
    int H;

    //自己的关于座位的信息
    info* pinfo;

    //构造函数
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //QTabWidget* tabwidget;
    //三个主页面
    Widget* camera;
    QWidget* wait;
    QWidget* mainwindow;
    QWidget* timer;


    int timesum = 0;
    int timeSum = 0;

    QLabel* time;
    QPushButton* leave;
    QPushButton* back;
    QTimer* timeslot;


    GCarouselFigureWidget* picture;



    QLabel* userhhh;
    QLabel* userInfor1;
    QLabel* userInfor2;
    QLabel* userInfor3;


    QLabel* mainwindoInfor;
    QLabel* connecterInfor;
private:
    //联系人页面
    QWidget* connecter;
    //个人页面
    QWidget* user;
    //反馈页面
    QWidget* backword;
    QWidget* beiwanglu;

    //主页面上的切换按钮，每个页面有三个
    QPushButton* mainwinMain;
    QPushButton* connectMain;
    QPushButton* _userMain;
    QPushButton* mainwinCon;
    QPushButton* connectCon;
    QPushButton* _userCon;
    QPushButton* mainwinUser;
    QPushButton* connectUser;
    QPushButton* _userUser;
    //选座界面的四个按钮
    QPushButton* findSet;
    QPushButton* helpFindSet;
    QPushButton* backSet;
    QPushButton* others;
    QPushButton* qiandao;
    //联系人界面的三个按钮
    QPushButton* addFriend;
    QPushButton* newFriend;
    //QPushButton* official;
    //个人页面的按钮与图片
    QPushButton* myselfimg;
    QPushButton* myselfInfor;
    QPushButton* Collection;
    QPushButton* friendcircle;
    QPushButton* settings;
    //与寻找窗口的连接指针
    setFind* self;
    //联系人列表的指针
    QListWidget* friendList;


    QPushButton* beiwangl;
    QPushButton* backw;
    QPushButton* beiwanglutop;
    QPushButton* beiwanglunote;
    QPushButton* backtop;
    QPushButton* backneirong;
    QPushButton* phonenumber;
    QPushButton* submit;

    QTextEdit* beiwangluneirong;
    QTextEdit* backtext;

    QLineEdit* phone;

    friends* myfriends;

public:
    //三个页面的UI
    void mainwindowUI(const int screenW,const int screenH,QWidget* mainwindow);
    void connecterUI(const int screenW,const int screenH,QWidget* connecter);
    void userUI(const int screenW,const int screenH,QWidget* user);
    //总的UI设计
    void SetupUI();

    //获取所有的位置信息，做一个初始化
    void makeset();
    //连接所有的信号与槽函数（本类内的）
    void connectAll();
    void nuller();
    void tijiao();


public slots:
    //槽函数

    void timeA();

    void timeSlot();
    \
    void timeout();

    void timerUI();
    //寻找座位的槽函数
    void findset();
    //退回座位的槽函数
    void backset();

    /*我在Tabwidget和三个单独页面中选择了三个单独的页面，
      因为三个页面的话相互不影响，耦合性低，一个出事了不至于
      所有的都出事，而且在tabwidget需要单独美化，不如单个页面方便
      （我最开始是tabwidget做的，后来更改为了目前的页面。而且这三个
      也好切换，添加到tabwidget中就好了
    */
    //转到主页面的槽函数
    void switchWindowToMain();
    //转到联系人页面的槽函数
    void switchWindowToConnect();
    //转到个人页面的槽函数
    void switchWindowToUser();


    void hidebeiwanglu();
    void hidefankui();

    void showbeiwanglu();
    void showfankui();
};
#endif // MAINWINDOW_H
