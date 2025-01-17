#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <memory>
#include "CSV.hpp"
#include "Jogador.hpp"
#include "Tabuleiro.hpp"
#include "PosicaoCartesiana.hpp"

class Partida
{
private:
    std::unique_ptr<Jogador> _player1;
    std::unique_ptr<Jogador> _player2;
    std::unique_ptr<Tabuleiro> _tabuleiro;
    int _rounds;

public:
    Partida(std::unique_ptr<Tabuleiro>, std::unique_ptr<Jogador>, std::unique_ptr<Jogador>);
    ~Partida();

    void round();
    void leitorJogada(int);
    void finalizarPartida(int);
    void atualizaDadosJogador(std::unique_ptr<Jogador>, std::unique_ptr<Jogador>);
    void atualizaDadosPartida(std::unique_ptr<Jogador>, std::unique_ptr<Jogador>);
    void atualizaDadosPartida();
};

#endif