#include "defaultconfig.h"
#include <QSettings>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <qstring.h>
void syncDefaultConfig(const QString& iniName)
{
    QFile file(iniName);
    if (!file.exists()) {
        const QString dirPath = QFileInfo(iniName).absolutePath();
        QDir dir(dirPath);
        if (!dir.exists())
            dir.mkpath(dirPath);

        QFile::copy(":/config/default.ini", iniName);
        file.setPermissions(QFile::ReadOwner | QFile::WriteOwner);
    } else {
        QSettings config(iniName, QSettings::IniFormat);
        config.beginGroup("Settings");
        if (config.value("Language").toString().isEmpty())
            config.setValue("Language", "en");
        if (config.value("Theme").toString().isEmpty())
            config.setValue("Theme", "default");
        config.endGroup();
    }
}

