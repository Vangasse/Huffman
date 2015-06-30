#ifndef ENVIRONMENTALIST_H
#define ENVIRONMENTALIST_H
#include "node.h"
#include <QList>


class Environmentalist
{
private:
    Node* root;
    Node *cursor;
    QString encodedTree;
public:
    Environmentalist();
    ~Environmentalist();
    void plantTree(QList<Node*> list);
    void encodeTree(Node *ncursor);
    void encodeTree();
    Node *getRoot() const;
    void setRoot(Node *value);
    QString getEncodedTree() const;
    void setEncodedTree(const QString &value);
};

#endif // ENVIRONMENTALIST_H
