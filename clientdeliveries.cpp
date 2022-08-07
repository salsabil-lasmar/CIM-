#include "clientdeliveries.h"
#include "ui_clientdeliveries.h"
#include "getpath.h"

#include<QDebug>
#include<QDir>
#include<QRegularExpression>
ClientDeliveries::ClientDeliveries(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDeliveries)
{
    ui->setupUi(this);
   // QDir directory("/\\nwa.file.core.windows.net\\ambit-cim\\Deliveries\\ClientDeliveries");
    //QStringList DisplayList = directory.entryList();

}

ClientDeliveries::~ClientDeliveries()
{
    delete ui;
}
