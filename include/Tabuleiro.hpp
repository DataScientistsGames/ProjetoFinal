#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <iostream>
#include "Casa.hpp"
#include "PosicaoCartesiana.hpp"

class Tabuleiro
{
protected:
    Casa **_board;
    int _x;
    int _y;
    int _tipo; // 0 - velha, 1 - reversi, 2 - lig4

public:
    Tabuleiro(int, int);
    ~Tabuleiro();

    void virtual posicionarPeca(int, int, int);
    int virtual finalizarJogo(); // 0 - continua, 1 - jogador 1 venceu, 2 - jogador 2 venceu
    Casa virtual localizarPeca(int, int);
    Casa stringParaCasa(const int);
    PosicaoCartesiana calculaVies(int);
    int getTipo();
};

#endif