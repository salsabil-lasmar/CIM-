#include "docwindow.h"
#include "inifile.h"
#include "qstandarditemmodel.h"
#include "ui_docwindow.h"
#include<QDir>
DocWindow::DocWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DocWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Documentation Window");
    Settings obj;
    QString pathDoc = obj.getValue(obj.init("Settings.ini"),"PATHAMBITCIM")+"\\Documentation";
    QStandardItemModel *standardModel = new QStandardItemModel ;
    QStandardItem *rootNode = standardModel->invisibleRootItem();
    QDir directory(pathDoc);
    QStringList DocList = directory.entryList();
    DocList.removeAll(".");
    DocList.removeAll("..");
    for ( auto &e:DocList){
        auto item = new QStandardItem (e);

        rootNode->appendRow(item);

    ui->treeView->setModel(standardModel);
    if(!e.contains('.')){
       item->setIcon(QIcon("iconjpgdir.jpg"));}
    else
       {item->setIcon(QIcon("images.png"));}

    }
}

DocWindow::~DocWindow()
{
    delete ui;
}
