#include "trainee.h"
#include <QDebug>

Trainee::Trainee()
{

}

Trainee::~Trainee()
{

}

QByteArray Trainee::bitToByte(QBitArray work) //FUNÇAO DO MATHEUS
{
    qDebug() << "START" << endl;
    QByteArray results;
    results.resize(work.count()/8);
    results.fill(0);
    for(int i = 0; i < work.count(); ++i)
    {
        results[i/8] = (results.at(i/8) | ((work[i]?1:0)<<(i%8)));
        qDebug() << i << results;
        qDebug() << endl;
    }
    return results;
}
