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

    int finalizarJogo() override final;                // acho que n precisa de override e final junto, só override já funciona
    bool posicionarPeca(int, int, int) override final; // parece que 'override final' é redundante

    // metodos exclusivo do reversi por causa da complexidade das regras
    bool temJogadaValida(Casa);
    bool jogadaValida(int, int, Casa, bool);
};

#endif