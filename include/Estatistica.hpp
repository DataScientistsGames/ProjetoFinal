#ifndef ESTATISTICA_H
#define ESTATISTICA_H

#include <iostream>
#include <memory>
#include <vector>
#include "CSV.hpp"
#include "Jogador.hpp"
#include "Tabuleiro.hpp"
#include "PosicaoCartesiana.hpp"

/**
 * @brief Classe estática, para calcular as estatisticas do jogador
 * @details Classe interamente nova, pensada para ser um atributo novo para o sistema para facilitar vizualização dos dados.
 */
class Estatistica
{
public:

    /**
     * @brief Pega as estatísticas de um jogador existente.
     * @param linha_jogador Dados do jogador para ser criado seu objeto.
     * @return Não há return
     * @details Exemplo de print:
     * @verbatim
      Média de vitórias: 11.3333
      Média de derrotas: 13.3333
      Viés Jogador Velha: 0.27 na direção X e 0.18 na direção Y.
      Viés Jogador Reversi: 0.00 na direção X e 0.00 na direção Y.
      Viés Jogador Lig4: -0.29 na direção X e 0.00 na direção Y.
      Proporcao de Vitórias Velha: 0.44
      Proporcao de Vitórias Reversi: 0.48
      Proporcao de Vitórias Lig4: 0.46
     @endverbatim
    */
    static void calculaEstatisticasJogador(std::string linha_jogador);

    /**
     * @brief Calcula a média de um jogador.
     * @param valores valores a serem calculados alguma média.
     * @return Retorna a média.
    */
    static double media(std::vector<int> valores);

    /**
     * @brief Calcula o viés, chamandos os métodos de leitura do arquivo e pegando os dados.
     * @param apelido_jogador Apelido do jogador que será lido.
     * @param jogo Qual o jogo é desejado o viés.
     * @return Retorna o resultado da operação, como um vetor.
     * @exception Em caso de falha, a exceção parte do CSV até a main do programa.
    */
    static std::vector<double> vies(std::string apelido_jogador, char jogo);

    /**
     * @brief Calcula a proporção entre dois doubles.
     * @param valores Vetor que contêm os doubles a serem calculados.
     * @return Retorna a proporção do item 0 em relação ao total.
    */
    static double proporcao(std::vector<double> valores);

    /**
     * @brief Pega da linha o apelido do jogador.
     * @param linha Dados de uma linha do arquivo, partida.csv ou jogadores.csv.
     * @return Retorna o apelido.
    */
    static std::string pegaApelido(std::string linha);

    /**
     * @brief Pega da linha o jogo referente a partida.
     * @param linha Dados de uma linha do arquivo, partida.csv.
     * @return Retorna o Jogo.
    */
    static char pegaJogo(std::string linha);

    /**
     * @brief Pega o Viés da linha de partidas.
     * @param linha A linha a qual será retirada os vies.
     * @param direcao A direção cartesiana desejada.
     * @return Retorna o resultado do vies
    */
    static int pegaVies(std::string linha, char direcao);
};

#endif