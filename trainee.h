#ifndef TRAINEE_H
#define TRAINEE_H
#include <QByteArray>
#include <QBitArray>


class Trainee
{
public:
    Trainee();
    ~Trainee();
    QByteArray bitToByte(QBitArray work);
    QBitArray byteToBit(QByteArray work);
    QBitArray byteToBitZ(char byte);
    int bitToDecimal(QBitArray work);
};

#endif // TRAINEE_H
