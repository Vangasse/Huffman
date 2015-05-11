#include <QCoreApplication>
#include "filemanager.h"
#include <QDebug>

int main(/*int argc, char *argv[]*/)
{
    //QCoreApplication app(argc, argv);
    FileManager *huffman = new FileManager();

    huffman->receiveFile("test.txt");
    qDebug() << huffman->getFinalFile();

    int *array = huffman->getMarray();
    for(int i = 0; i < 256; i++){
        if(array[i] != 0)
            qDebug() << array[i] << ' ' << i;
    }

    return 0;//app.exec();
}
