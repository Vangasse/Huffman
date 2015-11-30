#include "link.h"
#include <QCoreApplication>
#include "filemanager.h"
#include "environmentalist.h"
#include "sourdough.h"
#include <QDebug>

Link::Link(QObject *parent) : QObject(parent)
{
}

void Link::startCompression(QString iname, QString ename)
{
    FileManager *huffman = new FileManager();
    Environmentalist *businesMan = new Environmentalist();

    huffman->receiveFile(iname);

    businesMan->plantTree(huffman->getList());

    huffman->encodeFile(businesMan->getRoot());

    businesMan->encodeTree();

    huffman->encodeCompleteFile(businesMan->getEncodedTree().size());

    if(ename.isEmpty())
    {
        int i = 0;
        while(iname.at(i) != '.')
        {
            ename += iname.at(i);
            i++;
        }
        ename += ".huff";
    }

    qDebug() << businesMan->getEncodedTree().size();
    qDebug() << businesMan->getEncodedTree();
    qDebug() << huffman->getLixo();

    huffman->createHuffFile(businesMan->getEncodedTree(), ename);
}

void Link::startDeCom(QString origin)
{
    FileManager *huffman = new FileManager();
    Environmentalist *businesMan = new Environmentalist();
    Sourdough *garimpeiro = new Sourdough();

    garimpeiro->receiveFile(origin);
    garimpeiro->deCoder();

    businesMan->plantTree(garimpeiro->getEncodedTree());

    huffman->createDepressedFile(businesMan->getRoot(), garimpeiro->getDeGold(), garimpeiro->getName());
}

void Link::startDeCom(QString origin, QString deEnd)
{
    FileManager *huffman = new FileManager();
    Environmentalist *businesMan = new Environmentalist();
    Sourdough *garimpeiro = new Sourdough();


    garimpeiro->receiveFile(origin);
    garimpeiro->deCoder();

    businesMan->plantTree(garimpeiro->getEncodedTree());

    huffman->createDepressedFile(businesMan->getRoot(), garimpeiro->getDeGold(), deEnd);
}
