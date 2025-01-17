#ifndef LIG4_H
#define LIG4_H

#include <iostream>
#include "Tabuleiro.hpp"
#include "Casa.hpp"

class Lig4 : public Tabuleiro
{
public:
    Lig4();
    ~Lig4();

    int finalizarJogo() override final;
    bool posicionarPeca(int, int, int) override final;
};

#endif