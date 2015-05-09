#include <QCoreApplication>
#include "filemanager.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    FileManager *huffman = new FileManager();
    return app.exec();
}
