#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <iostream>
#include "Comandos.hpp"

class Controlador
{
public:
    Controlador();
    ~Controlador();
    void leitorComando(enum Comandos);
    void cadastrarJogador();
    void removerJogador();
    void listarJogador();
    void executarPartida();
    void finalizarSistema();
    std::string traduzCSV(std::string);
    std::string pegaPalavraLinha(std::string);
};

#endif