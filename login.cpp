#include "login.h"

login::login(QWidget *parent)
    :QMainWindow(parent)
{


    qDebug() << "+999999++++++++++++++++++++++++++++++++++++++++++";

    SetupUI();

    connectALL();
//    QMessageBox* Msg = new QMessageBox;
//    Msg->setText("您上的登陆信息实效，请重新登陆");
//    Msg->exec();
}

void login::hhh()
{

    QDir *photo = new QDir;
    QUrl url("file:///storage/emulated/0/Leo");
    QString path = url.toLocalFile();  //获取到的路径
    bool exist = photo->exists(path);
    qDebug()<<"photo"<<exist;

    if(photo->exists(path)){

        qDebug() << "存在+++++++++++++++++++++++++++++++++++++++++++";
        this->window->show();
    }else{
        qDebug() << "不存在+++++++++++++++++++++++++++++++++++++++++++";
        this->show();
    }


    qDebug() << "+++++++++++++++++++++++++++++++++++++++++++";

//    QMessageBox* Msg = new QMessageBox;
//    Msg->setText("您上的登陆信息实效，请重新登陆");
//    Msg->exec();
}

void login::connectWindow(QWidget* w){
    this->window = w;
}

void login::SetupUI()
{
    this->setWindowTitle("最漂亮的鄢歆璐姐姐的大创APP");

    //获取窗口大小，自适应所有大小的屏幕
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();
    const int screenW = screenRect.width();
    const int screenH = screenRect.height();
//    const int screenW = 500;
//    const int screenH = 1000;
    this->setFixedSize(screenW,screenH);
    qDebug()<< screenH << endl;
    qDebug()<< screenW << endl;

    //设置登陆和注册按钮的背景图片
    //login->setIcon();
    //logon->setIcon();
        //login->setParent(this);
        //logon->setParent(this);
    user_login->move(screenW/5,screenH*1.85/3);
    user_logon->move(screenW*3/5,screenH*1.85/3);
    user_login->resize(screenW/5,screenH/20);
    user_logon->resize(screenW/5,screenH/20);
    //设置输入和输出的文本窗口

//    name->setParent(this);
//    passward.setParent(this);
    name->resize(screenW*3/5,screenH/20);
    passward->resize(screenW*3/5,screenH/20);

    name->move(screenW/5,screenH*2/5);
    passward->move(screenW/5,screenH/2);
    //设置未输入时的显示内容
    name->setPlaceholderText("请输入账号/学号/昵称");
    passward->setPlaceholderText("请输入密码");
    //输入密码时，隐藏密码
    passward->setEchoMode(QLineEdit::Password);
    user_login->setObjectName("user_login");
    user_login->setStyleSheet("QPushButton#user_login{border-image:url(:/images/登录)}");
    user_login->setFlat(true);

    user_logon->setObjectName("user_logon");
    user_logon->setStyleSheet("QPushButton#user_logon{border-image:url(:/images/登录)}");
    user_logon->setFlat(true);
    name->show();
    passward->show();

//    QLabel* Mainlabel = new QLabel(this);
//    Mainlabel->move(screenW/5,screenH/3);
//    Mainlabel->resize(screenW*3/5,screenH/10);
//    Mainlabel->setText("最漂亮的鄢歆璐姐姐的大创APP");


//    titleText.setPointSize(60);
//    title->setFont(titleText);


    //设置背景图片
    this->setObjectName("this");
    this->setStyleSheet("QWidget#this{border-image:url(:/images/登录界面)}");
//    QPalette Main_background = this->palette();
//    Main_background.setBrush(QPalette::Background,QBrush(QPixmap(":/images/登录界面")));
//    setPalette(Main_background);

}

void login::checkpw(){
    //这里这个检查账号密码的函数主要是为了在以后拓展为联网APP时易更改做的
    //直接更改这个函数即可
//    QFile user("/name/user");
//    if(!user.open(QIODevice::ReadOnly | QIODevice::Text)){
//        QMessageBox* Msg = new QMessageBox;
//        Msg->setText("您上的登陆信息实效，请重新登陆");
//        Msg->exec();
//    }


    username = name->text();
    pw = passward->text();

    QFile user("assets:/user/information");//在这个文件中，保存有所有的预设的账号密码
    if(!user.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox* Msg = new QMessageBox;
        Msg->setText("您上次的登陆信息实效，请重新登陆");
        Msg->exec();
        delete  Msg;
    }else{

    }
    QTextStream lines(&user);
    QString checkname,checkpd;
    checkname = lines.readLine();
    checkpd = lines.readLine();
    qDebug() << checkname << "  " << checkpd;
//    std::vector<QString> name;
//    std::vector<QString> pas;
//    qDebug()<< username;
//    qDebug()<< pw;
//    qDebug()<< "槽函数";
//    qDebug()<< checkname;
//    qDebug()<< checkpd;

//    user.close();
    if(username == checkname && pw ==checkpd){
        this->hide();
        this->window->show();
        qDebug() << "登入成功";
        QDir *photo = new QDir;
        QUrl url("file:///storage/emulated/0/Leo");
        QString path = url.toLocalFile();  //获取到的路径
        bool exist = photo->exists(path);
        qDebug()<<"photo"<<exist;

        if(exist)
        {
            qDebug() << "存在";
        } else
        {
            //创建photo文件夹
            photo->mkdir(path);
            qDebug() << "不存在";
        }

    }else{
        QMessageBox* Msg = new QMessageBox;
        Msg->setText("账户或密码输入错误");
        Msg->exec();
        delete Msg;
    }
}



void login::connectALL(){//连接所有的槽函数
    connect(user_login,&QPushButton::clicked,this,&login::checkpw);
    connect(user_logon,&QPushButton::clicked,this,&login::logon);

}

void login::logon(){
//    QFile user("assets:/user/information");//在这个文件中，保存有所有的预设的账号密码
//    if(!user.open(QIODevice::ReadOnly | QIODevice::Text)){
//        QMessageBox* Msg = new QMessageBox;
//        Msg->setText("您本地文件有误，正在为您重新创建，您以前保存的所有账号密码之后均被清空，请注意！");
//        Msg->exec();
//        delete  Msg;
//        user.open( QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
//    }
//    QTextStream lines(&user);
//    username = name->text();
//    pw = passward->text();
//    QByteArray userName ,pW;
//    userName = username.toLatin1();
//    pW = pw.toLatin1();
//    char* uN = userName.data();
//    char* p = pW.data();
//    user.write(uN);
//    user.write(p);
    QMessageBox* Msg = new QMessageBox;
    Msg->setText("目前注册功能尚未开放，请静待更新");
    Msg->exec();
    delete  Msg;
}






login::~login(){
    delete title;
    delete user_login;
    delete user_logon;
}
