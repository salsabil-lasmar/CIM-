#ifndef TECHDOCWINDOW_H
#define TECHDOCWINDOW_H

#include <QDialog>

namespace Ui {
class TechDocWindow;
}

class TechDocWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TechDocWindow(QWidget *parent = nullptr);
    ~TechDocWindow();

private:
    Ui::TechDocWindow *ui;
};

#endif // TECHDOCWINDOW_H
