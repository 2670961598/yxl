#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //临时添加一部分，开始加载的动画
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();
    const int screenW = screenRect.width();
    const int screenH = screenRect.height();
    this->wait = new QWidget;
    wait->resize(screenW,screenH);
    wait->move(0,0);
    QImage img(":/images/开屏");
    img = img.scaled(screenW,screenH);//图片缩放
    QLabel* underBGI = new QLabel(wait);
    underBGI->setPixmap(QPixmap::fromImage(img));
    underBGI->resize(screenW,screenH);
    underBGI->move(0,0);
    wait->show();
    this->SetupUI();
    this->connectAll();
    qDebug() << "===========================2";
    this->makeset();
    qDebug() << "===========1==========2";
}

void MainWindow::SetupUI(){

    //获取窗口大小，自适应所有大小的屏幕
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();
    const int screenW = screenRect.width();
    const int screenH = screenRect.height();
    this->W = screenW;
    this->H = screenH;
    qDebug()<< screenH << endl;
    qDebug()<< screenW << endl;



//    const int screenW = 500;
//    const int screenH = 1000;
    this->setFixedSize(screenW,screenH);
    //创建多页面
    //tabwidget = new QTabWidget(this);

    //生成三个页面
    this->mainwindow = new QWidget;
    this->connecter = new QWidget;
    this->user = new QWidget;


//    tabwidget->addTab(mainwindow,"        主页          ");
//    tabwidget->addTab(connecter,"       联系人       ");
//    tabwidget->addTab(user,"        个人        ");

//    tabwidget->resize(screenW,screenH-90);
//    tabwidget->move(0,0);
//    tabwidget->setTabPosition(QTabWidget::South);
//    tabwidget->show();

    QList<QString> list;
    list << QString(":/images/11")
         << QString(":/images/12")
         << QString(":/images/13");

    picture = new GCarouselFigureWidget(screenW*3/4,screenH*1.25/5,3,list);
    picture->setParent(mainwindow);
    picture->move(screenW/8,screenH/7);
    picture->setAutoPlay(true,5000);

    picture->show();

    this->mainwindowUI(screenW,screenH,this->mainwindow);
    this->connecterUI(screenW,screenH,this->connecter);
    this->userUI(screenW,screenH,this->user);

    //主页下的按钮

}

void MainWindow::nuller(){
    QMessageBox* Msg = new QMessageBox;
    Msg->setText("该功能暂未开放");
    Msg->setStyleSheet("QLabel{font: 18pt;color: rgb(0, 0, 127);border: 2px solid green;border-radius: 4px;padding: 2px;background-image: url(images/background.png);}");
    Msg->exec();
}

void MainWindow::timerUI(){
    if(pinfo->findedSet == true){
        if(timeSum != 0){
            if(timeslot->isActive()){
                timeslot->stop();
            }

            qDebug() << "777777777777777";
            this->timer = new QWidget;
            timeslot = new QTimer(timer);
            timer->setObjectName("timer");
            timer->setStyleSheet("QWidget#timer{border-image:url(:/images/mainwindowbg);}");

            leave = new QPushButton(timer);
            back = new QPushButton(timer);
            back->resize(W/5,H/20);
            back->move(W/5,H*3/4);
            back->setText("回到座位");
            leave->resize(W/5,H/20);
            leave->move(W*3/5,H*3/4);
            leave->setText("离开座位");

            time = new QLabel[8];
            for (int i = 0;i < 8 ;i++ ) {
                time[i].setParent(timer);
                time[i].resize(W/10,H/10);
                time[i].move(W*(i+1)/10,H/5);
                time[i].setObjectName("time" + QString::number(i));
                time[i].show();
            }
            time[2].resize(W/20,H/20);
            time[2].move(W*3.5/10,H*2.25/10);
            time[5].resize(W/20,H/20);
            time[5].move(W*6.5/10,H*2.25/10);
            int h = timeSum/3600;
            int m = (timeSum%3600)/60;
            int s = (timeSum%60);
            time[0].setStyleSheet("QLabel#time0{border-image:url(:/images/"+QString::number(h/10) +"a);}");
            time[1].setStyleSheet("QLabel#time1{border-image:url(:/images/"+QString::number(h%10) +"a);}");
            time[2].setStyleSheet("QLabel#time2{border-image:url(:/images/冒号);}");
            time[3].setStyleSheet("QLabel#time3{border-image:url(:/images/"+QString::number(m/10) +"a);}");
            time[4].setStyleSheet("QLabel#time4{border-image:url(:/images/"+QString::number(m%10) +"a);}");
            time[5].setStyleSheet("QLabel#time5{border-image:url(:/images/冒号);}");
            time[6].setStyleSheet("QLabel#time6{border-image:url(:/images/"+QString::number(s/10) +"a);}");
            time[7].setStyleSheet("QLabel#time7{border-image:url(:/images/"+QString::number(s%10) +"a);}");
            timeslot->start(1000);
            timer->show();
        }else{
            qDebug() << "6666666666666";
            this->timer = new QWidget;
            timeslot = new QTimer(timer);
            timer->setObjectName("timer");
            timer->setStyleSheet("QWidget#timer{border-image:url(:/images/mainwindowbg);}");

            leave = new QPushButton(timer);
            back = new QPushButton(timer);
            back->resize(W/5,H/20);
            back->move(W/5,H*3/4);
            back->setText("回到座位");
            leave->resize(W/5,H/20);
            leave->move(W*3/5,H*3/4);
            leave->setText("离开座位");

            time = new QLabel[8];
            for (int i = 0;i < 8 ;i++ ) {
                time[i].setParent(timer);
                time[i].resize(W/10,H/10);
                time[i].move(W*(i+1)/10,H/5);
                time[i].setObjectName("time" + QString::number(i));
                time[i].show();
            }
            time[2].resize(W/20,H/20);
            time[2].move(W*3.5/10,H*2.25/10);
            time[5].resize(W/20,H/20);
            time[5].move(W*6.5/10,H*2.25/10);
            time[0].setStyleSheet("QLabel#time0{border-image:url(:/images/0a);}");
            time[1].setStyleSheet("QLabel#time1{border-image:url(:/images/1a);}");
            time[2].setStyleSheet("QLabel#time2{border-image:url(:/images/冒号);}");
            time[3].setStyleSheet("QLabel#time3{border-image:url(:/images/0a);}");
            time[4].setStyleSheet("QLabel#time4{border-image:url(:/images/0a);}");
            time[5].setStyleSheet("QLabel#time5{border-image:url(:/images/冒号);}");
            time[6].setStyleSheet("QLabel#time6{border-image:url(:/images/0a);}");
            time[7].setStyleSheet("QLabel#time7{border-image:url(:/images/0a);}");


            timer->show();
        }



        connect(leave,&QPushButton::clicked,this,&MainWindow::timeSlot);
        connect(timeslot,&QTimer::timeout,this,&MainWindow::timeA);
        connect(back,&QPushButton::clicked,this,&MainWindow::timeout);

        qDebug() << "99999999999999999999";
    }else{
        QMessageBox* Msg = new QMessageBox;
        Msg->setText("您没有座位哦，不能暂时离开");
        Msg->exec();
    }
}

