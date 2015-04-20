#include "commandparameters.h"
#include <QtCore/QDebug>

QMap<QString, QString> *CommandParameters::args = new QMap<QString, QString>();
CommandParameters::CommandParameters()
{
}

void CommandParameters::setArgs(QMap<QString, QString> *param)
{
    CommandParameters::args = param;
}

bool CommandParameters::isCommandMode()
{
    return CommandParameters::args->contains("command");
}

bool CommandParameters::hasStart()
{
    return CommandParameters::args->contains("start");
}


bool CommandParameters::hasScript()
{
    return CommandParameters::args->contains("script") &&
           CommandParameters::args->value("script") != "";
}

bool CommandParameters::hasHelp()
{
    return CommandParameters::args->contains("help");
}

bool CommandParameters::hasVersion()
{
    return CommandParameters::args->contains("version");
}

bool CommandParameters::hasCache()
{
    return CommandParameters::args->contains("cache");
}
