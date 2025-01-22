#ifndef LIG4_H
#define LIG4_H

#include <iostream>
#include "Tabuleiro.hpp"
#include "Casa.hpp"

/**
 * @brief Classe que representa um tabuleiro de Ligue 4
 * @details Essa classe herda as funções da classe genérica Tabuleiro e especializa a avaliação da condição de finalização do tabuleiro, posicionamento das peças e a impreção da estética do tabuleiro.
 */
class Lig4 : public Tabuleiro
{
public:
    /**
     * @brief Construtor do tabuleiro de Ligue 4.
     * @details Constroi um tabuleiro 6 por 7 casas vazio.
     */
    Lig4();

    /**
     * @brief Avalia se o tabuleiro atingiu um estado de finalização.
     * @details O tabuleiro do Ligue 4, finaliza quando 4 peças de um jogador formam uma linha, coluna ou diagonal.
     * @return Retorna 0 se o tabuleiro pode continuar a ser usado, retorna 1|2 para o número do jogador vencedor ou retorna 3 para o empate.
     */
    int finalizarJogo() override final;

    /**
     * @brief Posiciona uma peça de um jogador.
     * @details Essa função posiciona as peças da coluna escolhida na última posição vazia.
     * @param y, Jogaor Coluna da posição e número correspondente ao jogador da jogada.
     * @return Retorna true se foi possível posicionar; retorna false se não.
     */
    bool posicionarPeca(int, int, int) override final;
    void imprimeBordaVertical() override final;
    void imprimeTabuleiro() override final;
};

#endif