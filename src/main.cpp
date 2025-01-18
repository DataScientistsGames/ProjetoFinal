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
            CoutComuns::limparCmd();
            std::cerr << VERM << "ERRO: " << e.what() << '\n'
                      << FIMCOR;
        }

        if (!std::cin.eof())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        CoutComuns::espereEnter();
        CoutComuns::limparCmd();
    } while (comando != FS);

    return 0;
}
