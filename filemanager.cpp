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

void FileManager::encodeFile(Node *cursor, unsigned char c){
    Node *aux;
    if(cursor->isLeaf()){
        if(cursor->getValue() != c)
            hash[c].remove(hash[c].size() - 1);
        return;
    }
    else{
        aux = cursor->getLeft();
        hash[c] += "0";
        encodeFile(aux, c);
        aux = cursor->getRight();
        hash[c] += "1";
        encodeFile(aux, c);
    }

}

void FileManager::encodeFile(Node *root){
    for(int i = 0; i < list.size(); i++){
        unsigned char c = list.at(i)->getValue();
        encodeFile(root, c);
        qDebug() << hash[c];
    }
}
