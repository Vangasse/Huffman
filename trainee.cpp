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
    for(int i = 0; i < work.size(); i++)
    {
        QBitArray bit(8);
        char byte;
        byte = work.at(i);
        bit = byteToBitZ(byte);
        results.setBit(i*8 + 0, bit.at(7));
        results.setBit(i*8 + 1, bit.at(6));
        results.setBit(i*8 + 2, bit.at(5));
        results.setBit(i*8 + 3, bit.at(4));
        results.setBit(i*8 + 4, bit.at(3));
        results.setBit(i*8 + 5, bit.at(2));
        results.setBit(i*8 + 6, bit.at(1));
        results.setBit(i*8 + 7, bit.at(0));
    }
    return results;
}

QBitArray Trainee::byteToBitZ(char byte){
    QBitArray bit(8);

    bit.setBit(7, 0x80&byte);
    bit.setBit(6, 0x40&byte);
    bit.setBit(5, 0x20&byte);
    bit.setBit(4, 0x10&byte);
    bit.setBit(3, 0x08&byte);
    bit.setBit(2, 0x04&byte);
    bit.setBit(1, 0x02&byte);
    bit.setBit(0, 0x01&byte);
//    qDebug() << bool(0x80&byte);
    return bit;
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
