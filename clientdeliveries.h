#ifndef CLIENTDELIVERIES_H
#define CLIENTDELIVERIES_H

#include <QDialog>

namespace Ui {
class ClientDeliveries;
}

class ClientDeliveries : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDeliveries(QWidget *parent = nullptr);
     QStringList NewList;
    ~ClientDeliveries();

private:
    Ui::ClientDeliveries *ui;
};

#endif // CLIENTDELIVERIES_H
