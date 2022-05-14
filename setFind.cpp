#include "setFind.h"
#include "mainwindow.h"

setFind::setFind(const int W,const int H,info* acceptinfo,MainWindow* window){
    this->myinfo = acceptinfo;
    this->screenW = W;
    this->screenH = H;
    this->mainwindow = window;
//    qDebug() << this->myinfo->number << "\n";
//    qDebug() << num << "\n";

    this->setupUI();

    this->connectAll();

    this->initSet();
}

void setFind::setupUI(){

    this->setwindow = new QWidget;
    this->setwindow->setObjectName("setwindow");
    this->setwindow->setStyleSheet("QWidget#setwindow{border-image:url(:/images/login)}");
    this->floor  = new QComboBox(this->setwindow);
    this->floor->resize(this->screenW*4/5,this->screenH/30);
    this->floor->move(this->screenW/10,this->screenH/20);
    this->floor->lineEdit();
    this->floor->addItem("第一楼");
    this->floor->addItem("第二楼");
    this->floor->addItem("第三楼");
    this->floor->addItem("第四楼");
    this->floor->addItem("第五楼");
    this->floor->addItem("第六楼");
    this->floor->addItem("第七楼");
    this->floor->addItem("第八楼");

    this->BGP = new QPushButton(setwindow);
    this->AP = new QPushButton(setwindow);
    this->BP = new QPushButton(setwindow);
    this->CP = new QPushButton(setwindow);


    this->BGP->resize(screenW,screenH*9/30);
    this->BGP->move(0,screenH*9/30);
    this->BGP->setObjectName("BGP");
    this->BGP->setFlat(true);
    this->BGP->setStyleSheet("QPushButton#BGP{border-image:url(:/images/图书馆外框)}");

    this->AP->resize(screenW*7.5/8,screenH*3.5/30);
    this->AP->move(screenW*7/208,screenH*9.5/30);
    this->AP->setObjectName("AP");
    this->AP->setFlat(true);
    this->AP->setStyleSheet("QPushButton#AP{border-image:url(:/images/A)}");
    this->CP->resize(screenW*0.7211,screenH*1.5/30);
    this->CP->move(screenW*2/8,screenH*13.5/30);
    this->CP->setObjectName("CP");
    this->CP->setFlat(true);
    this->CP->setStyleSheet("QPushButton#CP{border-image:url(:/images/C)}");
    this->BP->resize(screenW*7.5/8,screenH*2/30);
    this->BP->move(screenW*7/208,screenH*15.5/30);
    this->BP->setObjectName("BP");
    this->BP->setFlat(true);
    this->BP->setStyleSheet("QPushButton#BP{border-image:url(:/images/B)}");


//    this->test = new QLabel(this->setwindow);
//    this->test->resize(200,50);
//    this->test->move(screenW/3,screenH/2);
//    this->test->setText("这是一楼");


    //this->makeAll();
    this->image = new QImage[5];
    this->icon  = new QIcon[5];
    this->image[0] = QImage(":images/set0");
    this->image[1] = QImage(":images/set1");
    this->image[2] = QImage(":images/set2");
    this->image[3] = QImage(":images/set3");
    this->image[4] = QImage(":images/set4");
    this->image[0] = this->image[0].scaled(screenW/6,screenH/30);
    this->image[1] = this->image[1].scaled(screenW/6,screenH/30);
    this->image[2] = this->image[2].scaled(screenW/6,screenH/30);
    this->image[3] = this->image[3].scaled(screenW/6,screenH/30);
    this->image[4] = this->image[4].scaled(screenW/6,screenH/30);
    this->icon[0] = QIcon(QPixmap::fromImage(this->image[0]));
    this->icon[1] = QIcon(QPixmap::fromImage(this->image[1]));
    this->icon[2] = QIcon(QPixmap::fromImage(this->image[2]));
    this->icon[3] = QIcon(QPixmap::fromImage(this->image[3]));
    this->icon[4] = QIcon(QPixmap::fromImage(this->image[4]));
    this->makeset();
}

//void setFind::makeAll(){
//
//

void setFind::makeset(){
    this->scatter = new set*[7];
    for(int i = 0;i < 7;i++){
        scatter[i] = new set[7];
    }
}

