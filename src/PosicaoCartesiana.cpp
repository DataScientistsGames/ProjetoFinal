#include "PosicaoCartesiana.hpp"

PosicaoCartesiana::PosicaoCartesiana(int x = 0, int y = 0) : _x{x},
                                                             _y{y}
{
}

PosicaoCartesiana::getX()
{
    return this._x;
}

PosicaoCartesiana::getY()
{
    return this._y;
}

PosicaoCartesiana::setX(int x)
{
    return this._x;
}

PosicaoCartesiana::setY(int y)
{
    return this._y;
}