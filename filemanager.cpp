#include "filemanager.h"
#include <cstring>
#include <QFile>
#include <QString>


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
        finalFile += line;
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