void setFind::planset(){
    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 7;j++){
            switch (this->nowNumber[i][j]) {
            case 0:
                this->scatter[i][j].setIcon(this->icon[0]);
                this->scatter[i][j].setIconSize(QSize(screenW/6,screenH/30));
                break;
            case 1:
                this->scatter[i][j].setIcon(this->icon[1]);
                this->scatter[i][j].setIconSize(QSize(screenW/6,screenH/30));
                break;
            case 2:
                this->scatter[i][j].setIcon(this->icon[2]);
                this->scatter[i][j].setIconSize(QSize(screenW/6,screenH/30));
                break;
            case 3:
                this->scatter[i][j].setIcon(this->icon[3]);
                this->scatter[i][j].setIconSize(QSize(screenW/6,screenH/30));
                break;
            case 4:
                this->scatter[i][j].setIcon(this->icon[4]);
                this->scatter[i][j].setIconSize(QSize(screenW/6,screenH/30));
                break;

        }
    }
}
}
void setFind::changeSet(int x,const QString& text){
    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 7;j++){
            this->nowNumber[i][j] = this->myinfo->number[x][i][j];
            this->scatter[i][j].area = text;
            qDebug() << this->scatter[i][j].area;
            switch (this->myinfo->number[x][i][j]) {
            case 0:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set0)}");
                break;
            case 1:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set1)}");
                break;
            case 2:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set2)}");
                break;
            case 3:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set3)}");
                break;
            case 4:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set4)}");
                break;
            default:
                break;
            }
            //this->mainwindow->pinfo->takeset->area = text;
            //qDebug() << this->mainwindow->pinfo->takeset->area = text;
        }
    }
}
void setFind::comboboxChanged(const QString& text){
    qDebug() << "0|||||||||||||" ;
    if(text == "第一楼"){
        qDebug() << "1|||||||||||||" ;
        this->changeSet(0,"第一楼");
        this->now = 0;
    }else if(text == "第二楼"){
        qDebug() << "2|||||||||||||" ;
        this->changeSet(1,"第二楼");
        this->now = 1;
    }else if(text == "第三楼"){
        qDebug() << "3|||||||||||||" ;
        this->changeSet(2,"第三楼");
        this->now = 2;
    }else if(text == "第四楼"){
        qDebug() << "4|||||||||||||" ;
        this->changeSet(3,"第四楼");
        this->now = 3;
    }else if(text == "第五楼"){
        qDebug() << "5|||||||||||||" ;
        this->changeSet(4,"第五楼");
        this->now = 4;
    }else if(text == "第六楼"){
        qDebug() << "6|||||||||||||" ;
        this->changeSet(5,"第六楼");
        this->now = 5;
    }else if(text == "第七楼"){
        qDebug() << "7|||||||||||||" ;
        this->changeSet(6,"第七楼");
        this->now = 6;
    }else if(text == "第八楼"){
        qDebug() << "8|||||||||||||" ;
        this->changeSet(7,"第八楼");
        this->now = 7;
    }
    this->planset();
}

void setFind::setnumChange(){
    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 7;j++){
            this->nowNumber[i][j] = this->scatter[i][j].num;
            this->myinfo->number[now][i][j] = this->scatter[i][j].num;
            qDebug() <<this->scatter[i][j].num;
        }
        qDebug() << "\n";
    }
}

