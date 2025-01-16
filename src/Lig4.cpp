#include "Lig4.hpp"

Lig4::Lig4() : Tabuleiro(6, 7)
{
    this->_tipo = 2; // identificador para lig4
}

int Lig4::finalizarJogo()
{
    // TODO - verificar 4 em linha (horizontal, vertical e diagonal)
    return 0; // jogo continua
}

bool Lig4::posicionarPeca(int x, int y, int num_jogador)
{
    for (int i = 5; i >= 0; --i)
    {
        return Tabuleiro::posicionarPeca(i, y, num_jogador);
    }

}