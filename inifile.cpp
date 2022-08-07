#include "inifile.h"

#include<QSettings>
#include<QDebug>
Settings::Settings()
{


}
QMap<QString,QString> Settings:: init(QString path){
    QMap<QString,QString> pathMap;
    QSettings* settings = new QSettings(path, QSettings::IniFormat);

    settings->beginGroup("PATHS");

    const QStringList childKeys = settings->childKeys();
    QStringList values ;
    foreach (const QString &childKey, childKeys)
    values << settings->value(childKey).toString();
    for(int i=0; i<childKeys.size(); i++){
        pathMap.insert(childKeys[i],values[i]);
    }
    settings->endGroup();
return pathMap;

}


QString Settings ::getValue(QMap<QString,QString> M,QString key){
return M[key];
}
