#ifndef CADASTRADOR_H
#define CADASTRADOR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "CSV.hpp"

class Cadastrador
{
public:
    Cadastrador();
    ~Cadastrador();

    std::string removerJogador(std::string);
    std::string cadastrarJogador(std::string, std::string);
    void listarJogador(char);

    std::string adicionaChave(char, std::string);
    std::string pegaPalavraLinha(std::string);
    std::string retornaLinhaJogador(std::string);
    bool existeJogador(std::string);
    bool existeEstatistica(std::string);
    void traduzChaveCSV(std::string);
};

#endif