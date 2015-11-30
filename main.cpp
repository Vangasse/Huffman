#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include "link.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QGuiApplication::setApplicationName("Huffman");
    QGuiApplication::setApplicationVersion("A ULTIMA");

    QQmlApplicationEngine engine;
    QQmlContext *interpreter = engine.rootContext();

    QCommandLineParser parser;

    parser.addHelpOption();
    parser.addVersionOption();
    parser.setApplicationDescription("Parser significa analisador");
    parser.addPositionalArgument("file.x", QCoreApplication::translate("main", "original file"));
    parser.addPositionalArgument("file.huff", QCoreApplication::translate("main", "final file"));
    parser.addPositionalArgument("local", QCoreApplication::translate("main", "final adress"));

    QCommandLineOption compress("c",QCoreApplication::translate("main","compress file.x."),
                                QCoreApplication::translate("main","file.x"));
    parser.addOption(compress);
    QCommandLineOption out("o",QCoreApplication::translate("main","save as file.huff."),
                               QCoreApplication::translate("main","file.huff"));
    parser.addOption(out);
    QCommandLineOption local("d",QCoreApplication::translate("main","put it in local."),
                             QCoreApplication::translate("main","local"));
    parser.addOption(local);
    QCommandLineOption startGui("gui", QCoreApplication::translate("main", "start gui."));
    parser.addOption(startGui);
    parser.process(app);

    Link huff(&app);

    if(parser.isSet(compress))
        {
            huff.startCompression(parser.value(compress), parser.value(out));
            exit(0);
        }
        else if(parser.isSet(startGui))
        {
            interpreter->setContextProperty("_huffman", &huff);
            engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
        }
        else
        {
            if(app.arguments().size() == 1)
                    qDebug() << qPrintable(parser.helpText());
                else if(parser.isSet(local))
                    huff.startDeCom(app.arguments().at(1),parser.value(local));
                else
                    huff.startDeCom(app.arguments().at(1));
        }

    return app.exec();
}

