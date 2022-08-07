#include "dllswindow.h"
#include "ui_dllswindow.h"

#include<QDir>
#include<QStandardItem>
#include<QMenu>
#include<QDebug>
DLLsWindow::DLLsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DLLsWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("DLLs");
    ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->treeView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotCustomMenuRequested(QPoint)));

    QDir directory("/\\nwa.file.core.windows.net\\ambit-cim\\Deliveries\\DLLs");
    QStringList DisplayList = directory.entryList();

    QStandardItemModel *standardModel = new QStandardItemModel ;
    QStandardItem *rootNode = standardModel->invisibleRootItem();

    for(int i=0;i<DisplayList.size();i++){

         DisplayList.removeAll(".");
         DisplayList.removeAll("..");
        //ui->listWidget->addItems(DisplayList);
        auto item = new QStandardItem (DisplayList[i]);

        rootNode->appendRow(item);


        QString pathDlls ="/\\nwa.file.core.windows.net\\ambit-cim\\Deliveries\\DLLs\\"+DisplayList[i];
        QDir dir(pathDlls);
        QStringList dllsVersion = dir.entryList();
        dllsVersion.removeAll("..");
        dllsVersion.removeAll(".");
        for(auto &element:dllsVersion){

            item->appendRow(new QStandardItem (element));
            item->setIcon(QIcon("iconjpgdir.jpg"));
            // ui->treeView->setModel(standardModel);
        }

    }

    ui->treeView->setModel(standardModel);

}
void DLLsWindow :: slotCustomMenuRequested(QPoint pos)
{


    QMenu *contextMenu = new QMenu(this);
    QAction * installAct = new QAction(tr("install"), this);


    contextMenu->addAction(installAct);
    contextMenu->exec(mapToGlobal(pos));
    contextMenu->popup(ui->treeView->viewport()->mapToGlobal(pos));
}


DLLsWindow::~DLLsWindow()
{
    delete ui;
}
