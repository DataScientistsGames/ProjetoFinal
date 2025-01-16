#include <iostream>
#include <string>

#define CHAR_BORDA '#'
#define X 3
#define Y 3

using namespace std;

void imprimeBordaVertical()
{
    for (int i = 0; i < ((X * 4) + 1); i++) // Multiplica x por 4 porque toda casa impressa vem junto com um '#' e dois espaços. Soma 1 porque existe uma parede de '#'s antes de cada linha.
    {
        std::cout << CHAR_BORDA;
    }

    std::cout << std::endl;
}

void imprimeTabuleiro()
{
    
}

int main() {
    char charsPecas[3] = {' ', 'X', 'O'};

    imprimeBordaVertical();

    for (int i = 0; i < Y; i++) 
    {
        std::cout << CHAR_BORDA;

        for (int j = 0; j < X; j++) 
        {
            int pecaAtual = 2;

            std::cout << " " << charsPecas[pecaAtual] << " " << CHAR_BORDA;
        }

        std::cout << std::endl;
        imprimeBordaVertical();
    }

    return 0;
}