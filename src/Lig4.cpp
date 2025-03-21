#include "Lig4.hpp"
#define STRING_JOGADOR_1 "\e[0;34m @ \033[0m"
#define STRING_JOGADOR_2 "\e[0;31m O \033[0m"

Lig4::Lig4() : Tabuleiro(6, 7, STRING_JOGADOR_1, STRING_JOGADOR_2)
{
    this->_tipo = 2; // identificador para lig4
}

int Lig4::finalizarJogo()
{
    // olha por todas as casas do tabuleiro de baixo pra cima, ja que posicionamos de baixo pra cima

    bool existeCasaVazia = false;
    for (int x = 5; x >= 0; x--)
    {
        for (int y = 0; y < 7; y++)
        {
            Casa jogador = this->_board[x][y];
            if (jogador != VAZIO)
            {
                // olha horizontal
                if (y + 3 < 7 &&
                    this->_board[x][y + 1] == jogador &&
                    this->_board[x][y + 2] == jogador &&
                    this->_board[x][y + 3] == jogador)
                {
                    return jogador == JOGADOR_1 ? 1 : 2;
                }

                // olha vertical
                if (x - 3 >= 0 &&
                    _board[x - 1][y] == jogador &&
                    _board[x - 2][y] == jogador &&
                    _board[x - 3][y] == jogador)
                {
                    return jogador == JOGADOR_1 ? 1 : 2;
                }

                // olha diagonal para cima e para a direita
                if (x - 3 >= 0 && y + 3 < 7 &&
                    _board[x - 1][y + 1] == jogador &&
                    _board[x - 2][y + 2] == jogador &&
                    _board[x - 3][y + 3] == jogador)
                {
                    return jogador == JOGADOR_1 ? 1 : 2;
                }

                // olha diagonal para cima e para a esquerda
                if (x - 3 >= 0 && y - 3 >= 0 &&
                    _board[x - 1][y - 1] == jogador &&
                    _board[x - 2][y - 2] == jogador &&
                    _board[x - 3][y - 3] == jogador)
                {
                    return jogador == JOGADOR_1 ? 1 : 2;
                }
            }
            else
            {
                existeCasaVazia = true;
            }
        }
    }

    return existeCasaVazia ? 0 : 3; // jogo continua se existir casa vazia, ou empata se nao existir
}

bool Lig4::posicionarPeca(int x, int y, int num_jogador)
{
    if (x < 0 || x > 5)
        return false;

    for (int i = 6; i >= 0; --i)
    {
        if (this->_board[x][i] == VAZIO)
        {
            return Tabuleiro::posicionarPeca(x, i, num_jogador);
        }
    }

    return false;
}

void Lig4::imprimeBordaVertical()
{
    for (int i = 0; i < this->_x; i++) // acho que desse jeito fica mais bonito, pois parece que a peça cai na coluna mesmo
    {
        std::cout << "    ";
    }

    std::cout << " " << std::endl;
}

void Lig4::imprimeTabuleiro()
{
    Tabuleiro::imprimeTabuleiro();
    std::cout << "Formato de jogada: <Coluna>" << std::endl;
}