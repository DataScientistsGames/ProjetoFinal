#ifndef LIG4_H
#define LIG4_H

#include <iostream>
#include "Tabuleiro.hpp"
#include "Casa.hpp"

class Lig4 : public Tabuleiro
{
public:
    Lig4(int, int);
    ~Lig4();

    void posicionarPeca(int, int, int) override final;
    Casa localizarPeca(int, int) override final;
};

#endif