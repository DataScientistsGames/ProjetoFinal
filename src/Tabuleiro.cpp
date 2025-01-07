#include "Tabuleiro.hpp"
#include "Casa.hpp"
#include <iostream>

Tabuleiro::Tabuleiro(int x, int y)
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
    for (const auto &linhas : this->_board)
        delete[] linhas;
    delete[] this->_board;
}

void Tabuleiro::posicionarPeca(int x, int y, int num_jogador = 0)
{
    this->_board[x][y] = num_jogador;
}

Casa Tabuleiro::localizarPeca(int, int)
{
    return this->_board[x][y];
}