void MainWindow::timeout(){

    timesum = 0;
    timeSum = 0;
    time[0].setStyleSheet("QLabel#time0{border-image:url(:/images/0a);}");
    time[1].setStyleSheet("QLabel#time1{border-image:url(:/images/1a);}");
    time[2].setStyleSheet("QLabel#time2{border-image:url(:/images/冒号);}");
    time[3].setStyleSheet("QLabel#time3{border-image:url(:/images/0a);}");
    time[4].setStyleSheet("QLabel#time4{border-image:url(:/images/0a);}");
    time[5].setStyleSheet("QLabel#time5{border-image:url(:/images/冒号);}");
    time[6].setStyleSheet("QLabel#time6{border-image:url(:/images/0a);}");
    time[7].setStyleSheet("QLabel#time7{border-image:url(:/images/0a);}");
    timeslot->stop();
    qDebug() << timeslot->isActive();
    qDebug() << "   666 ";

}


void MainWindow::timeSlot(){
    if(this->pinfo->findedSet == true){
        qDebug() << "111";
        QTime current_time =QTime::currentTime();
        int hour = current_time.hour();//当前的小时
        int minute = current_time.minute();//当前的分
        int second = current_time.second();//当前的秒
        if(timesum == 0){
            timesum = hour*3600+ minute*60 + second + 5;
            timeSum = 5;
        }else{
            timeSum = timesum - (hour*3600+ minute*60 + second);
        }

        timeslot->start(1000);
    }else{
        QMessageBox* Msg = new QMessageBox;
        Msg->setText("您的座位已经被退掉，请勿再次离开");
        Msg->exec();
    }
}


void MainWindow::timeA(){
    if(timeSum == 0){
        timeslot->stop();
        QMessageBox* Msg = new QMessageBox;
        Msg->setText("已经到时间了，您还未回到座位，您的座位已经自动退掉");
        Msg->exec();
        timesum = 0;
        timeSum = 0;
        time[0].setStyleSheet("QLabel#time0{border-image:url(:/images/0a);}");
        time[1].setStyleSheet("QLabel#time1{border-image:url(:/images/1a);}");
        time[2].setStyleSheet("QLabel#time2{border-image:url(:/images/冒号);}");
        time[3].setStyleSheet("QLabel#time3{border-image:url(:/images/0a);}");
        time[4].setStyleSheet("QLabel#time4{border-image:url(:/images/0a);}");
        time[5].setStyleSheet("QLabel#time5{border-image:url(:/images/冒号);}");
        time[6].setStyleSheet("QLabel#time6{border-image:url(:/images/0a);}");
        time[7].setStyleSheet("QLabel#time7{border-image:url(:/images/0a);}");
        this->pinfo->takeset->num++;
        this->self->setnumChange();
        this->pinfo->findedSet = false;
        this->userInfor1->setText("在线\n无座");
        userInfor1->move(W*2/9,H*5/20-50);
        return;
    }
    int h = timeSum/3600;
    int m = (timeSum%3600)/60;
    int s = (timeSum%60);
    timeSum--;

    time[0].setStyleSheet("QLabel#time0{border-image:url(:/images/"+QString::number(h/10) +"a);}");
    time[1].setStyleSheet("QLabel#time1{border-image:url(:/images/"+QString::number(h%10) +"a);}");
    time[2].setStyleSheet("QLabel#time2{border-image:url(:/images/冒号);}");
    time[3].setStyleSheet("QLabel#time3{border-image:url(:/images/"+QString::number(m/10) +"a);}");
    time[4].setStyleSheet("QLabel#time4{border-image:url(:/images/"+QString::number(m%10) +"a);}");
    time[5].setStyleSheet("QLabel#time5{border-image:url(:/images/冒号);}");
    time[6].setStyleSheet("QLabel#time6{border-image:url(:/images/"+QString::number(s/10) +"a);}");
    time[7].setStyleSheet("QLabel#time7{border-image:url(:/images/"+QString::number(s%10) +"a);}");

    qDebug() << "1\n";

}


