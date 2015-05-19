#include "filemanager.h"


int *FileManager::getMarray() const
{
    return marray;
}

void FileManager::setMarray(int *value)
{
    marray = value;
}

QByteArray FileManager::getFinalFile() const
{
    return finalFile;
}

void FileManager::setFinalFile(const QByteArray &value)
{
    finalFile = value;
}

QList<Node *> FileManager::getList() const
{
    return list;
}

void FileManager::setList(const QList<Node *> &value)
{
    list = value;
}
FileManager::FileManager()
{
    marray = new int[256];
    for(int i = 0; i < 256; i++){
        marray[i] = 0;
    }
}

FileManager::~FileManager()
{

}

void FileManager::receiveFile(QString fileName){
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd()) {
        QByteArray line = file.readLine(1024);
        charFrequence(line);
    }
    file.close();
}

void FileManager::charFrequence(QByteArray line){
    unsigned char c;

    for(int i = 0; i < line.size(); i++){
        c = (unsigned char)line[i];
        marray[c]++;
    }

}

void FileManager::charList(){
    for(int i = 0; i < 256; i++){
        if(marray[i] > 0){
            Node *aux = new Node(i,marray[i]);
            list.append(aux);
        }
    }
}

bool FileManager::encodeFile(Node *cursor, unsigned char c, bool found){
    Node *aux;
    if(cursor->isLeaf()){
        if(cursor->getValue() != c){
            hash[c].remove(hash[c].size() - 1, hash[c].size() - 1);
            return false;
        }
        else{
            return true;
        }
    }
    else{
        aux = cursor->getLeft();
        hash[c] += "0";
        found = encodeFile(aux, c, false);
        if(!(found)){
            aux = cursor->getRight();
            hash[c] += "1";
            found = encodeFile(aux, c, false);
        }
    }

    if(!(found)){
        if(hash[c].size() == 1)
            hash[c] = "";
        else
            hash[c].remove(hash[c].size() - 1, hash[c].size() - 1);
    }

    return found;

}

void printTree(Node* root){
    if(root->isLeaf()){
        qDebug() << ">>" << root->getValue() << ' ' << root->getNumber();
        return;
    }
    printTree(root->getLeft());
    printTree(root->getRight());
}

void FileManager::encodeFile(Node *root){
    for(int i = 0; i < list.size(); i++){
        unsigned char c = list.at(i)->getValue();
        encodeFile(root, c, false);
        qDebug() << hash[c] << ' ' << c << ' ' << list.at(i)->getNumber();
    }
    printTree(root);
}
