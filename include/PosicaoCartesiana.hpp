#ifndef POSCARTESIANA_H
#define POSCARTESIANA_H

class PosicaoCartesiana
{
private:
    int _x, _y;

public:
    PosicaoCartesiana(int x = 0, int y = 0);
    ~PosicaoCartesiana();

    int getX();
    int setX();

    int getY();
    int setY();
};

#endif