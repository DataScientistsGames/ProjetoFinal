#ifndef JOGADOR_H
#define JOGADORA_H

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
    bool _cor_atual;

public:
    Jogador(std::string, bool);
    ~Jogador();
};

#endif