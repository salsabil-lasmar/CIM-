#include "softwarewindow.h"
#include "inifile.h"
#include "ui_softwarewindow.h"
#include<QDir>
#include<QStandardItem>
SoftwareWindow::SoftwareWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SoftwareWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Install Softwares");
    Settings obj;
    QString pathSoft= obj.getValue(obj.init("Settings.ini"),"PATHAMBITCIM")+"\\InstallSoftwares";
    QStandardItemModel *standardModel = new QStandardItemModel ;
    QStandardItem *rootNode = standardModel->invisibleRootItem();
    QDir directory(pathSoft);
    QStringList softsList = directory.entryList();
    softsList.removeAll(".");
    softsList.removeAll("..");
    for(auto &e:softsList){
        auto item = new QStandardItem (e);
        rootNode->appendRow(item);
        /* ui->treeView->setModel(standardModel);
        QString pathSofts ="/\\nwa.file.core.windows.net\\ambit-cim\\Deliveries\\InstallSoftwares\\"+e;
       QDir dir(pathSofts);
        QStringList softsFile= dir.entryList();
        softsFile.removeAll("..");
        softsFile.removeAll(".");
        for(auto &element:softsFile){

            item->appendRow(new QStandardItem (element));
            item->setIcon(QIcon("iconjpg.jpg"));
            ui->treeView->setModel(standardModel);
        }*/
        if(!e.contains('.')){
           item->setIcon(QIcon("iconjpgdir.jpg"));}
        else
           {item->setIcon(QIcon("images.png"));}

        ui->treeView->setModel(standardModel);
    }
    ui->treeView->setModel(standardModel);

}

SoftwareWindow::~SoftwareWindow()
{
    delete ui;
}
