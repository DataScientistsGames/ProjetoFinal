#ifndef COUTCOMUNS_H
#define COUTCOMUNS_H

#include <iostream>

/**
 * @brief classe auxiliadora com funções base de manipulação do terminal
 */
class CoutComuns
{
public:
    /**
     * @brief Método que imprime os comandos do menu do sistema
     * @details Exemplo de print:
     * @verbatim
     ----------------[C O M A N D O S]----------------
       CJ <Apelido> <Nome> - Cadastrar Jogador
       RJ <Apelido> - Remover Jogador
       LJ [A|N] - Listar Jogador por Apelido ou Nome
       EP [R|L|V] <Apelido Jogador 1> <Apelido Jogador 2> - Executar Partida de Reversi, Lig4 ou Jogo da Velha
       EST <Apelido> - Calcula e mostra as estatísticas de um Jogador
       FS - Finalizar Sistema
     -------------------------------------------------
     @endverbatim
    */
    static void displayComandos();

    /**
     * @brief Método que espera uma entrada de 'ENTER' para que continue o programa
     * @details Exemplo de print:
     * @verbatim
     Pressione Enter para continuar...
     @endverbatim
    */
    static void espereEnter();
    
    /**
     * @brief Método para limpar o terminal
     */
    static void limparCmd();

    
    /**
     * @brief Método que limpa o buffer de entrada caso haja algum lixo
     */
    static void limpaBuffer();

    CoutComuns() = delete; // desabilita criar uma instancia - classe estatica
};

#endif
