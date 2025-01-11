#ifndef VELHA_H
#define VELHA_H

#include <iostream>
#include "Tabuleiro.hpp"
#include "Casa.hpp"

class Velha : public Tabuleiro
{
public:
    Velha();
    ~Velha();

    int finalizarJogo() override final;
    void posicionarPeca(int, int, int) override final; // eu acho que override e final juntos é redundante, mas posso estar louco
    Casa localizarPeca(int, int) override final;
};

#endif