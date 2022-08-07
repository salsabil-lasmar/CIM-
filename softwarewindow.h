#ifndef SOFTWAREWINDOW_H
#define SOFTWAREWINDOW_H

#include <QDialog>

namespace Ui {
class SoftwareWindow;
}

class SoftwareWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SoftwareWindow(QWidget *parent = nullptr);
    ~SoftwareWindow();

private:
    Ui::SoftwareWindow *ui;
};

#endif // SOFTWAREWINDOW_H
