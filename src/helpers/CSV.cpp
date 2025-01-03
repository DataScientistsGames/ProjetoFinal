#include "CSV.hpp"
#include <iostream>
#include <csignal>

CSV::CSV(std::string caminho) : _arquivo(caminho, std::ios::in | std::ios::out | std::ios::app)
{
    if (!this->_arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        this->~CSV();
    }

    this->_arquivo.seekp(0, std::ios::beg);
}

CSV::~CSV()
{
    this->_arquivo.close();
}

void CSV::escreverArquivo(std::string entrada)
{
    this->_arquivo.clear();
    this->_arquivo << entrada;
    this->_arquivo.seekp(0, std::ios::beg);
}

std::string CSV::lerLinhaArquivo()
{
    if (!this->_arquivo.eof())
    {
        std::string linha;
        std::getline(this->_arquivo, linha);
        std::cout << linha << std::endl;
        return linha;
    }
    return "";
}