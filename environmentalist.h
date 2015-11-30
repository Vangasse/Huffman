#ifndef ENVIRONMENTALIST_H
#define ENVIRONMENTALIST_H
#include "node.h"
#include <QList>


class Environmentalist
{
private:
    Node* root;
    Node *cursor;
    QByteArray encodedTree;

    int indice;
public:
    Environmentalist();
    ~Environmentalist();
    void plantTree(QList<Node*> list);
    void plantTree(QByteArray encodedTree);
    void plantTreeRecall(QByteArray &encodedTree, Node *pointer);
    void encodeTree(Node *ncursor);
    void encodeTree();
    Node *getRoot() const;
    void setRoot(Node *value);
    QByteArray getEncodedTree() const;
    void setEncodedTree(const QByteArray &value);
};

#endif // ENVIRONMENTALIST_H