void MainWindow::mainwindowUI(const int screenW,const int screenH,QWidget* mainwindow){
//    //标签，先尝试一下
//    QLabel* main = new QLabel(mainwindow);
//    main->setText("这是主页面");
//    main->move(screenW/3,screenH/2);
//    main->resize(screenW/3,screenH/10);
    //主页面设置一个图片

//    QImage img(":/images/mainwindow");
//    img = img.scaled(screenW*3/4,screenH/5);//图片缩放
//    QLabel* underBGI = new QLabel(mainwindow);
//    underBGI->setPixmap(QPixmap::fromImage(img));
//    underBGI->resize(screenW*3/4,screenH/5);
//    underBGI->move(screenW/8,screenH/10);


    mainwindow->resize(screenW,screenH*27/30);
    mainwindow->setObjectName("mainwindow");
    mainwindow->setStyleSheet("QWidget#mainwindow{border-image:url(:/images/mainwindowbg);}");


    //四个按钮
    findSet        = new QPushButton(mainwindow);
    helpFindSet    = new QPushButton(mainwindow);
    backSet        = new QPushButton(mainwindow);
    others         = new QPushButton(mainwindow);
    qiandao        = new QPushButton(mainwindow);
    //设置按钮大小
    findSet->resize(screenW*7/24,screenH/15);
    helpFindSet->resize(screenW*7/24,screenH/15);
    backSet->resize(screenW*7/24,screenH/15);
    others->resize(screenW*7/24,screenH*0.75/15);
    qiandao->resize(screenW*7/24,screenH/15);
    //设置按钮位置
    findSet->move(screenW*4/24,screenH*2.5/5);
    helpFindSet->move(screenW*13/24,screenH*2.5/5);
    backSet->move(screenW*4/24,screenH*3/5);
    others->move(screenW*13/24,screenH*3/5);
    qiandao->move(screenW*17/48,screenH*3.5/5);


    camera = new Widget;
    camera->mainwindow = this->mainwindow;



    qiandao->setStyleSheet("border-image:url(:/images/签到)");
    qiandao->setFlat(true);
    //设置按钮背景

//    QImage findSetimg(":/images/寻找位置");
//    findSetimg = findSetimg.scaled(screenW*7/24,screenH/10);//图片缩放
//    QIcon findSetIcon(QPixmap::fromImage(findSetimg));
//    findSet->setIcon(findSetIcon);
//    findSet->setIconSize(QSize(screenW*7/24,screenH/10));
    findSet->setStyleSheet("border-image:url(:/images/寻找位置)");
    findSet->setFlat(true);
//    QImage helpFindSetimg(":/images/帮助寻找");
//    helpFindSetimg = helpFindSetimg.scaled(screenW*7/24,screenH/10);//图片缩放
//    QIcon helpFindSetIcon(QPixmap::fromImage(helpFindSetimg));
//    helpFindSet->setIcon(helpFindSetIcon);
//    helpFindSet->setIconSize(QSize(screenW*7/24,screenH/10));
    helpFindSet->setStyleSheet("border-image:url(:/images/帮助寻找)");
    helpFindSet->setFlat(true);
//    QImage backSetimg(":/images/退掉座位");
//    backSetimg = backSetimg.scaled(screenW*7/24,screenH/10);//图片缩放
//    QIcon backSetIcon(QPixmap::fromImage(backSetimg));
//    backSet->setIcon(backSetIcon);
//    backSet->setIconSize(QSize(screenW*7/24,screenH/10));
    backSet->setStyleSheet("border-image:url(:/images/退掉座位)");
    backSet->setFlat(true);
//    QImage othersimg(":/images/其他设置");
//    othersimg = othersimg.scaled(screenW*7/24,screenH/10);//图片缩放
//    QIcon othersIcon(QPixmap::fromImage(othersimg));
//    others->setIcon(othersIcon);
//    others->setIconSize(QSize(screenW*7/24,screenH/10));
    others->setStyleSheet("border-image:url(:/images/离开座位)");
    others->setFlat(true);

    //之后修改为适应性的 《------------》
//    mainwindoInfor = new QLabel(mainwindow);
//    //QFont* userInformation = new QFont;
//    mainwindoInfor->setScaledContents(true);
//    mainwindoInfor->resize(screenW*2/3,screenH/10);
//    mainwindoInfor->move(screenW/6,screenH*4/5);
//    mainwindoInfor->setText("\t叶青鑫  在线  无座");



    this->mainwinMain = new QPushButton(mainwindow);
    this->connectMain = new QPushButton(mainwindow);
    this->_userMain   = new QPushButton(mainwindow);
    this->mainwinMain->resize(screenW/3,screenH*3/30);
    this->connectMain->resize(screenW/3,screenH*3/30);
    this->_userMain->resize(screenW/3,screenH*3/30);
    this->mainwinMain->move(0,screenH*9/10);
    this->connectMain->move(screenW/3,screenH*9/10);
    this->_userMain->move(screenW*2/3,screenH*9/10);

    this->mainwinMain->setFlat(true);
    this->connectMain->setFlat(true);
    this->_userMain->setFlat(true);
    QImage mainwinMainimg(":/images/主页图标");
    mainwinMainimg = mainwinMainimg.scaled(screenW/3,screenH*3/30);//图片缩放
    QIcon mainwinMainIcon(QPixmap::fromImage(mainwinMainimg));
    this->mainwinMain->setIcon(mainwinMainIcon);
    this->mainwinMain->setIconSize(QSize(screenW/3,screenH*3/30));
    QImage connectMainimg(":/images/好友图标");
    connectMainimg = connectMainimg.scaled(screenW/3,screenH*3/30);//图片缩放
    QIcon connectMainIcon(QPixmap::fromImage(connectMainimg));
    this->connectMain->setIcon(connectMainIcon);
    this->connectMain->setIconSize(QSize(screenW/3,screenH*3/30));
    QImage _userMainimg(":/images/我的");
    _userMainimg = _userMainimg.scaled(screenW/3,screenH*3/30);//图片缩放
    QIcon _userMainIcon(QPixmap::fromImage(_userMainimg));
    this->_userMain->setIcon(_userMainIcon);
    this->_userMain->setIconSize(QSize(screenW/3,screenH*3/30));

}
void MainWindow::connecterUI(const int screenW,const int screenH,QWidget* connecter){
//    QLabel* connect = new QLabel(connecter);
//    connect->setText("这是联系人页面");
//    connect->move(screenW/3,screenH/2);
//    connect->resize(screenW/3,screenH/10);
//      mainwindow->setStyleSheet("QWidget#mainwindow{border-image:url(:/images/mainwindowbg);}");
    connecter->setObjectName("connecter");
    connecter->setStyleSheet("QWidget#connecter{border-image:url(:/images/connecter);}");


    //添加好友等按钮
    this->addFriend = new QPushButton(connecter);
    this->newFriend = new QPushButton(connecter);
    //this->official  = new QPushButton(connecter);

    addFriend->resize(screenW/2,screenH/10);
    newFriend->resize(screenW/2,screenH/10);
    //official->resize(screenW/3,screenH/10);

    addFriend->move(0,0);
    newFriend->move(screenW/2,0);
    //official->move(screenW*2/3,screenH/20);
    //
    addFriend->setStyleSheet("border-image:url(:/images/好友添加好友)");
    newFriend->setStyleSheet("border-image:url(:/images/好友新朋友)");
    addFriend->setFlat(true);
    newFriend->setFlat(true);
//    QImage addFriendimg;
//    addFriendimg.load(":/images/好友添加好友");
//    addFriendimg =setObjectName addFriendimg.scaled(screenW/2,screenH/10);//图片缩放
//    QIcon addFriendIcon(QPixmap::fromImage(addFriendimg));
//    addFriend->setIcon(addFriendIcon);
//    addFriend->setIconSize(QSize(screenW/2,screenH/10));
//    QImage newFriendimg(":/images/好友新朋友");
//    newFriendimg = newFriendimg.scaled(screenW/2,screenH/10);//图片缩放
//    QIcon newFriendIcon(QPixmap::fromImage(newFriendimg));
//    newFriend->setIcon(newFriendIcon);
//    newFriend->setIconSize(QSize(screenW/2,screenH/10));
//    QImage officialimg(":/images/公众号");
//    officialimg = officialimg.scaled(screenW/3,screenH/10);//图片缩放
//    QIcon officialIcon(QPixmap::fromImage(officialimg));
//    official->setIcon(officialIcon);
//    official->setIconSize(QSize(screenW/3,screenH/10));

    this->friendList = new QListWidget(connecter);
    this->friendList->resize(screenW,screenH*4/5);
    this->friendList->move(50,screenH*2/20);

    QListWidgetItem* test[10];
    for (int i = 0;i < 10 ;i++ ) {
        test[i] = new QListWidgetItem;
        test[i]->setSizeHint(QSize(150,100));
        QFont font;
        font.setPointSize(20);
        test[i]->setFont(font);
        friendList->addItem(test[i]);
    }

    test[0]->setText("黄英亮\t在线");
    test[1]->setText("鄢歆璐\t在线");
    test[2]->setText("汤宇航\t在线");
    test[3]->setText("温尧智\t在线");
    test[4]->setText("梅阳鸿\t在线");
    test[5]->setText("赵洪民\t未在线");
    test[6]->setText("雷佳臻\t未在线");
    test[7]->setText("汤宇航\t在线");
    test[8]->setText("温尧智\t在线");
    test[9]->setText("梅阳鸿\t在线");

    //this->myfriends = new friends[10];
//        friendList->addItem("赵洪民\t未在线");
//        friendList->addItem("雷佳臻\t未在线");
//    }
    //之后修改为适应性的 《------------》
//    connecterInfor = new QLabel(connecter);
//    //QFont* userInformation = new QFont;

//    connecterInfor->resize(screenW,screenH/20);
//    connecterInfor->move(0,0);
//    connecterInfor->setText("\t叶青鑫 在线 无座");


    this->mainwinCon = new QPushButton(connecter);
    this->connectCon = new QPushButton(connecter);
    this->_userCon  = new QPushButton(connecter);
    this->mainwinCon->resize(screenW/3,screenH*3/30);
    this->connectCon->resize(screenW/3,screenH*3/30);
    this->_userCon->resize(screenW/3,screenH*3/30);
    this->mainwinCon->move(0,screenH*9/10);
    this->connectCon->move(screenW/3,screenH*9/10);
    this->_userCon->move(screenW*2/3,screenH*9/10);

    this->mainwinCon->setFlat(true);
    this->connectCon->setFlat(true);
    this->_userCon->setFlat(true);

    QImage mainwinConimg(":/images/主页图标");
    mainwinConimg = mainwinConimg.scaled(screenW/3,screenH*3/30);//图片缩放
    QIcon mainwinConIcon(QPixmap::fromImage(mainwinConimg));
    this->mainwinCon->setIcon(mainwinConIcon);
    this->mainwinCon->setIconSize(QSize(screenW/3,screenH*3/30));
    QImage connectConimg(":/images/好友图标");
    connectConimg = connectConimg.scaled(screenW/3,screenH*3/30);//图片缩放
    QIcon connectConIcon(QPixmap::fromImage(connectConimg));
    this->connectCon->setIcon(connectConIcon);
    this->connectCon->setIconSize(QSize(screenW/3,screenH*3/30));
    QImage _userConimg(":/images/我的");
    _userConimg = _userConimg.scaled(screenW/3,screenH*3/30);//图片缩放
    QIcon _userConIcon(QPixmap::fromImage(_userConimg));
    this->_userCon->setIcon(_userConIcon);
    this->_userCon->setIconSize(QSize(screenW/3,screenH*3/30));




    //安卓滑动代码
    friendList->setStyleSheet("QListView { background-color: rgba(0, 0, 0, 0); border:0px;}");
    friendList->setSpacing(0);
    friendList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    friendList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    friendList->setContentsMargins(0, 0, 0, 0);
    friendList->setVerticalScrollBar(NULL);
    friendList->setHorizontalScrollBar(NULL);
    friendList->setSelectionMode(QAbstractItemView::NoSelection);// SingleSelection);
    friendList->setDragEnabled(false);
    friendList->setDragDropMode(QAbstractItemView::NoDragDrop);
    friendList->setMovement(QListView::Static);
    friendList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //支持手势滑动,关键代码
    QScroller::grabGesture(friendList, QScroller::TouchGesture);
}
void MainWindow::userUI(const int screenW,const int screenH,QWidget* user){
//    QLabel* userL = new QLabel(user);
//    userL->setText("这是个人页面");
//    userL->move(screenW/3,screenH/2);
//    userL->resize(screenW/3,screenH/10);
    user->setObjectName("user");
    user->setStyleSheet("QWidget#user{border-image:url(:/images/user)}");

    backword = new QWidget;
    beiwanglu = new QWidget;

    backword->setStyleSheet("border-image:url(:/images/user)");
    beiwanglu->setStyleSheet("border-image:url(:/images/user)");
    beiwangl = new QPushButton(beiwanglu);
    backw = new QPushButton(backword);

    beiwangl->resize(W*1.5/5,H/10);
    backw->resize(W*1.5/5,H/10);
    beiwangl->move(0,0);
    backw->move(0,0);
    beiwangl->setObjectName("beiwangl");
    backw->setObjectName("backw");
    //beiwangl->setStyleSheet("QPushButton#beiwangl{border-image:url(:/images/备忘录顶部返回)}");
    beiwangl->setFlat(true);
    backw->setStyleSheet("QPushButton#backw{border-image:url(:/images/反馈)}");
    backw->setFlat(true);

    beiwanglutop = new QPushButton(beiwanglu);
    beiwanglutop->resize(W*2/5,H/10);
    beiwanglutop->move(W*1.5/5,0);
    beiwanglutop->setObjectName("beiwanglutop");
    beiwanglutop->setStyleSheet("QPushButton#beiwanglutop{border-image:url(:/images/备忘录顶部)}");
    beiwanglutop->setFlat(true);

    beiwanglunote = new QPushButton(beiwanglu);
    beiwanglunote->resize(W*2/5,H/20);
    beiwanglunote->move(0,H/5);
    beiwanglunote->setObjectName("beiwanglutop");
    beiwanglunote->setStyleSheet("QPushButton#beiwanglutop{border-image:url(:/images/备忘录note)}");
    beiwanglunote->setFlat(true);

    beiwangluneirong = new QTextEdit(beiwanglu);
    beiwangluneirong->resize(W,H*2/5);
    beiwangluneirong->move(0,H*2/5);
    beiwangluneirong->setFrameStyle(QFrame::NoFrame);
    beiwangluneirong->setObjectName("beiwangluneirong");
    beiwangluneirong->setStyleSheet("QTextEdit#beiwangluneirong{border-image:url(:/images/备忘录note)}");

    //头像

    this->myselfimg = new QPushButton(user);
    myselfimg->resize(screenW/3,screenH/15);
    myselfimg->move(screenW/9,screenH*3/20);
    myselfimg->setStyleSheet("border-image:url(:/images/我的预约记录)");
    myselfimg->setFlat(true);
//    QImage selfPicture(":/images/selfimg");
//    myselfimg->setPixmap(QPixmap::fromImage(selfPicture));
    //个人信息
    this->myselfInfor = new QPushButton(user);
    myselfInfor->resize(screenW/3,screenH/15);
    myselfInfor->move(screenW*5/9,screenH*3/20);
    myselfInfor->setStyleSheet("border-image:url(:/images/我的违纪警告)");
    myselfInfor->setFlat(true);

    this->Collection = new QPushButton(user);
    Collection->resize(screenW,screenH*2/20);
    Collection->move(0,screenH*7/20);
    //Collection->setText("\t\t\t收藏");
    Collection->setStyleSheet("border-image:url(:/images/我的备忘录)");
    Collection->setFlat(true);


    this->friendcircle = new QPushButton(user);
    friendcircle->resize(screenW,screenH*1.5/20);
    friendcircle->move(0,screenH*9/20);
    friendcircle->setStyleSheet("border-image:url(:/images/我的设置)");
    friendcircle->setFlat(true);


    this->settings = new QPushButton(user);
    settings->resize(screenW,screenH*1/15);
    settings->move(0,screenH*13/20);
    settings->setStyleSheet("border-image:url(:/images/我的反馈)");
    settings->setFlat(true);
//    QImage settingsimg(":/images/反馈");
//    settingsimg = settingsimg.scaled(screenW,screenH/15);//图片缩放
//    QIcon settingsIcon(QPixmap::fromImage(settingsimg));
//    settings->setIcon(settingsIcon);
//    settings->setIconSize(QSize(screenW,screenH/10));
//    settings->setText("\t\t\t设置");
//    settings->setStyleSheet("QPushButton{text-align:left}");

    //之后修改为适应性的 《------------》
    userInfor1 = new QLabel(user);
    userInfor2 = new QLabel(user);
    userInfor3 = new QLabel(user);
    //QFont* userInformation = new QFont;

    userInfor1->resize(screenW*1.75/9,screenH*2/60);
    userInfor1->move(screenW*1.75/9,screenH*5/20-50);
    userInfor2->resize(screenW,screenH*2/20);
    userInfor2->move(screenW*2/9,screenH*5/20+screenH*2/60-50);
    userInfor3->resize(screenW,screenH*2/20);
    userInfor3->move(screenW*2/9,screenH*5/20+screenH*4/60-50);
    userInfor1->setObjectName("userInfor1");
    userInfor2->setObjectName("userInfor2");
    userInfor3->setObjectName("userInfor3");
    userInfor1->setStyleSheet("QLabel#userInfor1{border-image:url(:/images/无座)}");
    userInfor2->hide();
    userInfor3->hide();
//    userInfor1->setStyleSheet("font-size:60px");
//    userInfor1->setText("在线\n无座\n");

    userhhh = new QLabel(user);
    //QFont* userInformation = new QFont;

    userhhh->resize(screenW,screenH*2/20);
    userhhh->move(screenW*6/9,screenH*5/20-100);
    userhhh->setStyleSheet("font-size:60px");
    userhhh->setText("0次");

    this->mainwinUser = new QPushButton(user);
    this->connectUser = new QPushButton(user);
    this->_userUser  = new QPushButton(user);
    this->mainwinUser->resize(screenW/3,screenH*3/30);
    this->connectUser->resize(screenW/3,screenH*3/30);
    this->_userUser->resize(screenW/3,screenH*3/30);
    this->mainwinUser->move(0,screenH*9/10);
    this->connectUser->move(screenW/3,screenH*9/10);
    this->_userUser->move(screenW*2/3,screenH*9/10);

    this->mainwinUser->setFlat(true);
    this->connectUser->setFlat(true);
    this->_userUser->setFlat(true);

    QImage mainwinUserimg(":/images/主页图标");
    mainwinUserimg = mainwinUserimg.scaled(screenW/3,screenH*3/30);//图片缩放
    QIcon mainwinUserIcon(QPixmap::fromImage(mainwinUserimg));
    this->mainwinUser->setIcon(mainwinUserIcon);
    this->mainwinUser->setIconSize(QSize(screenW/3,screenH*3/30));
    QImage connectUserimg(":/images/好友图标");
    connectUserimg = connectUserimg.scaled(screenW/3,screenH*3/30);//图片缩放
    QIcon connectUserIcon(QPixmap::fromImage(connectUserimg));
    this->connectUser->setIcon(connectUserIcon);
    this->connectUser->setIconSize(QSize(screenW/3,screenH*3/30));
    QImage _userUserimg(":/images/我的");
    _userUserimg = _userUserimg.scaled(screenW/3,screenH*3/30);//图片缩放
    QIcon _userUserIcon(QPixmap::fromImage(_userUserimg));
    this->_userUser->setIcon(_userUserIcon);
    this->_userUser->setIconSize(QSize(screenW/3,screenH*3/30));

}

