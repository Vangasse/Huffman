#include "sourdough.h"
#include <QDebug>


QString Sourdough::getEncodedTree() const
{
    return encodedTree;
}

void Sourdough::setEncodedTree(const QString &value)
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
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd()) {
        QByteArray line = file.readLine(1024);
        encodedFile += line;
    }
    file.close();
}

void Sourdough::deCoder()
{
    eTrashAndTree.append(encodedFile.at(0));
    eTrashAndTree.append(encodedFile.at(1));
    eNameSize.append(encodedFile.at(2));

    Trainee *estagiario = new Trainee();

    deTrashAndTree = estagiario->byteToBit(eTrashAndTree);

    for(int i = 0; i < 16; i++)
    {
        if(i < 3)
        {
            if(deTrashAndTree.at(i))
                deTrash.setBit(i, true);
        }
        else
        {
            if(deTrashAndTree.at(i))
                deTree.setBit(i - 3, true);
        }
    }

    deNameSize = estagiario->byteToBit(eNameSize);

    trashSize = estagiario->bitToDecimal(deTrash);
    treeSize = estagiario->bitToDecimal(deTree);
    nameSize = estagiario->bitToDecimal(deNameSize);

    for(int i = 2 + treeSize + nameSize; i < encodedFile.size(); i++)
    {
        eGold.append(encodedFile.at(i));
    }

    deGold = estagiario->byteToBit(eGold);
    deGold.resize(deGold.size() - trashSize);

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

}
