#ifndef CSV_H
#define CSV_H

#include <iostream>
#include <fstream>

class CSV
{
private:
    std::fstream _arquivo;

public:
    CSV(std::string);
    ~CSV();

    void escreverArquivo(std::string);
    std::string lerLinhaArquivo();
};

#endif