void MainWindow::switchWindowToMain(){
    this->connecter->hide();
    this->user->hide();
    this->mainwindow->show();
    qDebug() << "mainwindow";
}

void MainWindow::switchWindowToConnect(){
    this->user->hide();
    this->mainwindow->hide();
    this->connecter->show();
    qDebug() << "Connecter";
}

void MainWindow::makeset(){

    qDebug() << "hh";
    pinfo = new info;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    this->pinfo->number = new int**[10];
    for(int k = 0;k < 10;k++){
        qDebug() << "===k" + QString::number(k) +"===222===============2";
        this->pinfo->number[k] = new int*[7];
    }
    for(int k = 0;k < 10;k++){
        for(int i = 0;i < 7;i++){
            qDebug() << "===j" + QString::number(i)+ " "+ QString::number(k) +"===222===============2";

            this->pinfo->number[k][i] = new int[7];        }
    }
    for(int k = 0;k < 10;k++){
        for(int i = 0;i < 7;i++){
            for(int j = 0;j < 7;j++){

                this->pinfo->number[k][i][j] = qrand()%5;
                qDebug() << this->pinfo->number[k][i][j] << "\n";
            }
        }
    }
    qDebug() << "======222===============2";
}


void MainWindow::switchWindowToUser(){
    this->mainwindow->hide();
    this->connecter->hide();
    this->user->show();
    qDebug() << "User";
}




