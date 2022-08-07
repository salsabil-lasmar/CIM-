#include "getpath.h"
#include"inifile.h"
#include<QDir>
#include<QDebug>
#include<iostream>
getpath::getpath()
{

}

QList<QString> getpath :: getClientList(){

    QString pathFileini = "Settings.ini";
    Settings obj;
    pathGlobal = obj.getValue(obj.init(pathFileini),"PATHGLOBAL");
    pathInclude = obj.getValue(obj.init(pathFileini),"PATHDEFINE");

    QStringList listclientName,liste_des_clients ;
    QString ClientName;
    QDir dir (pathGlobal );
    QList <QFileInfo> clientList= dir.entryInfoList();
    for(  const auto &e : qAsConst(clientList)){
        ClientName= e.baseName();
        QString pathclientName=pathGlobal+"\\"+ClientName;
        QDir directory (pathclientName);
        QStringList testlist = directory.entryList();
        for(  const auto &element : qAsConst(testlist)){

              if(element.contains(".groupproj")  ){
                  liste_des_clients.append(ClientName);
                  break;
              }
        }
    }
    return liste_des_clients;

}

QList<QString> getpath :: getPathList(){
   QList<QString> NewPaths;
   QList<QString> list = getClientList();
   for( auto &e : list){
       QString IncludeCim=pathGlobal+"\\"+pathInclude;
       QString NewPath =replaceNameClient(IncludeCim,e);
       NewPaths.append(NewPath);}
 return NewPaths;

}

QString getpath :: replaceNameClient(QString path , QString Client){

    path.replace("*",Client);
    return path;
   }

