#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
<<<<<<< HEAD
QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE
=======

#include <QMessageBox>
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
>>>>>>> 7522dc93025c53d4ed9281b941da872fbea9bb7f

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent*);
<<<<<<< HEAD
    MainWindow(QWidget* parent=nullptr);
    ~MainWindow();


=======
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

>>>>>>> 7522dc93025c53d4ed9281b941da872fbea9bb7f
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
