#ifndef TRANSFERWINDOW_H
#define TRANSFERWINDOW_H

#include <QDialog>

namespace Ui {
class TransferWindow;
}

class TransferWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TransferWindow(QWidget *parent = nullptr);
    ~TransferWindow();

private:
    Ui::TransferWindow *ui;
};

#endif // TRANSFERWINDOW_H
