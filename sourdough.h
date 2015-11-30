#ifndef SOURDOUGH_H
#define SOURDOUGH_H
#include <QString>
#include <QFile>
#include "trainee.h"


class Sourdough
{
private:
    QByteArray encodedFile;
    QByteArray eTrashAndTree;
    QByteArray eNameSize;
    QByteArray eGold;

    QBitArray deTrashAndTree;
    QBitArray deTrash;
    QBitArray deTree;
    QBitArray deNameSize;
    QBitArray deGold;

    QString name;
    QByteArray encodedTree;

    int trashSize;
    int treeSize;
    int nameSize;

public:
    Sourdough();
    ~Sourdough();
    void receiveFile(QString fileName);
    void deCoder();
    QByteArray getEncodedTree() const;
    void setEncodedTree(const QByteArray &value);
    int getTrashSize() const;
    void setTrashSize(int value);
    QBitArray getDeGold() const;

    QString getName() const;
    void setName(const QString &value);
};

#endif // SOURDOUGH_H
