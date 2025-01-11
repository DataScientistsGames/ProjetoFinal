#include <iostream>
#include <string>
#include <stdexcept>
#include "CoutComuns.hpp" // helper do embelezamento do cmd
#include "Controlador.hpp"
#include "Comandos.hpp"

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
    if (comandoStr == "FS")
        return FS;
    else
        throw std::invalid_argument(comandoStr + " não é um comando válido!");
}

int main()
{
    Controlador sistema;

    std::string entrada;
    Comandos comando;

    try
    {
        do
        {
            CoutComuns::displayComandos();
            std::cout << "Digite um comando válido: ";
            std::cin >> entrada;
            std::cin.ignore();

            comando = stringParaComando(entrada);
            sistema.leitorComando(comando);
        } while (comando != FS);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << '\n';
    }

    return 0;
}
