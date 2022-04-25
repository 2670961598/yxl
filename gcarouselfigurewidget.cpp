// gcarouselfigurewidget.cpp
#include "gcarouselfigurewidget.h"
#include <QAbstractButton>
#include <QPushButton>
GCarouselFigureWidget::GCarouselFigureWidget(int iwidth,int iheight,int imagesNums,QList<QString>& imageUrlList,QWidget *parent)
    :m_width(iwidth),m_height(iheight), m_imageNums(imagesNums),m_imageUrlList(imageUrlList), QWidget(parent)
{
    //初始化默认值
    m_autoPlay = false;
    m_autoPlaySecs = 0;

    setFixedSize (m_width,m_height);
    initWidget();
}

void GCarouselFigureWidget::initWidget(){
    // 图片显示控件
    m_imageWidget = new QWidget(this);
    m_imageWidget->setGeometry (0,0,width (),height ());

    // 轮播按钮组件
    m_btnGroup = new QButtonGroup(this);
    int originalpos_width = width()/2 - 15*m_imageNums/2;
    for(int i =0;i <m_imageNums;i++){
        QPushButton* absBtn = new QPushButton(this);
        absBtn->setStyleSheet("QPushButton{background-color:grey;"
                              "border-style: none;"
                              "border-top-right-radius:5px;"
                              "border-top-left-radius:5px;"
                              "border-bottom-right-radius:5px;"
                              "border-bottom-left-radius:5px}"
                              "QPushButton:hover{background-color:red;color: white;}"
                              "QPushButton:pressed{background-color:rgba(85, 170, 255,200); border-style: none; }");

        absBtn->setGeometry (originalpos_width + i*15,4*height ()/5,10,10);
        m_btnGroup->addButton (absBtn,i);
    }
    connect (m_btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(changedImage(int)));
    connect (&m_autoPlayTimer,SIGNAL(timeout()),this,SLOT(autoChangedImage()));

    // 初始化显示
    if(m_imageNums > 0){
        // default show the first image in the images-list
        m_imageIndex = 0;
        if(m_autoPlay){
            autoChangedImage ();
        }else{
            changedImage (0);
        }
    }else{
        m_imageIndex = -1;
    }
}

void GCarouselFigureWidget::setAutoPlay(bool flag,int milsecs)
{
    m_autoPlay = flag;
    if(m_autoPlay){
        m_autoPlayTimer.setInterval (milsecs);
        m_autoPlayTimer.start ();
    }else{
        m_autoPlayTimer.stop ();
    }
}

void GCarouselFigureWidget::autoChangedImage(){
    if(m_autoPlay){
        m_imageIndex = (++m_imageIndex)% m_imageNums;
        changedImage(m_imageIndex);
        // 当前图片对应的按钮显示红色，其他按钮颜色仍显示灰色
        for(int i = 0;i < m_imageNums;i++){
            if( i == m_imageIndex){
                m_btnGroup->buttons ().at (i)->setStyleSheet("QPushButton{background-color:red;"
                                                             "border-style: none;"
                                                             "border-top-right-radius:5px;"
                                                             "border-top-left-radius:5px;"
                                                             "border-bottom-right-radius:5px;"
                                                             "border-bottom-left-radius:5px}"
                                                             "QPushButton:hover{background-color:red;color: white;}"
                                                             "QPushButton:pressed{background-color:rgba(85, 170, 255,200); border-style: none; }");
            }else{
                m_btnGroup->buttons ().at (i)->setStyleSheet("QPushButton{background-color:grey;"
                                                             "border-style: none;"
                                                             "border-top-right-radius:5px;"
                                                             "border-top-left-radius:5px;"
                                                             "border-bottom-right-radius:5px;"
                                                             "border-bottom-left-radius:5px}"
                                                             "QPushButton:hover{background-color:red;color: white;}"
                                                             "QPushButton:pressed{background-color:rgba(85, 170, 255,200); border-style: none; }");
            }
        }
        update ();
    }
}


void GCarouselFigureWidget::changedImage(int index){
    QImage image;
    image.load (m_imageUrlList[index]);
    setAutoFillBackground (true);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window,
                 QBrush(image.scaled(size(), /*Qt::IgnoreAspectRatio*/Qt::KeepAspectRatioByExpanding,
                                     Qt::SmoothTransformation)));
    setPalette(pal);
    update ();
    // 记录当前图片位置
    m_imageIndex = index;
    // 当前图片对应的按钮显示红色，其他按钮颜色仍显示灰色
    for(int i = 0;i < m_imageNums;i++){
        if( i == m_imageIndex){
            m_btnGroup->buttons ().at (i)->setStyleSheet("QPushButton{background-color:red;"
                                                         "border-style: none;"
                                                         "border-top-right-radius:5px;"
                                                         "border-top-left-radius:5px;"
                                                         "border-bottom-right-radius:5px;"
                                                         "border-bottom-left-radius:5px}"
                                                         "QPushButton:hover{background-color:red;color: white;}"
                                                         "QPushButton:pressed{background-color:rgba(85, 170, 255,200); border-style: none; }");
        }else{
            m_btnGroup->buttons ().at (i)->setStyleSheet("QPushButton{background-color:grey;"
                                                         "border-style: none;"
                                                         "border-top-right-radius:5px;"
                                                         "border-top-left-radius:5px;"
                                                         "border-bottom-right-radius:5px;"
                                                         "border-bottom-left-radius:5px}"
                                                         "QPushButton:hover{background-color:red;color: white;}"
                                                         "QPushButton:pressed{background-color:rgba(85, 170, 255,200); border-style: none; }");
        }
    }
}

void GCarouselFigureWidget::resizeEvent(QResizeEvent *){

}

GCarouselFigureWidget::~GCarouselFigureWidget()
{

}
