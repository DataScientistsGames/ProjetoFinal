#include "CSV.hpp"
#include <iostream>
#include <vector>
#include <string>

CSV::CSV(std::string caminho) : _arquivo(caminho, std::ios::in | std::ios::out), _arquivo_nome(caminho)
{
    if (!this->_arquivo.is_open())
    {
        this->~CSV();
        throw std::runtime_error("Erro ao abrir o arquivo!");
    }

    this->_arquivo.seekp(0, std::ios::end);
    this->_arquivo.seekg(0, std::ios::beg);
}

CSV::~CSV()
{
    this->_arquivo.close();
}

void CSV::escreverArquivo(std::string entrada)
{
    this->_arquivo.seekp(0, std::ios::end);
    this->_arquivo.clear();
    this->_arquivo << entrada;
    this->_arquivo.seekp(0, std::ios::end);
}

void CSV::apagarNoArquivo(std::string apelido)
{
    this->_arquivo.clear();
    this->_arquivo.seekg(0, std::ios::beg);
    std::vector<std::string> linhas;
    std::string linha;

    while (std::getline(this->_arquivo, linha))
    {
        if (pegaApelidoLinha(linha) != apelido)
        {
            linhas.push_back(linha);
        }
    }

    this->_arquivo.close();
    this->_arquivo.open(this->_arquivo_nome, std::ios::in | std::ios::out | std::ios::trunc);

    if (!this->_arquivo.is_open())
    {
        throw std::runtime_error("Erro ao abrir o arquivo no modo truncado.");
    }

    for (const auto &linhaAtual : linhas)
    {
        this->_arquivo << linhaAtual << '\n';
    }

    this->_arquivo.flush();
    this->_arquivo.clear();
    this->_arquivo.seekg(0, std::ios::beg);
}

void CSV::atualizarNoArquivo(std::string apelido_jogador, std::string novos_dados)
{
    this->_arquivo.clear();
    this->_arquivo.seekg(0, std::ios::beg);
    std::vector<std::string> linhas;
    std::string linha;

    while (std::getline(this->_arquivo, linha))
    {
        if (pegaApelidoLinha(linha) != apelido_jogador)
        {
            linhas.push_back(linha);
        }
        else
        {
            linhas.push_back(novos_dados);
        }
    }

    this->_arquivo.close();
    this->_arquivo.open(this->_arquivo_nome, std::ios::in | std::ios::out | std::ios::trunc);

    if (!this->_arquivo.is_open())
    {
        throw std::runtime_error("Erro ao abrir o arquivo no modo truncado.");
    }

    for (const auto &linhaAtual : linhas)
    {
        this->_arquivo << linhaAtual << '\n';
    }

    this->_arquivo.flush();
    this->_arquivo.clear();
    this->_arquivo.seekg(0, std::ios::beg);
}

std::string CSV::pegaApelidoLinha(std::string linha)
{
    std::string apelido = "";
    int i = 0;
    while (linha[i] != ',')
    {
        apelido += linha[i];
        i++;
    }
    return apelido;
}

std::string CSV::lerLinhaArquivo()
{
    if (!this->_arquivo.eof())
    {
        std::string linha;
        std::getline(this->_arquivo, linha);
        return linha;
    }
    return "";
}