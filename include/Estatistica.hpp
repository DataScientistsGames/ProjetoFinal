#ifndef ESTATISTICA_H
#define ESTATISTICA_H

#include <iostream>
#include <memory>
#include <vector>
#include "CSV.hpp"
#include "Jogador.hpp"
#include "Tabuleiro.hpp"
#include "PosicaoCartesiana.hpp"

class Estatistica
{
public:
    static void calculaEstatisticasJogador(std::string);
    static double media(std::vector<int>);
    static std::vector<double> vies(std::string, char);
    static double porcentagem(std::vector<int>);
    static std::string pegaApelido(std::string);
    static char pegaJogo(std::string);
    static int pegaVies(std::string linha, char direcao);
};

#endif