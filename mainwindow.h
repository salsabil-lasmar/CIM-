#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qitemselectionmodel.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   QMap<QString,QString> map ;
     void clientDeliveries();
private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_4_clicked();

     void selectionChangedSlot(const QItemSelection & , const QItemSelection & );

     void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
