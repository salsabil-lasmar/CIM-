#include "techdocwindow.h"
#include "inifile.h"
#include "qstandarditemmodel.h"
#include "ui_techdocwindow.h"
#include<QDir>
TechDocWindow::TechDocWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TechDocWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Technical Documentation");
    Settings obj;
    QString pathTechDoc= obj.getValue(obj.init("Settings.ini"),"PATHAMBITCIM")+"\\AmbitCIM_DEV\\06_Technical_documentation";
    QDir directory(pathTechDoc);
    QStringList TDocList = directory.entryList();

    QStandardItemModel *standardModel = new QStandardItemModel ;
    QStandardItem *rootNode = standardModel->invisibleRootItem();

    for(int i=0;i<TDocList.size();i++){
         TDocList.removeAll(".");
         TDocList.removeAll("..");
        auto item = new QStandardItem (TDocList[i]);

        rootNode->appendRow(item);


        QString path =pathTechDoc+"\\"+TDocList[i];
        QDir dir(path);
        QStringList techDocs = dir.entryList();
        techDocs.removeAll("..");
        techDocs.removeAll(".");
        for(auto &element:techDocs){

            item->appendRow(new QStandardItem (element));
            item->setIcon(QIcon("iconjpgdir.jpg"));
        }

    }
    ui->treeView->setModel(standardModel);



}

TechDocWindow::~TechDocWindow()
{
    delete ui;
}