void setFind::checkset(){
    set* val = qobject_cast<set*>(sender());
    QMessageBox* Msg = new QMessageBox;
    QString midinfo = QString::number(val->num);
    Msg->setText("您确定要在这里坐下吗？");
    Msg->setInformativeText("选择之后，短时间之内不可以更改哦");
    Msg->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    Msg->setDefaultButton(QMessageBox::Yes);
    qDebug() << "\n=====1111111111111==================\n";
    if(Msg->exec()==QMessageBox::Yes){
        qDebug() << "\n======22222222222=================\n";
        if(this->myinfo->findedSet == true){
            qDebug() << "\n====33333333333====================\n";
            QMessageBox* Msg = new QMessageBox;
            Msg->setText("您已经占过座位了哦");
            Msg->exec();
            delete Msg;
            return;
        }
        if(val->num == 0){
            qDebug() << "\n========444444444444==================\n";
            QMessageBox* warning = new QMessageBox;
            warning->setText("这个地方没有位置了哦,请重新选择");
            warning->exec();
            delete Msg;
            delete warning;
            return;
        }
        qDebug() << "\n=======555555555555=============\n";
        val->num--;
        qDebug() << "\n=======66666666666666=================\n";
        QString text = val->gettext();
        QStringList t;
        t = text.split(',');

        qDebug() << t[0] << "  " << t[1].toInt() << t[2].toInt();
        this->mainwindow->userInfor1->setStyleSheet("QLabel#userInfor1{border-image:url(:/images/" + t[0] + ")}");
        this->mainwindow->userInfor2->setStyleSheet("QLabel#userInfor2{border-image:url(:/images/" + t[1] + ")}");
        this->mainwindow->userInfor3->setStyleSheet("QLabel#userInfor3{border-image:url(:/images/" + t[2] + ")}");
        //this->mainwindow->mainwindoInfor->setText(val->getmaintext());
        //this->mainwindow->connecterInfor->setText(val->getmaintext());
        qDebug() << "\n========7777777777777==============\n";
        this->myinfo->findedSet = true;
        this->myinfo->takeset = val;
        qDebug() << val->area;
        this->setnumChange();
        this->planset();

    }else{
    }
    delete  Msg;

}

void setFind::connectAll(){
    connect(floor,&QComboBox::currentTextChanged,this,&setFind::comboboxChanged);
    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 7;j++){
            connect(&this->scatter[i][j],&set::clicked,this,&setFind::checkset);
        }
    }
    connect(this->AP,&QPushButton::clicked,this,&setFind::showA);
    connect(this->BP,&QPushButton::clicked,this,&setFind::showB);
    connect(this->CP,&QPushButton::clicked,this,&setFind::showC);
}

void setFind::show(){
    this->setwindow->show();
}




