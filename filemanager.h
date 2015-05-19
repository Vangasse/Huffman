#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QString>
#include <QFile>
#include <QString>
#include "node.h"
#include <QList>
#include <QtAlgorithms>
#include <QDebug>


class FileManager
{
private:
    int *marray;
    QByteArray finalFile;
    QList<Node*> list;
    bool treatNode();
    QHash<unsigned char, QString> hash;
public:
    FileManager();
    ~FileManager();
    void charFrequence(QByteArray line);
    void receiveFile(QString fileName);
    void charList();
    void encodeFile(Node *root);
    void encodeFile(Node *cursor, unsigned char c);
    int *getMarray() const;
    void setMarray(int *value);
    QByteArray getFinalFile() const;
    void setFinalFile(const QByteArray &value);
    QList<Node *> getList() const;
    void setList(const QList<Node *> &value);
};

#endif // FILEMANAGER_H
