#ifndef TABULEIRO_H
#define TABULEIRO_H

#define CHAR_BORDA_COLUNA '|'
#define CHAR_BORDA_LINHA '-'

#include <iostream>
#include "Casa.hpp"
#include "PosicaoCartesiana.hpp"

/**
 * @brief Classe genérica que representa um Tabuleiro
 * @details Essa classe guarda o estado do tabuleiro, e performa ações de posiconar peça dos jogadores, avaliar condição de finalização e calcular vies da posição no tabuleiro.
 */
class Tabuleiro
{
protected:
    Casa **_board;
    int _x;
    int _y;
    int _tipo; // 0 - velha, 1 - reversi, 2 - lig4
    std::string _string_pecas[3];

public:
    /**
     * @brief Construtor base da classe Tabuleiro.
     * @param x, y, string_player1, string_player2 largura e comprimeto do tabuleiro, e strings que representam os jogadores.
     */
    Tabuleiro(int x, int y, std::string string_player1, std::string string_player2);

    /**
     * @brief Destroi o objeto e libera a memória do quadro do tabuleiro.
     */
    ~Tabuleiro();

    /**
     * @brief Posiciona uma peça de um jogador.
     * @details Essa função posiciona as peças se a casa do tabuleiro estiver vazia.
     * @param x, y, Jogaor Coordenadas da posição e número correspondente ao jogador da jogada.
     * @return Retorna true se foi possível posicionar; retorna false se não.
     */
    bool virtual posicionarPeca(int x, int y, int num_jogador);
    int virtual finalizarJogo(); // 0 - continua, 1 - jogador 1 venceu, 2 - jogador 2 venceu, 3 - empatou

    /**
     * @brief Retorna a casa correspondente à posição.
     * @param x,y Coordenadas da posição checada.
     * @return O viés calculado, expressado como uma posição cartesiana.
     */
    Casa virtual localizarPeca(int x, int y);

    /**
     * @brief Retorna a casa correspondente ao inteiro.
     * @param num_jogador O jogador em inteiro.
     * @return A casa respectiva.
     */
    Casa intParaCasa(const int num_jogador);

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

    /**
     * @brief Converte as coordenadas pra uma base com origem no centro do tabuleiro.
     * @param posX A coordenada X.
     * @param posY A coordenada Y.
     * @return As coordenadas sob a nova base.
     */
    PosicaoCartesiana virtual centralizaCoordenadas(int posX, int posY);
};

#endif