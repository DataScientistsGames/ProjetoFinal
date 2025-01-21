#ifndef CADASTRADOR_H
#define CADASTRADOR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "CSV.hpp"

/**
 * @brief classe criada para lidar com a escrita, remoção e leitura de jogadores do CSV
 */
class Cadastrador
{
public:
    /**
     * @brief Construtor padrão da classe.
     */
    Cadastrador();

    
    /**
     * @brief Destrutor padrão da classe.
     */
    ~Cadastrador();
 
    /**
     * @brief Remove um jogador dos arquivos, caso exista.
     * @param apelido_jogador Apelido do jogador que será removido.
     * @return Retorna o resultado da operação.
     * @exception Em caso de falha, a exceção parte do CSV até a main do programa.
    */
    std::string removerJogador(std::string apelido_jogador);

    /**
     * @brief Adiciona um jogador ao arquivo de jogadores.
     * @param apelido_jogador Apelido do jogador que será adicionado (único).
     * @param nome_jogador Nome do jogador que será removido.
     * @return Retorna o resultado da operação.
     * @exception Em caso de falha, a exceção parte do CSV até a main do programa.
    */
    std::string cadastrarJogador(std::string apelido_jogador, std::string nome_jogador);

    /**
     * @brief Lista os jogadores salvos.
     * @param metodo Método (Nome ou Apelido) pelo qual os jogadores serão listados.
     * @exception Em caso de falha, a exceção parte do CSV até a main do programa.
    */
    void listarJogador(char metodo);

    /**
     * @brief Adiciona nos dados dos jogadores a chave (Nome ou Apelido) para que seja de mais fácil ordenação.
     * @param metodo Método (Nome ou Apelido) pelo qual os jogadores serão listados.
     * @param linha String com os dados do jogador que será adicionada a chave.
    */
    std::string adicionaChave(char metodo, std::string linha);

    /**
     * @brief Pega o Apelido do jogador dada a linha de arquivo (primeira célula do CSV).
     * @param linha String com os dados do jogador que será lida.
     * @return Retorna o Apelido.
    */
    std::string pegaPalavraLinha(std::string linha);

    /**
     * @brief Retorna a linha do arquivo CSV com os dados do jogador dado apelido.
     * @param apelido_jogador Apelido do jogador que quer os dados.
     * @return Retorna a linha com os dados.
    */
    std::string retornaLinhaJogador(std::string apelido_jogador);

    /**
     * @brief Verifica se o jogador está registrado no arquivo.
     * @param apelido_jogador Apelido do jogador que quer verificar.
     * @return Retorna verdadeiro o falso caso esse jogador esteja cadastrado.
    */
    bool existeJogador(std::string apelido_jogador);

    /**
     * @brief Verifica se há alguma estatística do jogador no arquivo de partidas.
     * @param apelido_jogador Apelido do jogador que quer verificar.
     * @return Retorna verdadeiro o falso caso esse jogador tenha estatísticas registradas.
    */
    bool existeEstatistica(std::string apelido_jogador);

    /**
     * @brief Imprime para o usuário os dados de uma chave+string relativos a um jogador.
     * @param linha Linha com chave que será traduzida e impressa.
     * @details Exemplo de print:
     * @verbatim
     apelido_jogador Nome do Jogador
     Reversi - V: 0 D: 0 
     Lig4 - V: 0 D: 0 
     Velha - V: 0 D: 0
     @endverbatim
    */
    void traduzChaveCSV(std::string linha);
};

#endif