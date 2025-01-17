#ifndef TABULEIRO_H
#define TABULEIRO_H

#define CHAR_BORDA_COLUNA '|'
#define CHAR_BORDA_LINHA '-'

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
    char _charsPecas[3];

public:
    Tabuleiro(int, int, char, char);
    ~Tabuleiro();

    bool virtual posicionarPeca(int, int, int);
    int virtual finalizarJogo(); // 0 - continua, 1 - jogador 1 venceu, 2 - jogador 2 venceu, 3 - empatou
    Casa virtual localizarPeca(int, int);
    Casa stringParaCasa(const int);
    PosicaoCartesiana calculaVies(int);
    int getTipo();
    void virtual imprimeBordaVertical();
    void virtual imprimeTabuleiro();
    bool virtual temJogadaValida(Casa);
};

#endif