void setFind::showA(){


    QLabel* shujia = new QLabel[9];
    for(int i = 0;i < 9;i++){
        shujia[i].setParent(AW);
        shujia[i].resize(screenW/5,screenH/30);
        shujia[i].setObjectName("AWL" + QString::number(i));
        shujia[i].setStyleSheet("QLabel#AWL" + QString::number(i) + "{border-image:url(:/images/书架)}");
        qDebug() << "AWL" + QString::number(i) ;
    }
    shujia[0].move(screenW*1.5/5,screenH/3);
    shujia[1].move(screenW*2.5/5,screenH/3);

    shujia[2].move(screenW/5,screenH*13/30);
    shujia[3].move(screenW*2/5,screenH*13/30);
    shujia[4].move(screenW*3/5,screenH*13/30);

    shujia[5].move(screenW*0.5/5,screenH*16/30);
    shujia[6].move(screenW*1.5/5,screenH*16/30);
    shujia[7].move(screenW*2.5/5,screenH*16/30);
    shujia[8].move(screenW*3.5/5,screenH*16/30);


    scatter[0][0].move(screenW*1.5/5 + screenW*3/80,screenH*11/30+20);
    scatter[0][1].move(screenW*2.5/5 + screenW*3/80,screenH*11/30+20);
    scatter[0][0].x = 1;
    scatter[0][0].y = 1;
    scatter[0][1].x = 1;
    scatter[0][1].y = 2;
    scatter[0][0].show();
    scatter[0][1].show();
    scatter[0][2].move(screenW/5 + screenW*3/80,screenH*14/30+20);
    scatter[0][3].move(screenW*2/5 + screenW*3/80,screenH*14/30+20);
    scatter[0][4].move(screenW*3/5 + screenW*3/80,screenH*14/30+20);
    scatter[0][2].x = 2;
    scatter[0][2].y = 1;
    scatter[0][3].x = 2;
    scatter[0][3].y = 2;
    scatter[0][4].x = 2;
    scatter[0][4].y = 3;
    scatter[0][2].show();
    scatter[0][3].show();
    scatter[0][4].show();
    scatter[0][5].move(screenW*0.5/5 + screenW*3/80,screenH*17/30+20);
    scatter[0][6].move(screenW*1.5/5 + screenW*3/80,screenH*17/30+20);
    scatter[1][0].move(screenW*2.5/5 + screenW*3/80,screenH*17/30+20);
    scatter[1][1].move(screenW*3.5/5 + screenW*3/80,screenH*17/30+20);
    scatter[0][5].x = 3;
    scatter[0][5].y = 1;
    scatter[0][6].x = 3;
    scatter[0][6].y = 2;
    scatter[1][0].x = 3;
    scatter[1][0].y = 3;
    scatter[1][1].x = 3;
    scatter[1][1].y = 4;
    scatter[0][5].show();
    scatter[0][6].show();
    scatter[1][0].show();
    scatter[1][1].show();


    QPushButton* shafa = new QPushButton[6];
    for(int i = 0;i < 6;i++){
        shafa[i].setParent(AW);
        shafa[i].setObjectName("SF" + QString::number(i));
        qDebug() << "SF" + QString::number(i) ;
        shafa[i].show();
    }


    shafa[0].resize(screenW/5,screenH/30);
    shafa[1].resize(screenW/5,screenH/30);
    shafa[2].resize(screenW*0.8/5,screenW*0.8/5);
    shafa[3].resize(screenW*0.8/5,screenW*0.8/5);
    shafa[4].resize(screenW/5,screenH/30);
    shafa[5].resize(screenW/5,screenH/30);
    shafa[0].setStyleSheet("QPushButton#SF0{border-image:url(:/images/沙发6)}");
    shafa[1].setStyleSheet("QPushButton#SF1{border-image:url(:/images/沙发6)}");
    shafa[2].setStyleSheet("QPushButton#SF2{border-image:url(:/images/沙发3)}");
    shafa[3].setStyleSheet("QPushButton#SF3{border-image:url(:/images/沙发4)}");
    shafa[4].setStyleSheet("QPushButton#SF4{border-image:url(:/images/沙发)}");
    shafa[5].setStyleSheet("QPushButton#SF5{border-image:url(:/images/沙发)}");

    //shujia[0].move(screenW*1.5/5,screenH/3);
    shafa[0].move(screenW/5,screenH/4);
    shafa[1].move(screenW*3/5,screenH/4);
    shafa[2].move(screenW*0.5/5,screenH/3);
    shafa[3].move(screenW*3.75/5,screenH/3);
    shafa[4].move(screenW/5,screenH*19/30);
    shafa[5].move(screenW*3/5,screenH*19/30);

    //shujia[8].move(screenW*3.5/5,screenH*16/30);

    AW->setStyleSheet("QWidget#AW{border-image:url(:/images/login)}");
    AW->show();

}