void MainWindow::findset(){
    this->self = new setFind(this->W,this->H,this->pinfo,this);
    this->self->show();
}

void MainWindow::backset(){
    if(this->pinfo->findedSet == true){
        QMessageBox* Msg = new QMessageBox;
        Msg->setText("占座不易，您确定要退掉吗？");
        QString tokenSet = this->pinfo->takeset->gettext();
        qDebug() << tokenSet;
        Msg->setInformativeText(tokenSet);
        Msg->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        Msg->setDefaultButton(QMessageBox::Yes);
        if(Msg->exec() == QMessageBox::Yes){
            this->pinfo->takeset->num++;
            this->self->setnumChange();
            this->pinfo->findedSet = false;
            QMessageBox* infor = new QMessageBox;
            infor->setText("您的座位已经退掉了哦！");
            this->userInfor1->setStyleSheet("QLabel#userInfor1{border-image:url(:/images/无座)}");
            userInfor1->move(W*2/9,H*5/20-50);
            //this->mainwindoInfor->setText("\t叶青鑫 在线 无座");
            //this->connecterInfor->setText("\t叶青鑫 在线 无座");
            infor->exec();
        }else{
            QMessageBox* infor = new QMessageBox;
            infor->setText("您的座位依旧保留，请尽快就坐哦");
            infor->exec();
        }
    }else{
        QMessageBox* Msg = new QMessageBox;
//        QPalette palette;
//        palette.setBrush(QPalette::Background,QBrush(QPixmap(":/images/没有座位可以退掉")));
//        Msg->setPalette(palette);
        Msg->setText("您没有座位可以退掉哦");
        Msg->exec();
    }
}

