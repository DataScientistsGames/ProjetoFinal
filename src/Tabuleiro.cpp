#include "Tabuleiro.hpp"
#include "Casa.hpp"
#include <iostream>

Tabuleiro::Tabuleiro(int x, int y) : _x(x), _y(y)
{
    this->_board = new Casa *[x];
    for (int i = 0; i < x; ++i)
    {
        this->_board[i] = new Casa[y];
        for (int j = 0; j < y; j++)
        {
            this->_board[i][j] = VAZIO;
        }
    }
}

Tabuleiro::~Tabuleiro()
{
    for (int i = 0; i < this->_x; i++)
    {
        delete[] (this->_board[i]);
    }
    delete[] this->_board;
}

int Tabuleiro::finalizarJogo() { return 1; };

void Tabuleiro::posicionarPeca(int x, int y, int num_jogador = 0)
{
    this->_board[x][y] = stringParaCasa(num_jogador);
}

Casa Tabuleiro::localizarPeca(int x, int y)
{
    return this->_board[x][y];
}

Casa Tabuleiro::stringParaCasa(const int num_jogador)
{
    switch (num_jogador)
    {
    case 1:
        return JOGADOR_1;
        break;

    case 2:
        return JOGADOR_2;
        break;

    default:
        return VAZIO;
        break;
    }
}

PosicaoCartesiana Tabuleiro::calculaVies(int jogador)
{
    return PosicaoCartesiana(0, 0);
}

int Tabuleiro::getTipo()
{
    return this->_tipo;
}