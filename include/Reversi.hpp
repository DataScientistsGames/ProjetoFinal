#ifndef REVERSI_H
#define REVERSI_H

#include <iostream>
#include "Tabuleiro.hpp"
#include "Casa.hpp"

/**
 * @brief Classe que representa um tabuleiro de Reversi
 * @details Essa classe herda as funções da classe genérica Tabuleiro e especializa a avaliação da condição de finalização do tabuleiro, posicionamento das peças e avaliação de jogadas válidas.
 */
class Reversi : public Tabuleiro
{
public:
    /**
     * @brief Construtor do tabuleiro de Reversi.
     * @details Constroi um tabuleiro 8 por 8 casas com as peças iniciais no padrão do tabuleiro de Reversi.
     */
    Reversi();

    /**
     * @brief Avalia se o tabuleiro atingiu um estado de finalização.
     * @details O tabuleiro do Ligue 4, finaliza não há mais jogadas válidas e o vencedor é escolhido pela quantidade de peças no tabuleiro.
     * @return Retorna 0 se o tabuleiro pode continuar a ser usado, retorna 1|2 para o número do jogador vencedor ou retorna 3 para o empate.
     */
    int finalizarJogo() override final;

    /**
     * @brief Posiciona uma peça de um jogador.
     * @details Essa função chama o método de validação da jogada passando o parametro para posicionar e reverter as peças segunda as regras do tabuleiro.
     * @param x, y, Jogaor Coordenadas da posição e número correspondente ao jogador da jogada.
     * @return Retorna true se foi possível posicionar; retorna false se não.
     */
    bool posicionarPeca(int, int, int) override final;

    /**
     * @brief Checa se o jogador ainda pode fazer alguma jogada válida.
     * @details Exclusivo dessa classe, pois o reversi tem regras específicas para o posicionamento de uma peça.
     * @param jogador Número correspondente ao jogador sendo checado.
     * @return Retorna true se existe pelo menos uma jogada válida que o jogador possa fazer; retorna false se não.
     */
    bool temJogadaValida(Casa jogador);

    /**
     * @brief Checa se uma jogada é válida para um jogador.
     * @details Além disso como ela percorre as formações de linhas e colunas das peças, essa função pode atuar na reversão das peças do oponente.
     * @param x, y, Jogaor Coordenadas da posição e número correspondente ao jogador sendo checado.
     * @return Retorna true se a jogada é válida para o jogador; retorna false se não.
     */
    bool jogadaValida(int, int, Casa, bool);
    void imprimeTabuleiro() override final;
};

#endif