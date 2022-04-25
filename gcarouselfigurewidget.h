// gcarouselfigurewidget.h

#ifndef GCAROUSELFIGUREWIDGET_H
#define GCAROUSELFIGUREWIDGET_H

#include <QWidget>
#include <QString>
#include <QList>
#include <QButtonGroup>
#include <QTimer>

/*!
 * \brief The GCarouselFigureWidget class
 *  图片轮播组件
 */

class GCarouselFigureWidget : public QWidget
{
    Q_OBJECT

public:
    GCarouselFigureWidget(int iwidth, int iheight, int imagesNums, QList<QString>& imageUrlList, QWidget *parent = 0);
    ~GCarouselFigureWidget();

    void resizeEvent(QResizeEvent *);
    void initWidget();

    // 设置自动播放
    void setAutoPlay(bool flag, int milsecs);

public slots:
    void changedImage(int index);  // 更换背景图片
    void autoChangedImage();       // 自动切换背景
public:
    QWidget* m_imageWidget;        // 显示图片的Widget
    QButtonGroup* m_btnGroup;      // 按钮组(圆形)

private:
    int m_width;
    int m_height;
    int m_imageNums;               // 定义要展示的图片的数量
    QList<QString> m_imageUrlList; // 所有要展示的图片的路径
    int m_imageIndex;              // 记录当前显示的图片的下标
    bool m_autoPlay;               // 是否自动播放图片,默认为否
    bool m_autoPlaySecs;           // 自动播放间隔时间
    QTimer m_autoPlayTimer;        // 自动播放定时器
};

#endif // GCAROUSELFIGUREWIDGET_H
