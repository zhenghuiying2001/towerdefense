#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD

=======
#include "tower.h"
#include <QList>
>>>>>>> 7522dc93025c53d4ed9281b941da872fbea9bb7f
class MyWindow : public QMainWindow
{
    Q_OBJECT
public:
<<<<<<< HEAD
    explicit MyWindow(QWidget *parent=nullptr);
    void paintEvent(QPaintEvent *);

private:

signals:
    void chooseBack();
=======
    explicit MyWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void set_tower();
private:
    QList<Tower*> tower_list;
signals:
    void chooseBack();
public slots:
>>>>>>> 7522dc93025c53d4ed9281b941da872fbea9bb7f
};

#endif // MYWINDOW_H
