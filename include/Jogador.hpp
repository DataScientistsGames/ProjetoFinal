#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include "PosicaoCartesiana.hpp"

class Jogador
{
private:
    std::string _apelido, _nome;
    int _vitorias_velha, _derrotas_velha;
    int _vitorias_reversi, _derrotas_reversi;
    int _vitorias_lig, _derrotas_lig;
    PosicaoCartesiana _vies;

public:
    Jogador(std::string);
    ~Jogador();

    std::string getApelido();
    std::string getNome();
    int getVitoriasV();
    int getDerrotasV();
    int getVitoriasR();
    int getDerrotasR();
    int getVitoriasL();
    int getDerrotasL();
};

#endif