void MainWindow::connectAll(){
    //connect(user_login,&QPushButton::clicked,this,&login::checkpw);
    //connect(mainwinMain,&QPushButton::clicked,this,&MainWindow::switchWindowToMain);
    connect(this->connectMain,&QPushButton::clicked,this,&MainWindow::switchWindowToConnect);
    connect(this->_userMain,&QPushButton::clicked,this,&MainWindow::switchWindowToUser);
    connect(this->mainwinCon,&QPushButton::clicked,this,&MainWindow::switchWindowToMain);
    //connect(connectCon,&QPushButton::clicked,this,&MainWindow::switchWindowToConnect);
    connect(this->_userCon,&QPushButton::clicked,this,&MainWindow::switchWindowToUser);
    connect(this->mainwinUser,&QPushButton::clicked,this,&MainWindow::switchWindowToMain);
    connect(this->connectUser,&QPushButton::clicked,this,&MainWindow::switchWindowToConnect);
    //connect(_userUser,&QPushButton::clicked,this,&MainWindow::switchWindowTouser);

    connect(this->findSet,&QPushButton::clicked,this,&MainWindow::findset);
    connect(this->backSet,&QPushButton::clicked,this,&MainWindow::backset);
    connect(this->helpFindSet,&QPushButton::clicked,this,&MainWindow::nuller);
    connect(this->others,&QPushButton::clicked,this,&MainWindow::timerUI);
    connect(this->qiandao,&QPushButton::clicked,this->camera,&Widget::onCapture);

    connect(this->addFriend,&QPushButton::clicked,this,&MainWindow::nuller);
    connect(this->newFriend,&QPushButton::clicked,this,&MainWindow::nuller);
    //connect(this->official,&QPushButton::clicked,this,&MainWindow::nuller);

    connect(this->myselfInfor,&QPushButton::clicked,this,&MainWindow::nuller);
    connect(this->friendcircle,&QPushButton::clicked,this,&MainWindow::nuller);
    connect(this->settings,&QPushButton::clicked,this,&MainWindow::showfankui);
    connect(this->Collection,&QPushButton::clicked,this,&MainWindow::showbeiwanglu);

    connect(this->beiwangl,&QPushButton::clicked,this,&MainWindow::hidebeiwanglu);
    connect(this->backw,&QPushButton::clicked,this,&MainWindow::hidefankui);
}


