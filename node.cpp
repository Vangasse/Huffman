#include "node.h"


unsigned char Node::getValue() const
{
    return value;
}

void Node::setValue(unsigned char value)
{
    this->value = value;
}

QByteArray Node::getElement() const
{
    return element;
}

void Node::setElement(QByteArray element)
{
    this->element = element;
}

int Node::getNumber() const
{
    return number;
}

void Node::setNumber(int value)
{
    number = value;
}

Node *Node::getLeft() const
{
    return left;
}

void Node::setLeft(Node *value)
{
    left = value;
}

Node *Node::getRight() const
{
    return right;
}

void Node::setRight(Node *value)
{
    right = value;
}
Node::Node(unsigned char value, int number)
{
    this->value = value;
    this->number = number;
    this->left = 0;
    this->right = 0;
}

Node::Node(QByteArray element)
{
    this->element = element;
    this->left = 0;
    this->right = 0;
}

Node::~Node()
{

}

bool Node::isLeaf(){
    if(left == 0 && right == 0){
        return true;
    }
    return false;
}
