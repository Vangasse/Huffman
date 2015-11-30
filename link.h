#ifndef LINK_H
#define LINK_H

#include <QString>
#include <QObject>

class Link : public QObject
{
    Q_OBJECT
public:
    Link(QObject *parent);
    Q_INVOKABLE void startCompression(QString iname, QString ename);
    Q_INVOKABLE void startDeCom(QString origin);
    Q_INVOKABLE void startDeCom(QString origin, QString deEnd);
};

#endif // LINK_H
