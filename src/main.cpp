#include <QtCore/QTextCodec>
#include <QtWidgets/QApplication>
#include <QtCore/QCommandLineOption>
#include <QtCore/QCommandLineParser>

#include "mainwindow.h"
#include "commandparameters.h"
#include "consts.h"

int main(int argc, char *argv[])
{
    QTextCodec *localCode = QTextCodec::codecForLocale();
    QTextCodec::setCodecForLocale(localCode);

    QApplication a(argc, argv);

    // 解析参数
    CommandParameters commandParameters;
    QCommandLineOption opHelp("help");
    QCommandLineOption opStart("start");
    QCommandLineOption opCmd("command");
    QCommandLineOption opVer("version");
    QCommandLineOption opCache("cache");
    QCommandLineOption opScript("script");
    opScript.setValueName("script");

    QCommandLineParser parser;
    parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);
    parser.addOption(opHelp);
    parser.addOption(opStart);
    parser.addOption(opCmd);
    parser.addOption(opVer);
    parser.addOption(opCache);
    parser.addOption(opScript);

    parser.process(a);
    QMap<QString, QString> *params = new QMap<QString, QString>();
    // --name=value options
    if (parser.isSet(opStart)) {
        params->insert("start", "1");
    }
    if (parser.isSet(opScript)) {
        params->insert("script", parser.value(opScript));
    }
    if (parser.isSet(opCmd)) {
        params->insert("command", "1");
    }
    if (parser.isSet(opHelp)) {
        params->insert("help", "1");
    }
    if (parser.isSet(opCache)) {
        params->insert("cache", "1");
    }
    if (parser.isSet(opVer)) {
        params->insert("version", VERSION_STRING);
    }
    commandParameters.setArgs(params);

    MainWindow w;

    // 显示版本号时无视其它参数内容
    if (CommandParameters::hasVersion()) {
        printf(VERSION_STRING);
        return 0;
    }

    // 显示帮助时 无视 --command 参数值 立即显示出窗口
    if (CommandParameters::hasHelp()) {
        w.show();
        return a.exec();
    }

    // --command 参数没有时显示窗口
    if (!CommandParameters::isCommandMode()) {
        w.show();
        return a.exec();
    }

    // 命令行模式并且没有开启help
    // 进行 start 和 script 脚本执行判断
    // 如果没有脚本可执行 则立即关闭自身
    if (CommandParameters::isCommandMode() && !CommandParameters::hasHelp()) {
        // 开启命令模式时 --script 参数值为空则立即退出
        if (CommandParameters::hasScript() &&
            CommandParameters::args->value("script") == "") {
            return 0;
        }

        // 开启命令模式时 --script 参数值为空则立即退出
        if (!CommandParameters::hasScript() &&
            !CommandParameters::hasStart()) {
            a.quit();
            return 0;
        }
    }

    // 用来修补sendEvent在不显示窗口时失效问题
    // 先最小化显示再隐藏
    // show窗口之后才能开始接收GUI归属的消息
    w.showMinimized();
    w.hide();

    return a.exec();
}
