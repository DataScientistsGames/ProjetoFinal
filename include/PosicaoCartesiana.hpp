#ifndef POSCARTESIANA_H
#define POSCARTESIANA_H

class PosicaoCartesiana
{
private:
    int _x, _y;

public:

    PosicaoCartesiana(int x, int y);
    PosicaoCartesiana();
    ~PosicaoCartesiana();

    int getX();
    int getY();

    void setX(int);
    void setY(int);
};

#endif