void setFind::showB(){


    QLabel* penzai = new QLabel(BW);
    penzai->resize(screenW/6,screenW/6);
    penzai->move(screenW*5/12,screenH/2-screenW*3.5/12);
    penzai->setObjectName("penzai");
    penzai->setStyleSheet("QLabel#penzai{border-image:url(:/images/盆栽)}");
    penzai->show();

    QLabel* shujia = new QLabel[20];
    for(int i = 0;i < 20;i++){
        shujia[i].setParent(BW);
        shujia[i].resize(screenW/6,screenH/30);
        shujia[i].setObjectName("BWL" + QString::number(i));
        shujia[i].setStyleSheet("QLabel#BWL" + QString::number(i) + "{border-image:url(:/images/书架)}");
        qDebug() << "BWL" + QString::number(i) ;
        shujia[i].show();
    }
    shujia[0].resize(screenW/5,screenH/30);
    shujia[1].resize(screenW/5,screenH/30);
    shujia[2].resize(screenW/5,screenH/30);
    shujia[3].resize(screenW/5,screenH/30);
    shujia[0].move(screenW*0.5/5,screenH*2/30);
    shujia[1].move(screenW*1.5/5,screenH*2/30);
    shujia[2].move(screenW*2.5/5,screenH*2/30);
    shujia[3].move(screenW*3.5/5,screenH*2/30);

    shujia[4].move(screenW*3/30,screenH*6/30);
    shujia[5].move(screenW*8/30,screenH*6/30);
    shujia[6].move(screenW*17/30,screenH*6/30);
    shujia[7].move(screenW*22/30,screenH*6/30);

    shujia[8].move(screenW*3/30,screenH*17/30);
    shujia[9].move(screenW*8/30,screenH*17/30);
    shujia[10].move(screenW*17/30,screenH*17/30);
    shujia[11].move(screenW*22/30,screenH*17/30);

    shujia[12].move(screenW*3/30,screenH*21/30);
    shujia[13].move(screenW*8/30,screenH*21/30);
    shujia[14].move(screenW*17/30,screenH*21/30);
    shujia[15].move(screenW*22/30,screenH*21/30);

    shujia[16].resize(screenW/5,screenH/30);
    shujia[17].resize(screenW/5,screenH/30);
    shujia[18].resize(screenW/5,screenH/30);
    shujia[19].resize(screenW/5,screenH/30);
    shujia[16].move(screenW*0.5/5,screenH*25/30);
    shujia[17].move(screenW*1.5/5,screenH*25/30);
    shujia[18].move(screenW*2.5/5,screenH*25/30);
    shujia[19].move(screenW*3.5/5,screenH*25/30);

    scatter[1][2].move(screenW*14.5/120,screenH*4/30);
    scatter[1][3].move(screenW*34.5/120,screenH*4/30);
    scatter[1][4].move(screenW*70.5/120,screenH*4/30);
    scatter[1][5].move(screenW*90.5/120,screenH*4/30);
    scatter[1][2].x = 1;
    scatter[1][2].y = 1;
    scatter[1][3].x = 1;
    scatter[1][3].y = 2;
    scatter[1][4].x = 1;
    scatter[1][4].y = 3;
    scatter[1][5].x = 1;
    scatter[1][5].y = 4;
    scatter[1][2].show();
    scatter[1][3].show();
    scatter[1][4].show();
    scatter[1][5].show();

    scatter[1][6].move(screenW*14.5/120,screenH*19/30);
    scatter[2][0].move(screenW*34.5/120,screenH*19/30);
    scatter[2][1].move(screenW*70.5/120,screenH*19/30);
    scatter[2][2].move(screenW*90.5/120,screenH*19/30);
    scatter[1][6].x = 2;
    scatter[1][6].y = 1;
    scatter[2][0].x = 2;
    scatter[2][0].y = 2;
    scatter[2][1].x = 2;
    scatter[2][1].y = 3;
    scatter[2][2].x = 2;
    scatter[2][2].y = 4;
    scatter[1][6].show();
    scatter[2][0].show();
    scatter[2][1].show();
    scatter[2][2].show();

    scatter[2][3].move(screenW*14.5/120,screenH*23/30);
    scatter[2][4].move(screenW*34.5/120,screenH*23/30);
    scatter[2][5].move(screenW*70.5/120,screenH*23/30);
    scatter[2][6].move(screenW*90.5/120,screenH*23/30);
    scatter[2][3].x = 3;
    scatter[2][3].y = 1;
    scatter[2][4].x = 3;
    scatter[2][4].y = 2;
    scatter[2][5].x = 3;
    scatter[2][5].y = 3;
    scatter[2][6].x = 3;
    scatter[2][6].y = 4;
    scatter[2][3].show();
    scatter[2][4].show();
    scatter[2][5].show();
    scatter[2][6].show();


    QPushButton* shafa = new QPushButton[4];
    for(int i = 0;i < 4;i++){
        shafa[i].setParent(BW);
        shafa[i].setObjectName("SF" + QString::number(i));
        qDebug() << "SF" + QString::number(i) ;
        shafa[i].show();
    }


    shafa[0].resize(screenW/5,screenH/30);
    shafa[1].resize(screenW/5,screenH/30);
    shafa[2].resize(screenH/30,screenW/5);
    shafa[3].resize(screenH/30,screenW/5);

    shafa[0].setStyleSheet("QPushButton#SF0{border-image:url(:/images/沙发6)}");
    shafa[1].setStyleSheet("QPushButton#SF1{border-image:url(:/images/沙发)}");
    shafa[2].setStyleSheet("QPushButton#SF2{border-image:url(:/images/沙发竖)}");
    shafa[3].setStyleSheet("QPushButton#SF3{border-image:url(:/images/沙发竖5)}");


    //shujia[0].move(screenW*1.5/5,screenH/3);
    shafa[0].move(screenW*2/5,screenH*11.5/30-screenW*4/30);
    shafa[1].move(screenW*2/5,screenH*11.5/30+screenW*4/30);
    shafa[2].move(screenW*2/5-screenH/30,screenH*11.5/30 - screenW*2/30);
    shafa[3].move(screenW*3/5,screenH*11.5/30 - screenW*2/30);


    //shujia[8].move(screenW*3.5/5,screenH*16/30);

    BW->setStyleSheet("QWidget#BW{border-image:url(:/images/login)}");
    BW->show();
}

