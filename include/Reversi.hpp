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
    void posicionarPeca(int, int, int) override final; // acho que n precisa de override e final junto, só override já funciona
    void imprimeBordaVertical() override final;        // parece que 'override final' é redundante
    Casa localizarPeca(int, int) override final;
};

#endif