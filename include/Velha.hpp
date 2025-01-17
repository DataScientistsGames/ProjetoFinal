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
    void imprimeTabuleiro() override final;
};

#endif