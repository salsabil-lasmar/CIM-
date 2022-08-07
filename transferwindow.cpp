#include "transferwindow.h"
#include "inifile.h"
#include "qstandarditemmodel.h"
#include "ui_transferwindow.h"
#include<QDir>
TransferWindow::TransferWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransferWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Transfer Window");
    Settings obj;
    QString pathTrans= obj.getValue(obj.init("Settings.ini"),"PATHAMBITCIM")+"\\AmbitCIM_DEV\\00_Transfer";
    QStringList CIMTeam;
    QStandardItemModel *standardModel = new QStandardItemModel ;
    QStandardItem *rootNode = standardModel->invisibleRootItem();
    CIMTeam<<"Hamdi"<<"Rihab"<<"Salma"<<"Souhail"<<"Firas"<<"Issam"<<"Alaa"<<"Bilel"<<"Nidhal"<<"Khalil"<<"Nada";
    QDir directory(pathTrans);
    QStringList TransList = directory.entryList();
    for ( int i=0;i<TransList.size();i++){
        for(int j=0;j<CIMTeam.size();j++)
          if(TransList[i]==CIMTeam[j]){
            auto item = new QStandardItem (TransList[i]);
            rootNode->appendRow(item);
            item->setIcon(QIcon("iconjpgdir.jpg"));}
   }


 ui->treeView->setModel(standardModel);
}

TransferWindow::~TransferWindow()
{
    delete ui;
}
