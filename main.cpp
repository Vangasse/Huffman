#include <QCoreApplication>
#include "filemanager.h"
#include "environmentalist.h"
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

    huffman->charList();

    QList<Node*> list = huffman->getList();

    for(int i = 0; i < list.size(); i++){
        qDebug() << list.at(i)->getValue();
        qDebug() << list.at(i)->getNumber();
    }

    Environmentalist *businesMan = new Environmentalist();

    businesMan->plantTree(list);

    for(int i = 0; i < list.size(); i++){
        qDebug() << list.at(i)->getValue() << ' ' << list.at(i)->getNumber();
    }

    huffman->encodeFile(businesMan->getRoot());
    
    businesMan->encodeTree();

    qDebug() << businesMan->getEncodedTree() << endl;

    huffman->encodeCompleteFile(businesMan->getEncodedTree().size());

    qDebug() << huffman->getEncodedTrash();
    qDebug() << huffman->getEncodedTreeSize();
    qDebug() << huffman->getEncodedNameSize();
    qDebug() << huffman->getFileNameSav();
    qDebug() << businesMan->getEncodedTree();
    qDebug() << huffman->getEncodedFinalFile();

    huffman->createHuffFile(businesMan->getEncodedTree());

    return 0;//app.exec();
}
