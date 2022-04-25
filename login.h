#ifndef LOGIN_H
#define LOGIN_H


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
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include "mainwindow.h"
class login : public QMainWindow
{
    Q_OBJECT

private:
    //分别为输入框的qt控件
    QLineEdit *name = new QLineEdit(this);
    QLineEdit *passward = new QLineEdit(this);


    QString username , pw;//目前输入框中的内容
    QLabel* title;
    //添加按钮
    QPushButton* user_login = new QPushButton(this);
    QPushButton* user_logon = new QPushButton(this);


public:
    //构造函数
    login(QWidget *parent = nullptr);
    void hhh();
    //与主窗口所连接的窗口指针
    QWidget* window;
    ~login();
    //连接窗口的函数 《-----------》为以后可能与其他窗口相连接做预备
    void connectWindow(QWidget* w);

signals:


public slots:
    //检查密码是否正确
    void checkpw();

    //注册功能
    void logon();
public:

    //连接所有的信号与槽函数，（仅限于自己的类内）
    void connectALL();

    //设置整体ui风格
    void SetupUI();

};

#endif // LOGIN_H
