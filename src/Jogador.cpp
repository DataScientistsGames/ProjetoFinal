#include "Jogador.hpp"
#include <iostream>
#include <string>

Jogador::Jogador(std::string linha)
{
    long unsigned int i;
    for (i = 0; linha[i] != ','; i++)
    {
        this->_apelido += linha[i];
    }

    i++;
    for (; linha[i] != ','; i++)
    {
        this->_nome += linha[i];
    }

    i++;
    std::string vitorias_velha = "";
    for (; linha[i] != ','; i++)
    {
        vitorias_velha += linha[i];
    }
    this->_vitorias_velha = std::stoi(vitorias_velha);

    i++;
    std::string derrotas_velha = "";
    for (; linha[i] != ','; i++)
    {
        derrotas_velha += linha[i];
    }
    this->_derrotas_velha = std::stoi(derrotas_velha);

    i++;
    std::string vitorias_reversi = "";
    for (; linha[i] != ','; i++)
    {
        vitorias_reversi += linha[i];
    }
    this->_vitorias_reversi = std::stoi(vitorias_reversi);

    i++;
    std::string derrotas_reversi = "";
    for (; linha[i] != ','; i++)
    {
        derrotas_reversi += linha[i];
    }
    this->_derrotas_reversi = std::stoi(derrotas_reversi);

    i++;
    std::string vitorias_lig4 = "";
    for (; linha[i] != ','; i++)
    {
        vitorias_lig4 += linha[i];
    }
    this->_vitorias_lig = std::stoi(vitorias_lig4);

    i++;
    std::string derrotas_lig4 = "";
    for (; i < linha.size(); i++)
    {
        derrotas_lig4 += linha[i];
    }
    this->_derrotas_lig = std::stoi(derrotas_lig4);
}

Jogador::~Jogador() {}

std::string Jogador::getApelido() { return this->_apelido; }
std::string Jogador::getNome() { return this->_nome; }
int Jogador::getVitoriasV() { return this->_vitorias_velha; };
int Jogador::getDerrotasV() { return this->_derrotas_velha; };
int Jogador::getVitoriasR() { return this->_vitorias_reversi; };
int Jogador::getDerrotasR() { return this->_derrotas_reversi; };
int Jogador::getVitoriasL() { return this->_vitorias_lig; };
int Jogador::getDerrotasL() { return this->_derrotas_lig; };
PosicaoCartesiana Jogador::getVies() { return this->_vies; };
void Jogador::setVies(PosicaoCartesiana vies)
{
    this->_vies = vies;
}