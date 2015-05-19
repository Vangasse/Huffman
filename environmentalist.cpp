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
Environmentalist::Environmentalist()
{
    root = 0;
    cursor = 0;
    encodedTree = "*";
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

}

void Environmentalist::encodeTree(){
/*    cursor = root->getLeft();
    if(cursor->isLeaf()){
        encodedTree += cursor->getValue();
    }
    else{
        encodedTree += '*';
        encodeTree(cursor);
    }
    cursor = root->getRight();
*/
}
