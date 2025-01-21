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

    /**
     * @brief Construtor base da classe jogador.
     * @param linha Linha com os dados (exatamente como no CSV) que serão lidos e interpretados.
    */
    Jogador(std::string linha);
    ~Jogador();

    /**
     * @brief Retorna o apelido desse jogador.
    */
    std::string getApelido();

    /**
     * @brief Retorna o nome desse jogador.
    */
    std::string getNome();

    /**
     * @brief Retorna o valor de Vitórias no Jogo Velha desse jogador.
    */
    int getVitoriasV();

    /**
     * @brief Retorna o valor de Derrotas no Jogo Velha desse jogador.
    */
    int getDerrotasV();

    /**
     * @brief Retorna o valor de Vitórias no Jogo Reversi desse jogador.
    */
    int getVitoriasR();

    /**
     * @brief Retorna o valor de Derrotas no Jogo Reversi desse jogador.
    */
    int getDerrotasR();

    /**
     * @brief Retorna o valor de Vitórias no Jogo Lig4 desse jogador.
    */
    int getVitoriasL();

    /**
     * @brief Retorna o valor de Derrotas no Jogo Lig4 desse jogador.
    */
    int getDerrotasL();
};

#endif