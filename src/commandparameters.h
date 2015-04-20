#ifndef COMMANDPARAMETERS_H
#define COMMANDPARAMETERS_H
#include <QMap>

class CommandParameters
{
public:
    CommandParameters();
    bool static isCommandMode();
    bool static hasCache();
    bool static hasScript();
    bool static hasStart();
    bool static hasHelp();
    bool static hasVersion();
    static QMap<QString, QString> *args;
    void setArgs(QMap<QString, QString> *param);
private:

};

#endif // COMMANDPARAMETERS_H
