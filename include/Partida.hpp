#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include "CSV.hpp"
#include "Jogador.hpp"
#include "PosicaoCartesiana.hpp"

class Partida
{
private:
    Jogador *_player1;
    Jogador *_player2;
    int _rounds;

public:
    Partida(Jogador &, Jogador &);
    ~Partida();

    void round();
    PosicaoCartesiana leitorJogada();
    void finalizarPartida();
    void atualizaDados(std::string, std::string, PosicaoCartesiana);
};

#endif