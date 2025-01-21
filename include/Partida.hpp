#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <memory>
#include "CSV.hpp"
#include "Jogador.hpp"
#include "Tabuleiro.hpp"
#include "PosicaoCartesiana.hpp"

/**
 * @brief Classe criada para organizar e lidar com os dados durante a partida
 */
class Partida
{
private:
    std::unique_ptr<Jogador> _player1;
    std::unique_ptr<Jogador> _player2;
    std::unique_ptr<Tabuleiro> _tabuleiro;
    int _rounds;

public:
    /**
     * @brief Construtor padrão da classe, que recebe um tabuleiro e dois jogadores.
     * @param tabuleiro Ponteiro do tipo unique_ptr que aponta para o tabuleiro onde será jogado o jogo
     * @param player1 Ponteiro do tipo unique_ptr que aponta para o primeiro jogador da partida
     * @param player2 Ponteiro do tipo unique_ptr que aponta para o segundo jogador da partida
     */
    Partida(std::unique_ptr<Tabuleiro> tabuleiro, std::unique_ptr<Jogador> player1, std::unique_ptr<Jogador> player2);

    ~Partida();

    /**
     * @brief Método que executa a partida
     * @details Esse método é responsável por alternar os rounds e chamar o método de leitura com o jogador certo
     */
    void round();

    /**
     * @brief Método que lê a jogada de um jogador
     * @param num_jogador Número do jogador referente à jogada (1 ou 2)
     * @details Esse método deve verificar se o jogador tem jogadas válidas, se a jogada feita foi válida e printar o tabuleiro
     */
    void leitorJogada(int num_jogador);

    /**
     * @brief Método feito para finalizar a partida
     * @param vencedor Recebe o número do jogador que foi vencedor
     * @details Esse método deve chamar métodos de atualização dos dados nos arquivos e ser chamado quando a partida termina
     */
    void finalizarPartida(int vencedor);

    /**
     * @brief Método feito para atualizar os dados dos jogadores no arquivo
     * @param jogador_vencedor Recebe o ponteiro do jogador que foi vencedor
     * @param jogador_perdedor Recebe o ponteiro do jogador que foi perdedor
     * @details Esse método deve chamar o método de atualização de dados de partida ao fim
     */
    void atualizaDadosJogador(std::unique_ptr<Jogador> jogador_vencedor, std::unique_ptr<Jogador> jogador_perdedor);

    
    /**
     * @brief Método feito para atualizar os dados da partida no arquivo
     * @param jogador_vencedor Recebe o ponteiro do jogador que foi vencedor
     * @param jogador_perdedor Recebe o ponteiro do jogador que foi perdedor
     */
    void atualizaDadosPartida(std::unique_ptr<Jogador> jogador_vencedor, std::unique_ptr<Jogador> jogador_perdedor);

    /**
     * @brief Método feito para atualizar os dados da partida no arquivo
     * @details Esse método é chamado em caso de empate, ou seja, não há diferença entre vencedor e o perdedor.
     */
    void atualizaDadosPartida();
};

#endif