void setFind::showC(){

    scatter[3][0].x = 1;
    scatter[3][0].y = 1;
    scatter[3][1].x = 2;
    scatter[3][1].y = 1;
    scatter[3][2].x = 3;
    scatter[3][2].y = 1;
    scatter[3][3].x = 4;
    scatter[3][3].y = 1;
    scatter[3][4].x = 5;
    scatter[3][4].y = 1;
    scatter[3][5].x = 1;
    scatter[3][5].y = 3;
    scatter[3][6].x = 2;
    scatter[3][6].y = 3;
    scatter[4][0].x = 3;
    scatter[4][0].y = 3;
    scatter[4][1].x = 4;
    scatter[4][1].y = 3;
    scatter[4][2].x = 5;
    scatter[4][2].y = 3;
    scatter[4][3].x = 1;
    scatter[4][3].y = 2;
    scatter[4][4].x = 2;
    scatter[4][4].y = 2;
    scatter[4][5].x = 4;
    scatter[4][5].y = 2;
    scatter[4][6].x = 5;
    scatter[4][6].y = 2;

    //this->scatter[0][0].move();
    this->scatter[3][0].move(screenW*3/80,screenH*8.5/30);
    this->scatter[3][1].move(screenW*3/80,screenH*11.5/30);
    this->scatter[3][2].move(screenW*3/80,screenH*14.5/30);
    this->scatter[3][3].move(screenW*3/80,screenH*17.5/30);
    this->scatter[3][4].move(screenW*3/80,screenH*20.5/30);
    this->scatter[3][5].move(screenW*67/80,screenH*8.5/30);
    this->scatter[3][6].move(screenW*67/80,screenH*11.5/30);
    this->scatter[4][0].move(screenW*67/80,screenH*14.5/30);
    this->scatter[4][1].move(screenW*67/80,screenH*17.5/30);
    this->scatter[4][2].move(screenW*67/80,screenH*20.5/30);
    this->scatter[4][3].move(screenW*7/16,screenH*8.5/30);
    this->scatter[4][4].move(screenW*7/16,screenH*11.5/30);
    this->scatter[4][5].move(screenW*7/16,screenH*17.5/30);
    this->scatter[4][6].move(screenW*7/16,screenH*20.5/30);
    QLabel* penzai = new QLabel(CW);
    penzai->resize(screenW/6,screenW/6);
    penzai->move(screenW*5/12,screenH/2-screenW/12);
    penzai->setObjectName("penzai");
    penzai->setStyleSheet("QLabel#penzai{border-image:url(:/images/盆栽)}");
    penzai->show();

    QLabel* shujia = new QLabel[10];
    for(int i = 0;i < 10;i++){
        shujia[i].setParent(CW);
        shujia[i].resize(screenW/6,screenH/30);
        shujia[i].setObjectName("CWL" + QString::number(i));
        shujia[i].setStyleSheet("QLabel#CWL" + QString::number(i) + "{border-image:url(:/images/书架竖)}");
        qDebug() << "CWL" + QString::number(i) ;
        shujia[i].show();
    }

    shujia[0].resize(screenW/5,screenH/10);
    shujia[1].resize(screenW/5,screenH/10);
    shujia[2].resize(screenW/5,screenH/10);
    shujia[3].resize(screenW/5,screenH/10);
    shujia[4].resize(screenW/5,screenH/10);
    shujia[5].resize(screenW/5,screenH/10);
    shujia[6].resize(screenW/5,screenH/10);
    shujia[7].resize(screenW/5,screenH/10);
    shujia[8].resize(screenW/5,screenH/10);
    shujia[9].resize(screenW/5,screenH/10);

    shujia[0].move(screenW*1/5,screenH*7.5/30);
    shujia[1].move(screenW*1/5,screenH*10.5/30);
    shujia[2].move(screenW*1/5,screenH*13.5/30);
    shujia[3].move(screenW*1/5,screenH*16.5/30);
    shujia[4].move(screenW*1/5,screenH*19.5/30);
    shujia[5].move(screenW*3/5,screenH*7.5/30);
    shujia[6].move(screenW*3/5,screenH*10.5/30);
    shujia[7].move(screenW*3/5,screenH*13.5/30);
    shujia[8].move(screenW*3/5,screenH*16.5/30);
    shujia[9].move(screenW*3/5,screenH*19.5/30);

    QPushButton* shafa = new QPushButton[6];
    for(int i = 0;i < 6;i++){
        shafa[i].setParent(CW);
        shafa[i].setObjectName("SF" + QString::number(i));
        qDebug() << "SF" + QString::number(i) ;
        shafa[i].show();
    }

//    shafa[1].resize(screenW/5,screenH/30);
//    shafa[2].resize(screenW*0.8/5,screenW*0.8/5);


    shafa[0].resize(screenW/5,screenH/30);
    shafa[1].resize(screenW/5,screenH/30);
    shafa[2].resize(screenW*0.8/5,screenW*0.8/5);
    shafa[3].resize(screenW*0.8/5,screenW*0.8/5);
    shafa[4].resize(screenW*0.8/5,screenW*0.8/5);
    shafa[5].resize(screenW*0.8/5,screenW*0.8/5);

    shafa[0].setStyleSheet("QPushButton#SF0{border-image:url(:/images/沙发6)}");
    shafa[1].setStyleSheet("QPushButton#SF1{border-image:url(:/images/沙发)}");
    shafa[2].setStyleSheet("QPushButton#SF2{border-image:url(:/images/沙发3)}");
    shafa[3].setStyleSheet("QPushButton#SF3{border-image:url(:/images/沙发4)}");
    shafa[4].setStyleSheet("QPushButton#SF4{border-image:url(:/images/沙发1)}");
    shafa[5].setStyleSheet("QPushButton#SF5{border-image:url(:/images/沙发2)}");

    shafa[0].move(screenW*2/5,screenH/10);
    shafa[1].move(screenW*2/5,screenH*8.5/10);
    shafa[2].move(screenW*0.5/5,screenH*1.5/10);
    shafa[3].move(screenW*3.75/5,screenH*1.5/10);
    shafa[4].move(screenW*0.5/5,screenH*22.5/30);
    shafa[5].move(screenW*3.75/5,screenH*22.5/30);

    CW->setStyleSheet("QWidget#CW{border-image:url(:/images/login)}");
    CW->show();
}

