#ifndef TABULEIRO_H
#define TABULEIRO_H

#define CHAR_BORDA_COLUNA '|'
#define CHAR_BORDA_LINHA '-'

#include <iostream>
#include "Casa.hpp"
#include "PosicaoCartesiana.hpp"

class Tabuleiro
{
protected:
    Casa **_board;
    int _x;
    int _y;
    int _tipo; // 0 - velha, 1 - reversi, 2 - lig4
    std::string _string_pecas[3];

public:
    Tabuleiro(int x, int y, std::string string_player1, std::string string_player2);
    ~Tabuleiro();

    bool virtual posicionarPeca(int x, int y, int num_jogador = 0);
    int virtual finalizarJogo(); // 0 - continua, 1 - jogador 1 venceu, 2 - jogador 2 venceu, 3 - empatou
    
    /**
     * @brief Retorna a casa correspondente à posição.
     * @param jogador Número correspondente ao jogador sendo checado.
     * @return O viés calculado, expressado como uma posição cartesiana.
    */
    Casa virtual localizarPeca(int x, int y);

    Casa stringParaCasa(const int num_jogador);

    /**
     * @brief Calcula o viés nas posições jogadas pelo jogador.
     * @param jogador Número correspondente ao jogador sendo checado.
     * @return O viés calculado, expressado como uma posição cartesiana.
    */
    PosicaoCartesiana calculaVies(int jogador);

    /**
     * @brief Retorna o tipo do tabuleiro, ou seja, o jogo que está sendo jogado.
     * @return Retorna o número correspondente ao tipo do tabuleiro.
    */
    int getTipo();

    /**
     * @brief Imprime uma linha de caracteres do comprimento do tabuleiro impresso.
    */
    void virtual imprimeBordaVertical();

    /**
     * @brief Imprime cada casa do tabuleiro com sua respectiva peça dentro, cercado por duas bordas verticais.
    */
    void virtual imprimeTabuleiro();

    /**
     * @brief Checa se o jogador ainda pode fazer alguma jogada válida.
     * @details Usado somente no Reversi; em todo outro jogo sempre há jogadas válidas.
     * @param jogador Número correspondente ao jogador sendo checado.
     * @return Retorna true se existe pelo menos uma jogada válida que o jogador possa fazer; retorna false se não.
    */
    bool virtual temJogadaValida(Casa jogador);
};

#endif