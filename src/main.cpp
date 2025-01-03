#include <iostream>
#include <string>
#include <stdexcept>
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
        while (true)
        {
            std::cout << "Digite um comando válido (ou 'FS' para encerrar): ";
            std::cin >> entrada;

            if (entrada == "FS")
            {
                sistema.leitorComando(comando);
                break;
            }

            comando = stringParaComando(entrada);

            sistema.leitorComando(comando);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << '\n';
    }

    return 0;
}
