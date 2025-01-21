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

    // metodos exclusivo do reversi por causa da complexidade das regras
    bool temJogadaValida(Casa);
    bool jogadaValida(int, int, Casa, bool);
    void imprimeTabuleiro() override final;
};

#endif