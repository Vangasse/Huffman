#include "filemanager.h"
#include <cstring>
#include <QFile>
#include <QTextStream>
#include <QString>

FileManager::FileManager()
{
    memset(marray, 0, 256); //TESTE marray[] = {0};
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