void setFind::initSet(){
    this->AW = new QWidget;
    AW->setObjectName("AW");


//    this->scatter[i][j].setParent(setwindow);
//    this->scatter[i][j].x = i;
//    this->scatter[i][j].y = j;
//    this->scatter[i][j].area = "图书馆一楼";
//    this->scatter[i][j].resize(screenW/6,screenH/30);
//    this->scatter[i][j].move(screenW/12+i*screenW/6,screenH/3+j*screenH/30);
    qDebug() << "==============---------==========";
    for(int i = 0;i < 1;i++){
        for(int j = 0;j < 7;j++){
            //connect(&this->scatter[i][j],&set::clicked,this,&setFind::checkset);

            this->scatter[i][j].setParent(AW);
            this->scatter[i][j].area = "第一楼";
            this->scatter[i][j].resize(screenW*5/40,screenH/30);
            this->scatter[i][j].setObjectName(QString::number(i) + QString::number(j));
            //qDebug() << QString::number(this->mainwindow->pinfo->number[0][i][j]) << "   898989";
            this->scatter[i][j].num = this->mainwindow->pinfo->number[0][i][j];
            switch (this->mainwindow->pinfo->number[0][i][j]) {
            case 0:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set0)}");
                break;
            case 1:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set1)}");
                break;
            case 2:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set2)}");
                break;
            case 3:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set3)}");
                break;
            case 4:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set4)}");
                break;
            default:
                break;
            this->scatter[i][j].hide();
            }
        }
    }

    for(int i = 1;i < 2;i++){
        for(int j = 0;j < 2;j++){
            //connect(&this->scatter[i][j],&set::clicked,this,&setFind::checkset);

            this->scatter[i][j].setParent(AW);
            this->scatter[i][j].area = "第一楼";
            this->scatter[i][j].resize(screenW*5/40,screenH/30);
            this->scatter[i][j].setObjectName(QString::number(i) + QString::number(j));
            //qDebug() << QString::number(this->mainwindow->pinfo->number[0][i][j]) << "   898989";
            this->scatter[i][j].num = this->mainwindow->pinfo->number[0][i][j];
            switch (this->mainwindow->pinfo->number[0][i][j]) {
            case 0:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set0)}");
                break;
            case 1:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set1)}");
                break;
            case 2:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set2)}");
                break;
            case 3:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set3)}");
                break;
            case 4:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set4)}");
                break;
            default:
                break;
            this->scatter[i][j].hide();
            }
        }
    }
    this->BW = new QWidget;
    BW->setObjectName("BW");

    for(int i = 1;i < 2;i++){
        for(int j = 2;j < 7;j++){
            //connect(&this->scatter[i][j],&set::clicked,this,&setFind::checkset);
            this->scatter[i][j].setParent(BW);
            this->scatter[i][j].area = "第一楼";
            this->scatter[i][j].resize(screenW*5/40,screenH/30);
            this->scatter[i][j].setObjectName(QString::number(i) + QString::number(j));
            //qDebug() << QString::number(this->mainwindow->pinfo->number[0][i][j]) << "   898989";
            this->scatter[i][j].num = this->mainwindow->pinfo->number[0][i][j];
            switch (this->mainwindow->pinfo->number[0][i][j]) {
            case 0:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set0)}");
                break;
            case 1:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set1)}");
                break;
            case 2:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set2)}");
                break;
            case 3:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set3)}");
                break;
            case 4:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set4)}");
                break;
            default:
                break;
            this->scatter[i][j].hide();
            }
        }
    }
    for(int i = 2;i < 3;i++){
        for(int j = 0;j < 7;j++){
            //connect(&this->scatter[i][j],&set::clicked,this,&setFind::checkset);
            this->scatter[i][j].setParent(BW);
            this->scatter[i][j].area = "第一楼";
            this->scatter[i][j].resize(screenW*5/40,screenH/30);
            this->scatter[i][j].setObjectName(QString::number(i) + QString::number(j));
            //qDebug() << QString::number(this->mainwindow->pinfo->number[0][i][j]) << "   898989";
            this->scatter[i][j].num = this->mainwindow->pinfo->number[0][i][j];
            switch (this->mainwindow->pinfo->number[0][i][j]) {
            case 0:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set0)}");
                break;
            case 1:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set1)}");
                break;
            case 2:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set2)}");
                break;
            case 3:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set3)}");
                break;
            case 4:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set4)}");
                break;
            default:
                break;
            this->scatter[i][j].hide();
            }
        }
    }

    this->CW = new QWidget;
    CW->setObjectName("CW");
    for(int i = 3;i < 5;i++){
        for(int j = 0;j < 7;j++){
            //connect(&this->scatter[i][j],&set::clicked,this,&setFind::checkset);
            this->scatter[i][j].setParent(CW);
            this->scatter[i][j].area = "第一楼";
            this->scatter[i][j].resize(screenW*5/40,screenH/30);
            this->scatter[i][j].setObjectName(QString::number(i) + QString::number(j));
            qDebug() << QString::number(this->mainwindow->pinfo->number[0][i][j]) << "   898989";
            this->scatter[i][j].num = this->mainwindow->pinfo->number[0][i][j];
            switch (this->mainwindow->pinfo->number[0][i][j]) {
            case 0:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set0)}");
                break;
            case 1:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set1)}");
                break;
            case 2:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set2)}");
                break;
            case 3:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set3)}");
                break;
            case 4:
                this->scatter[i][j].setStyleSheet("set#" + QString::number(i) + QString::number(j) + "{border-image:url(:/images/set4)}");
                break;
            default:
                break;
            this->scatter[i][j].hide();
            }
        }
    }


}

setFind::~setFind(){}
