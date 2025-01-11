#ifndef COUTCOMUNS_H
#define COUTCOMUNS_H

#include <iostream>

class CoutComuns
{
public:
    static void displayComandos();
    static void espereEnter();
    static void limparCmd();

    CoutComuns() = delete; // desabilita criar uma instancia - classe estatica
};

#endif