void MainWindow::showbeiwanglu(){
    if(!beiwanglu->isActiveWindow()){

        beiwanglu = new QWidget;
        beiwanglu->setObjectName("beiwnaglu");
        beiwanglu->setStyleSheet("QWidget#beiwnaglu{border-image:url(:/images/user)}");
        beiwangl = new QPushButton(beiwanglu);


        beiwangl->resize(W*1.5/5,H/10);

        beiwangl->move(0,0);

        beiwangl->setObjectName("beiwangl");
        beiwanglutop = new QPushButton(beiwanglu);
        beiwanglutop->resize(W*2/5,H/10);
        beiwanglutop->move(W*1.5/5,0);
        beiwanglutop->setObjectName("beiwanglutop");
        beiwanglutop->setStyleSheet("QPushButton#beiwanglutop{border-image:url(:/images/备忘录顶部)}");
        beiwanglutop->setFlat(true);
        beiwangl->setStyleSheet("QPushButton#beiwangl{border-image:url(:/images/备忘录顶部返回)}");
        beiwangl->setFlat(true);
        beiwanglunote = new QPushButton(beiwanglu);
        beiwanglunote->resize(W*2/5,H/20);
        beiwanglunote->move(0,H/5);
        beiwanglunote->setObjectName("beiwanglutop");
        beiwanglunote->setStyleSheet("QPushButton#beiwanglutop{border-image:url(:/images/备忘录note)}");
        beiwanglunote->setFlat(true);
        beiwangluneirong = new QTextEdit(beiwanglu);
        beiwangluneirong->resize(W*4/5,H*1.5/5);
        beiwangluneirong->move(W/10,H*1.5/5);
        beiwangluneirong->setObjectName("beiwangluneirong");
        beiwangluneirong->setStyleSheet("QTextEdit#beiwangluneirong{background-color:transparent;}");
        connect(this->beiwangl,&QPushButton::clicked,this,&MainWindow::hidebeiwanglu);

    }
    beiwanglu->show();
}
void MainWindow::hidebeiwanglu(){
    beiwanglu->hide();
    user->show();

}
void MainWindow::showfankui(){
    if(!backword->isActiveWindow()){
        backword = new QWidget;
        backword->setObjectName("backword");
        backword->setStyleSheet("QWidget#backword{border-image:url(:/images/user)}");
        backw = new QPushButton(backword);
        backw->resize(W*1.5/5,H/10);
        backw->move(0,0);
        backw->setObjectName("backw");
        backw->setStyleSheet("QPushButton#backw{border-image:url(:/images/备忘录顶部返回)}");
        backw->setFlat(true);
        backtop = new QPushButton(backword);
        backtop->resize(W*2/5,H/10);
        backtop->move(W*1.5/5,0);
        backtop->setObjectName("backtop");
        backtop->setStyleSheet("QPushButton#backtop{border-image:url(:/images/反馈顶部)}");
        backtop->setFlat(true);
        backneirong = new QPushButton(backword);
        backneirong->resize(W*2/5,H/20);
        backneirong->move(0,H/5);
        backneirong->setObjectName("backneirong");
        backneirong->setStyleSheet("QPushButton#backneirong{border-image:url(:/images/反馈反馈内容)}");
        backneirong->setFlat(true);
        phonenumber = new QPushButton(backword);
        phonenumber->resize(W*2/5,H*1.5/20);
        phonenumber->move(0,H*8.5/20);
        phonenumber->setObjectName("phonenumber");
        phonenumber->setStyleSheet("QPushButton#phonenumber{border-image:url(:/images/反馈联系方式)}");
        phonenumber->setFlat(true);
        submit = new QPushButton(backword);
        submit->resize(W*4/5,H*1.75/20);
        submit->move(W*0.5/5,H*16/20);
        submit->setObjectName("submit");
        submit->setStyleSheet("QPushButton#submit{border-image:url(:/images/反馈提交)}");
        submit->setFlat(true);
        backtext = new QTextEdit(backword);
        backtext->resize(W*4/5,H*0.75/5);
        backtext->move(W/10,H*1.25/5);
        backtext->setObjectName("backtext");
        backtext->setStyleSheet("QTextEdit#backtext{background-color:transparent;}");
        phone = new QLineEdit(backword);
        phone->resize(W*3/5,H/20);
        phone->move(W*2/5,H*8.75/20);
        phone->setObjectName("phone");
        phone->setStyleSheet("QLineEdit#phone{background-color:transparent;}");

        connect(this->backw,&QPushButton::clicked,this,&MainWindow::hidefankui);
        connect(this->submit,&QPushButton::clicked,this,&MainWindow::tijiao);
    }
    backword->show();
}
void MainWindow::hidefankui(){

    backword->hide();
    user->show();
}

void MainWindow::tijiao(){
    QMessageBox* Msg = new QMessageBox;
    Msg->setText("您已经提交成功，感谢您的反馈");
    Msg->exec();
    backword->hide();
    user->show();
}

MainWindow::~MainWindow()
{
    delete mainwindow;
    delete connecter;
    delete user;
}

