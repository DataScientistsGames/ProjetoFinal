#include <iostream>
#include <vector>
#include "Partida.hpp"
#include "Jogador.hpp"
#include "CSV.hpp"

Partida::Partida(Jogador &player1, Jogador &player2) : _player1(&player1), _player2(&player2), _rounds(0) {}

Partida::~Partida()
{
    delete this->_player1;
    delete this->_player2;
}