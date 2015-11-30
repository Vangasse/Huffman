#include "sourdough.h"
#include <QDebug>


QByteArray Sourdough::getEncodedTree() const
{
    return encodedTree;
}

void Sourdough::setEncodedTree(const QByteArray &value)
{
    encodedTree = value;
}

int Sourdough::getTrashSize() const
{
    return trashSize;
}

void Sourdough::setTrashSize(int value)
{
    trashSize = value;
}

QBitArray Sourdough::getDeGold() const
{
    return deGold;
}

QString Sourdough::getName() const
{
    return name;
}

void Sourdough::setName(const QString &value)
{
    name = value;
}

Sourdough::Sourdough()
{
    encodedFile = "";
    eTrashAndTree = "";
    eNameSize = "";
    
    deTrash.resize(3);
    deTree.resize(13);

    name = "";
    encodedTree = "";
}

Sourdough::~Sourdough()
{

}

void Sourdough::receiveFile(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        return;

//    while (!file.atEnd()) {
//        QByteArray line = file.readLine(1024);
//        encodedFile.append(line);
//        qDebug() << encodedFile;
//    }
    this->encodedFile = file.readAll();
    qDebug() << qPrintable(this->encodedFile);

    //    qDebug() << encodedFile.size();
    //    for(int i = 0; i < total.size(); i++)
    //    {
    //        unsigned int mango = total.at(i);
    //        qDebug() << total.at(i) << " " << mango;
    //    }
    //    qDebug() << endl;

    file.close();
}

void Sourdough::deCoder()
{
    eTrashAndTree.append(encodedFile.at(0));
    eTrashAndTree.append(encodedFile.at(1));
    eNameSize.append(encodedFile.at(2));

    Trainee *estagiario = new Trainee();

    deTrashAndTree = estagiario->byteToBit(eTrashAndTree);

    for(int i = 0; i < 16; i++){
        if(i < 3){
            if(deTrashAndTree.at(i))
                deTrash.setBit(i, true);
        }
        else{
            if(deTrashAndTree.at(i))
                deTree.setBit(i - 3, true);
        }
    }

    deNameSize = estagiario->byteToBit(eNameSize);
    trashSize = estagiario->bitToDecimal(deTrash);
    treeSize = estagiario->bitToDecimal(deTree);
    nameSize = estagiario->bitToDecimal(deNameSize);

//    qDebug() << trashSize << endl
//                << treeSize << endl
//                << nameSize << endl;


    for(int i = 3 + treeSize + nameSize; i < encodedFile.size(); i++)
    {
        eGold.append(encodedFile.at(i));
    }

    deGold = estagiario->byteToBit(eGold);
//    qDebug() << deGold.size() << "<<";
    deGold.resize(deGold.size() - trashSize);
//    qDebug() << deGold.size() << "<<";

    //    qDebug() << eGold.size();
        qDebug() << deGold;

    //Pegando nome e arvore codificada
    for(int i = 3; i < 3 + nameSize + treeSize; i++)
    {
        if(i < 3 + nameSize)
        {
            name += encodedFile.at(i);
        }
        else
        {
            encodedTree += encodedFile.at(i);
        }
    }
    qDebug() << encodedTree
             << treeSize
             << nameSize
             << name
             << trashSize;

}
