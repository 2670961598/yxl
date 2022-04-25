#ifndef SET_H
#define SET_H

#include <QWidget>
#include <QPushButton>


class set : public QPushButton
{
    Q_OBJECT
public:
    //这个桌子上还剩几个座位。
    int num = 4;
    set();
    //这个座位所处的区域
    QString area;
    QString areaa;
    //这个座位所在的位置
    int x;
    int y;

public:
    const QString gettext();
    const QString getmaintext();
};

#endif // SET_H
