#ifndef CSV_H
#define CSV_H

#include <iostream>
#include <fstream>
#include <string>

class CSV
{
private:
    std::string _arquivo_nome;
    std::fstream _arquivo;

public:
    CSV(std::string);
    ~CSV();

    void escreverArquivo(std::string);
    void apagarNoArquivo(std::string);
    void atualizarNoArquivo(std::string, std::string);
    std::string pegaApelidoLinha(std::string);
    std::string lerLinhaArquivo();
};

#endif