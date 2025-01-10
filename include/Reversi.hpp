#ifndef REVERSI_H
#define REVERSI_H

#include <iostream>
#include "Tabuleiro.hpp"
#include "Casa.hpp"

class Reversi : public Tabuleiro
{
public:
    Reversi(int, int);
    ~Reversi();

    void posicionarPeca(int, int, int) override final;
    Casa localizarPeca(int, int) override final;
};

#endif