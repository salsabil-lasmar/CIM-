#ifndef DOCWINDOW_H
#define DOCWINDOW_H

#include <QDialog>

namespace Ui {
class DocWindow;
}

class DocWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DocWindow(QWidget *parent = nullptr);
    ~DocWindow();

private:
    Ui::DocWindow *ui;
};

#endif // DOCWINDOW_H
