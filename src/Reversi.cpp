#include "Reversi.hpp"

Reversi::Reversi() : Tabuleiro(8, 8)
{
    this->_tipo = 1; // identificador para reversi
}

int Reversi::finalizarJogo()
{
    // TODO -  finalizar quando terminar todas as casas e vencedor é o jogador com mais casas com seu nome
    return 0; // jogo continua
}

void Reversi::posicionarPeca(int x, int y, int num_jogador)
{
    if (x >= 0 && x < 8 && y >= 0 && y < 8 && _board[x][y] == VAZIO)
    {
        Tabuleiro::posicionarPeca(x, y, num_jogador);
        // TODO - implementar lógica para capturar e reverter as casas do adversario
    }
}

Casa Reversi::localizarPeca(int, int) {};
