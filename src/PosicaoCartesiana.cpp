#include "PosicaoCartesiana.hpp"

PosicaoCartesiana::PosicaoCartesiana(double x, double y) : _x(x), _y(y) {};

PosicaoCartesiana::PosicaoCartesiana() : _x(0), _y(0) {};

PosicaoCartesiana::PosicaoCartesiana(const PosicaoCartesiana& pos) 
{
    this->_x = pos._x;
    this->_y = pos._y;
}

PosicaoCartesiana::~PosicaoCartesiana() {};

double PosicaoCartesiana::getX()
{
    return this->_x;
}

double PosicaoCartesiana::getY()
{
    return this->_y;
}

void PosicaoCartesiana::setX(double x)
{
    this->_x = x;
}

void PosicaoCartesiana::setY(double y)
{
    this->_y = y;
}