#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <iostream>
#include "Comandos.hpp"

/**
 * @brief Classe controlar o fluxo do programa.
 */
class Controlador
{
public:
    /**
     * @brief Controi o objeto.
     * @return Não há return.
    */
    Controlador();
    
    /**
     * @brief Destroi o objeto.
     * @return Não há return.
    */
    ~Controlador();
    
    /**
     * @brief Recebe os comandos do sistema e redireciona para as funções/classes necessárias.
     * @param comando O comando digitado pelo usuário.
     * @return Não há retorno.
     * @exception Em caso de escrita incorreta, a exceção parte para a main indicando o erro de comando.
    */
    void leitorComando(Comandos comando);
    
    /**
     * @brief Cadastra o jogador, lendo do teclado o apelido e o nome.
     * @return Não há retorno.
     * @exception Em caso de vírgula no apelido, a exceção parte para a main indicando o erro de comando.
    */
    void cadastrarJogador();
    
    /**
     * @brief Remove o jogador, lendo do teclado o apelido e removendo através dele.
     * @return Não há retorno.
     * @exception Em caso do apelido não ser encontrado, a exceção parte para a main indicando o erro de comando.
    */
    void removerJogador();
    
    /**
     * @brief Lista os jogadores existentes, lendo do teclado o método de ordenação, apelido(A) ou nome(N).
     * @return Não há retorno.
     * @exception Em caso do método ser digitado errado, a exceção parte para a main indicando o erro de comando.
    */
    void listarJogador();
    
    /**
     * @brief Executa o objeto da partida, lendo do teclado o jogo desejado e os apelidos dos jogadores,1 e 2.
     * @return Não há retorno.
     * @exception Em caso de um atributo ser digitado errado, a exceção parte para a main indicando o erro de comando.
    */
    void executarPartida();
    
    /**
     * @brief Chama o método de calculo das estatisticas, lendo do teclado o jogador pelo apelido e passando para o método.
     * @return Não há retorno.
     * @exception Em caso do jogador não existir, a exceção parte para a main indicando o erro de comando.
    */
    void estatisticasJogador();
    
    /**
     * @brief Finaliza o looping de comandos.
     * @return Não há retorno.
    */
    void finalizarSistema();
};

#endif