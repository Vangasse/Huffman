#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QString>


class FileManager
{
private:
    int *marray;
    QByteArray finalFile;
public:
    FileManager();
    ~FileManager();
    void charFrequence(QByteArray line);
    void receiveFile(QString fileName);
    int *getMarray() const;
    void setMarray(int *value);
    QByteArray getFinalFile() const;
    void setFinalFile(const QByteArray &value);
};

#endif // FILEMANAGER_H
