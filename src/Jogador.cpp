#include "Jogador.hpp"
#include <iostream>
#include <string>

Jogador::Jogador(std::string linha, bool cor) : _cor_atual(cor)
{
    int i;
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
    this->_derrotas_reversi == std::stoi(derrotas_reversi);

    i++;
    std::string vitorias_lig4 = "";
    for (; linha[i] != ','; i++)
    {
        vitorias_lig4 += linha[i];
    }
    this->_vitorias_lig == std::stoi(vitorias_lig4);

    i++;
    std::string derrotas_lig4 = "";
    for (; i < linha.size(); i++)
    {
        derrotas_lig4 += linha[i];
    }
    this->_derrotas_lig == std::stoi(derrotas_lig4);
}