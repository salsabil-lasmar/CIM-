#include "mainwindow.h"
#include "clientdeliveries.h"
#include "docwindow.h"
#include "inifile.h"
#include "softwarewindow.h"
#include "techdocwindow.h"
#include "transferwindow.h"
#include "ui_mainwindow.h"
#include "getpath.h"
#include"dllswindow.h"
#include<QStandardItem>
#include<QFile>
#include<QDir>
#include<QItemSelection>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   this->setWindowTitle("CIM Application");
    getpath obj;
    QStringList clientList;
    clientList = obj.getClientList();
    QDir dir ("/\\nwa.file.core.windows.net\\ambit-cim\\Deliveries\\ClientDeliveries");
    QStringList deliveries = dir.entryList();
    //for(int i=0;i<clientList.size();i++)
        /*for(int j=0; j<deliveries.size(); j++)
            if(deliveries[j].contains(clientList[i]))
                NewList.push_back(clientList[i]);*/
    QStandardItemModel *standardModel = new QStandardItemModel ;
    QStandardItem *rootNode = standardModel->invisibleRootItem();
    //for( auto &clientName : clientList){
    for(int i=0;i<clientList.size();i++){
        auto item = new QStandardItem (clientList[i]);

        rootNode->appendRow(item);
        item->appendRow(new QStandardItem ("Define"));
        item->appendRow(new QStandardItem ("DBDesc_Common"));
        item->appendRow(new QStandardItem ("DBDesc_Admin"));
        item->appendRow(new QStandardItem ("Configproperty"));
        for(int j=0; j<deliveries.size(); j++)
            if(deliveries[j].contains(clientList[i])){

               map.insert(clientList[i],deliveries[j]);
              item->appendRow(new QStandardItem ("Tags"));
              break;}
        ui->treeView->setModel(standardModel);

    }
   connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged,
             this, &MainWindow::selectionChangedSlot);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectionChangedSlot(const QItemSelection & , const QItemSelection & )
{

    const QModelIndex index = ui->treeView->selectionModel()->currentIndex();
       QString selectedText = index.data(Qt::DisplayRole).toString();
     QModelIndex seekRoot = index;
        QString showparent = seekRoot.parent().data(Qt::DisplayRole).toString();
       QString text = QString("%1 of %2").arg(selectedText)
                            .arg(showparent);
    // ui->label->setText(text);

     Settings obj;
     QString pathClientDeliveries= obj.getValue(obj.init("Settings.ini"),"PATHAMBITCIM")+"\\Deliveries\\ClientDeliveries";

          for(auto i = map.begin(); i != map.end(); ++i){
              if ( text<=QString ("Tags of "+i.key())){
             QDir directory(pathClientDeliveries+"\\"+i.value());
             QStringList DisplayList = directory.entryList();
             DisplayList.removeAll(".");
             DisplayList.removeAll("..");
            ui->listWidget->addItems(DisplayList);
              break;

              }
              ui->listWidget->clear();
    }

}

void MainWindow::on_pushButton_clicked()
{
    DLLsWindow* Dlls=new  DLLsWindow(this);
    Dlls->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    DocWindow* Doc=new  DocWindow(this);
    Doc->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    SoftwareWindow* softsW=new  SoftwareWindow(this);
    softsW->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    TechDocWindow* TechDocW=new  TechDocWindow(this);
    TechDocW->show();
}




void MainWindow::on_pushButton_5_clicked()
{
    TransferWindow* TransferDocW=new  TransferWindow(this);
    TransferDocW->show();

}

