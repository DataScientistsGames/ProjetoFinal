#include "PosicaoCartesiana.hpp"

PosicaoCartesiana::PosicaoCartesiana(int x, int y) : _x(x), _y(y) {};

PosicaoCartesiana::PosicaoCartesiana() : _x(0), _y(0) {};

PosicaoCartesiana::~PosicaoCartesiana() {};

int PosicaoCartesiana::getX()
{
    return this->_x;
}

int PosicaoCartesiana::getY()
{
    return this->_y;
}

void PosicaoCartesiana::setX(int x)
{
    this->_x = x;
}

void PosicaoCartesiana::setY(int y)
{
    this->_y = y;
}