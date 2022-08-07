#ifndef DLLSWINDOW_H
#define DLLSWINDOW_H

#include "qstandarditemmodel.h"
#include <QDialog>

namespace Ui {
class DLLsWindow;
}

class DLLsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DLLsWindow(QWidget *parent = nullptr);
    ~DLLsWindow();

private slots :

     void slotCustomMenuRequested(QPoint pos);

private:
    Ui::DLLsWindow *ui;
    QStandardItemModel *model;
    QList<QStandardItem *> list_items;
};

#endif // DLLSWINDOW_H
