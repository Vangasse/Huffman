#ifndef NODE_H
#define NODE_H
#include<QDebug>


class Node
{
private:
    unsigned char value;
    int number;
    Node *left;
    Node *right;
public:
    Node(unsigned char value, int number);
    ~Node();
    bool isLeaf();

    unsigned char getValue() const;
    void setValue(unsigned char value);
    int getNumber() const;
    void setNumber(int value);
    Node *getLeft() const;
    void setLeft(Node *value);
    Node *getRight() const;
    void setRight(Node *value);
};

#endif // NODE_H
