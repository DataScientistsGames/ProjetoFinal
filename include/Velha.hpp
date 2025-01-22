#ifndef VELHA_H
#define VELHA_H

#include <iostream>
#include "Tabuleiro.hpp"
#include "Casa.hpp"

/**
 * @brief Classe que representa um tabuleiro de Jogo da Velha
 * @details Essa classe herda as funções da classe genérica Tabuleiro e especializa a avaliaçãoo da condição de finalização do tabuleiro.
 */
class Velha : public Tabuleiro
{
public:
    /**
     * @brief Construtor do tabuleiro de Jogo da Velha.
     * @details Constroi um tabuleiro 3 por 3 casas vazio.
     */
    Velha();

    /**
     * @brief Avalia se o tabuleiro atingiu um estado de finalização.
     * @details O tabuleiro do Jogo da Velha, finaliza quando 3 peças de um jogador formam uma linha, coluna ou diagonal.
     * @return Retorna 0 se o tabuleiro pode continuar a ser usado, retorna 1|2 para o número do jogador vencedor ou retorna 3 para o empate.
     */
    int finalizarJogo() override final;
    void imprimeTabuleiro() override final;
};

#endif