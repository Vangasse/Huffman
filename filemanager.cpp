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

QString FileManager::getFileNameSav() const
{
    return fileNameSav;
}

void FileManager::setFileNameSav(const QString &value)
{
    fileNameSav = value;
}

QBitArray FileManager::getEncodedNameSize() const
{
    return encodedNameSize;
}

void FileManager::setEncodedNameSize(const QBitArray &value)
{
    encodedNameSize = value;
}

QBitArray FileManager::getEncodedFinalFile() const
{
    return encodedFinalFile;
}

void FileManager::setEncodedFinalFile(const QBitArray &value)
{
    encodedFinalFile = value;
}

QBitArray FileManager::getEncodedTrash() const
{
    return encodedTrash;
}

void FileManager::setEncodedTrash(const QBitArray &value)
{
    encodedTrash = value;
}

QBitArray FileManager::getEncodedTreeSize() const
{
    return encodedTreeSize;
}

void FileManager::setEncodedTreeSize(const QBitArray &value)
{
    encodedTreeSize = value;
}
FileManager::FileManager()
{
    marray = new int[256];
    for(int i = 0; i < 256; i++){
        marray[i] = 0;
    }
    finalFile = "";
}

FileManager::~FileManager()
{

}

void FileManager::receiveFile(QString fileName){
    fileNameSav = fileName;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd()) {
        QByteArray line = file.readLine(1024);
        charFrequence(line);
        finalFile += line;
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
    int new_bit;
    if(cursor->isLeaf()){
        if(cursor->getValue() != c){
            hash[c].resize(hash[c].size() - 1);
            return false;
        }
        else{
            return true;
        }
    }
    else{
        aux = cursor->getLeft();
        new_bit = hash[c].size();
        hash[c].resize(new_bit + 1);
        found = encodeFile(aux, c, false);
        if(!(found)){
            aux = cursor->getRight();
            new_bit = hash[c].size();
            hash[c].resize(new_bit + 1);
            hash[c].setBit(new_bit, true);
            found = encodeFile(aux, c, false);
        }
    }

    if(!(found)){
        if(hash[c].size() == 1)
            hash[c].clear();
        else
            hash[c].resize(hash[c].size() - 1);
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

void FileManager::encodeCompleteFile(int treeSize){
    int countDigits;
    for(QByteArray::iterator it = finalFile.begin(); it != finalFile.end(); it++)
    {
        int array_size = hash[*it].size();
        for(int i = 0; i < array_size; i++)
        {
            encodedFinalFile.resize(encodedFinalFile.size() + 1);
            if(hash[*it].at(i) == true)
            {
                encodedFinalFile.setBit(encodedFinalFile.size() - 1, true);
            }
        }
    }

    //CALCULA LIXO
    countDigits = encodedFinalFile.size() % 8;
    lixo = 8 - countDigits;

    if(lixo == 8)lixo = 0;

    for(int i = 0; i < lixo; i++)
        encodedFinalFile.resize(encodedFinalFile.size() + 1);

    int tam;
    //TAMANHO DO NOME
    encodedNameSize.resize(8);
    tam = 7;
    nameSize = fileNameSav.size();
    while(nameSize){
        if(nameSize % 2)
            encodedNameSize.setBit(tam, true);
        tam--;
        nameSize /= 2;
    }

    //TAMANHO DA ARVORE
    encodedTreeSize.resize(13);
    tam = 12;
    while(treeSize){
        if(treeSize % 2)
            encodedTreeSize.setBit(tam, true);
        tam--;
        treeSize /= 2;
    }

    //TAMANHO DO LIXO NO INICIO DO ARQUIVO
    encodedTrash.resize(3);
    switch (lixo) {
    case 1:
        encodedTrash.setBit(0, false);
        encodedTrash.setBit(1, false);
        encodedTrash.setBit(2, true);
        break;
    case 2:
        encodedTrash.setBit(0, false);
        encodedTrash.setBit(1, true);
        encodedTrash.setBit(2, false);
        break;
    case 3:
        encodedTrash.setBit(0, false);
        encodedTrash.setBit(1, true);
        encodedTrash.setBit(2, true);
        break;
    case 4:
        encodedTrash.setBit(0, true);
        encodedTrash.setBit(1, false);
        encodedTrash.setBit(2, false);
        break;
    case 5:
        encodedTrash.setBit(0, true);
        encodedTrash.setBit(1, false);
        encodedTrash.setBit(2, true);
        break;
    case 6:
        encodedTrash.setBit(0, true);
        encodedTrash.setBit(1, true);
        encodedTrash.setBit(2, false);
        break;
    case 7:
        encodedTrash.setBit(0, true);
        encodedTrash.setBit(1, true);
        encodedTrash.setBit(2, true);
        break;
    }

}

void FileManager::createHuffFile(QString encodedTree)
{
    QFile huffFile("test.huff");
    Trainee jefferson;

    huffFile.open(QIODevice::WriteOnly);

    QTextStream out(&huffFile);

    QBitArray aux;

    aux = encodedTrash;

    for(int i = 0; i < 13; i++)
    {
        aux.resize(aux.size() + 1);
        if(encodedTreeSize.at(i))
            aux.setBit(aux.size() - 1, true);
    }

    qDebug() << aux;

    out << jefferson.bitToByte(aux);
    out << jefferson.bitToByte(encodedNameSize);
    out << fileNameSav << encodedTree;
    out << jefferson.bitToByte(encodedFinalFile);

    huffFile.close();
}
