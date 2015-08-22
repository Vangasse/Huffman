#include "trainee.h"
#include <QDebug>

Trainee::Trainee()
{

}

Trainee::~Trainee()
{

}

int correction(int num)
{
    while(num < 0)
        num = num + 8;
    return num;
}


QByteArray Trainee::bitToByte(QBitArray work) //FUNÇAO DO MATHEUS
{
//    qDebug() << "START" << endl;
    QByteArray results;
    results.resize(work.count()/8);
    results.fill(0);
    for(int i = 0; i < work.count(); ++i)
    {
        results[i/8] = (results.at(i/8) | ((work[i]?1:0)<< correction(7-i)%8));
//        qDebug() << i << results;
//        qDebug() << endl;
    }
    return results;
}

QBitArray Trainee::byteToBit(QByteArray work)
{
    QBitArray results;
    results.resize(8*work.size());
    int tam = (8*work.size()) - 1;
    for(int i = work.size() - 1; i >= 0; i--)
    {
        int step = work.at(i);
        while(step){
            if(step % 2)
                results.setBit(tam, true);
            tam--;
            step /= 2;
        }
    }
    return results;
}

int Trainee::bitToDecimal(QBitArray work)
{
    int results = 0;

    for(int i = 0; i < work.size(); i++)
    {
        if(work.at(i))
            results = results*2 + 1;
        else
            results *= 2;
    }
    return results;
}
