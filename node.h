#ifndef NODE_H
#define NODE_H
#include<QDebug>


class Node
{
private:
    unsigned char value;
    QByteArray element;
    int number;
    Node *left;
    Node *right;
public:
    Node(unsigned char value, int number);
    Node(QByteArray value);
    ~Node();
    bool isLeaf();

    unsigned char getValue() const;
    void setValue(unsigned char value);
    QByteArray getElement() const;
    void setElement(QByteArray element);
    int getNumber() const;
    void setNumber(int value);
    Node *getLeft() const;
    void setLeft(Node *value);
    Node *getRight() const;
    void setRight(Node *value);
};

#endif // NODE_H
