#ifndef QMSG_H
#define QMSG_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>



class QMsg : public QMessageBox
{
    Q_OBJECT
public:
    explicit QMsg(QMessageBox *parent = nullptr);




signals:

};

#endif // QMSG_H
