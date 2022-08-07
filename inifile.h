#ifndef INIFILE_H
#define INIFILE_H

#include<QString>
class Settings
{
public:
    Settings();
    QMap<QString,QString> init (QString path);
    QString getValue(QMap<QString,QString> M,QString key);
    //~Settings();
};


#endif // INIFILE_H
