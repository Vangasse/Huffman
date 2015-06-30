#include "environmentalist.h"

bool lessThan(Node *a, Node *b){
    bool min;

    min = false;

    if(a->getNumber() < b->getNumber())
        min = true;
    else if( a->getNumber() == b->getNumber() && a->getValue() < b->getValue())
        min = true;
    return min;
}


Node *Environmentalist::getRoot() const
{
    return root;
}

void Environmentalist::setRoot(Node *value)
{
    root = value;
}

QString Environmentalist::getEncodedTree() const
{
    return encodedTree;
}

void Environmentalist::setEncodedTree(const QString &value)
{
    encodedTree = value;
}
Environmentalist::Environmentalist()
{
    root = 0;
    cursor = 0;
    encodedTree = "";
}

Environmentalist::~Environmentalist()
{

}

void Environmentalist::plantTree(QList<Node*> list){
    int i = list.size();
    while(i > 1){
        qSort(list.begin(), list.end(), lessThan);
        for(int j = 0; j < list.size(); j++){
            qDebug() << j << ' ' << list.at(j)->getNumber();
        }
        qDebug() << "\n";
        Node *beren = new Node(0, list.at(0)->getNumber() + list.at(1)->getNumber());
        beren->setLeft(list.at(0));
        beren->setRight(list.at(1));
        list.removeAt(0);
        list.removeAt(0);
        list.prepend(beren);
        i--;
        for(int j = 0; j < list.size(); j++){
            qDebug() << j << ' ' << list.at(j)->getNumber();
        }
        qDebug() << "\n";

    }

    root = list.at(0);

}

void Environmentalist::encodeTree(Node *ncursor){
    qDebug() << ncursor->getValue() << " " << ncursor->getNumber() << endl;

    if(ncursor->getLeft()->isLeaf()){
        if(ncursor->getLeft()->getValue() == '(')
            encodedTree += "*(";
        else if(ncursor->getLeft()->getValue() == '*')
            encodedTree += "**";
        else
            encodedTree += ncursor->getLeft()->getValue();
        qDebug() << ncursor->getLeft()->getValue() << " " << ncursor->getLeft()->getNumber() << endl;
    }
    else{
        encodedTree += "(";
        encodeTree(ncursor->getLeft());
    }
    if(ncursor->getRight()->isLeaf()){
        if(ncursor->getRight()->getValue() == '(')
            encodedTree += "*(";
        else if(ncursor->getRight()->getValue() == '*')
            encodedTree += "**";
        else
            encodedTree += ncursor->getRight()->getValue();
            qDebug() << ncursor->getRight()->getValue() << " " << ncursor->getRight()->getNumber() << endl;
    }
    else{
        encodedTree += "(";
        encodeTree(ncursor->getRight());
    }
}

void Environmentalist::encodeTree(){
    //Caractere identificador *
    //Caractere de nó (


    if(root->isLeaf())
        encodedTree += root->getValue();
    else{
        encodedTree += "(";
        encodeTree(root);
    }
}
