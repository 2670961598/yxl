#ifndef FRIENDS_H
#define FRIENDS_H

#include <QObject>
#include "set.h"


class friends
{

public:
    //联系人的姓名
    const QString thisname;
    //联系人的座位
    const QString studentNumber;
    set* findSet;

    friends(const QString name,const QString Number);
};

#endif // FRIENDS_H
