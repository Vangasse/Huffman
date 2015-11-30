#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QString>
#include <QFile>
#include <QString>
#include "node.h"
#include <QList>
#include <QtAlgorithms>
#include <QDebug>
#include <iterator>
#include <QBitArray>
#include "trainee.h"
#include "sourdough.h"


class FileManager
{
private:
    int *marray;
    QByteArray finalFile;
    QList<Node*> list;
    bool treatNode();
    QHash<unsigned char, QBitArray> hash;

    int lixo;

    QString fileNameSav;
    int nameSize;
    QBitArray encodedNameSize;

    QBitArray encodedFinalFile;
    QBitArray encodedTrash;
    QBitArray encodedTreeSize;

public:
    FileManager();
    ~FileManager();
    void charFrequence(QByteArray line);
    void receiveFile(QString fileName);
    void charList();
    void encodeFile(Node *root);
    bool encodeFile(Node *cursor, unsigned char c, bool found);
    void createHuffFile(QByteArray encodedTree, QString ename);
    void createDepressedFile(Node *root, QBitArray deGold, QString ename);

    int *getMarray() const;
    void setMarray(int *value);
    QByteArray getFinalFile() const;
    void setFinalFile(const QByteArray &value);
    QList<Node *> getList() const;
    void setList(const QList<Node *> &value);
    void encodeCompleteFile(int treeSize);
    QString getFileNameSav() const;
    void setFileNameSav(const QString &value);
    QBitArray getEncodedNameSize() const;
    void setEncodedNameSize(const QBitArray &value);
    QBitArray getEncodedFinalFile() const;
    void setEncodedFinalFile(const QBitArray &value);
    QBitArray getEncodedTrash() const;
    void setEncodedTrash(const QBitArray &value);
    QBitArray getEncodedTreeSize() const;
    void setEncodedTreeSize(const QBitArray &value);
    int getLixo() const;
};

#endif // FILEMANAGER_H
