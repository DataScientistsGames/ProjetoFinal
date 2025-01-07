#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <iostream>
#include "Casa.hpp"

class Tabuleiro
{
private:
    Casa **_board;

public:
    Tabuleiro(int, int);
    ~Tabuleiro();

    void posicionarPeca(int, int, int);
    Casa localizarPeca(int, int);
};

#endif