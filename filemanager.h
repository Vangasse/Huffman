#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QString>


class FileManager
{
private:
    int marray[256];
public:
    FileManager();
    ~FileManager();
    void charFrequence(QByteArray line);
    void receiveFile(QString fileName);
};

#endif // FILEMANAGER_H
