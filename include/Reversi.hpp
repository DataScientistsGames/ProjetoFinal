#ifndef REVERSI_H
#define REVERSI_H

#include <iostream>
#include "Tabuleiro.hpp"
#include "Casa.hpp"

class Reversi : public Tabuleiro
{
public:
    Reversi();
    ~Reversi();

    int finalizarJogo() override final;
    bool posicionarPeca(int, int, int) override final;
    Casa localizarPeca(int, int) override final;
};

#endif