#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <fstream>
#include "CoutComuns.hpp" // helper do embelezamento do cmd
#include "Controlador.hpp"
#include "Comandos.hpp"
#include "Cores.hpp"

Comandos stringParaComando(const std::string &comandoStr)
{
    if (comandoStr == "CJ")
        return CJ;
    else if (comandoStr == "RJ")
        return RJ;
    else if (comandoStr == "LJ")
        return LJ;
    else if (comandoStr == "EP")
        return EP;
    else if (comandoStr == "EST")
        return EST;
    else if (comandoStr == "FS")
        return FS;
    else
        throw std::invalid_argument(comandoStr + " não é um comando válido!");
}

int main()
{
    Controlador sistema;

    std::string entrada;
    Comandos comando;

    CoutComuns::limparCmd();

    do
    {
        try
        {
            CoutComuns::displayComandos();
            std::cout << "Digite um comando válido: ";
            std::cin >> entrada;
            std::cin.ignore();

            comando = stringParaComando(entrada);
            sistema.leitorComando(comando);
        }
        catch (const std::exception &e)
        {
            CoutComuns::limpaBuffer();
            CoutComuns::limparCmd();
            std::cerr << VERM << "ERRO: " << e.what() << FIMCOR << std::endl;
            CoutComuns::espereEnter();
            CoutComuns::limparCmd();
        }

    } while (comando != FS);

    return 0;
}
