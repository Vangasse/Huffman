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
    QString encodedTree;

    int trashSize;
    int treeSize;
    int nameSize;

public:
    Sourdough();
    ~Sourdough();
    void receiveFile(QString fileName);
    void deCoder();
    QString getEncodedTree() const;
    void setEncodedTree(const QString &value);
    int getTrashSize() const;
    void setTrashSize(int value);
};

#endif // SOURDOUGH_H
