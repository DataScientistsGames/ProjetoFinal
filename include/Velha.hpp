#ifndef VELHA_H
#define VELHA_H

#include <iostream>
#include "Tabuleiro.hpp"
#include "Casa.hpp"

class Velha : public Tabuleiro
{
public:
    Velha(int, int);
    ~Velha();

    void posicionarPeca(int, int, int) override final;
    Casa localizarPeca(int, int) override final;
};

#endif