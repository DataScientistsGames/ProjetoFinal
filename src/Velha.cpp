#include "Velha.hpp"

Velha::Velha() : Tabuleiro(3, 3)
{
    this->_tipo = 0; // identificador para velha
}

// verifica se atingiu condicao de finalizacao retornando o numero do jogador vencedor ou 0 se não tem vencedor ainda
int Velha::finalizarJogo()
{
    // Verifica linhas, colunas e diagonais para determinar o vencedor
    for (int i = 0; i < 3; i++)
    {
        // horizontais
        if (this->_board[i][0] == this->_board[i][1] && this->_board[i][1] == this->_board[i][2] && this->_board[i][0] != VAZIO)
        {
            return this->_board[i][0] == JOGADOR_1 ? 1 : 2;
        }
        // verticais
        if (this->_board[0][i] == this->_board[1][i] && this->_board[1][i] == this->_board[2][i] && this->_board[0][i] != VAZIO)
        {
            return this->_board[0][i] == JOGADOR_1 ? 1 : 2;
        }
    }
    // diagonal ponta esquerda superior para direita inferior
    if (this->_board[0][0] == this->_board[1][1] && this->_board[1][1] == this->_board[2][2] && this->_board[0][0] != VAZIO)
    {
        return this->_board[0][0] == JOGADOR_1 ? 1 : 2;
    }
    // diagonal ponta direita superior para esquerda inferior
    if (this->_board[0][2] == this->_board[1][1] && this->_board[1][1] == this->_board[2][0] && this->_board[0][2] != VAZIO)
    {
        return this->_board[0][2] == JOGADOR_1 ? 1 : 2;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (this->_board[i][j] == VAZIO)
            {
                return 0; // jogo continua
            }
        }
    }

    return 3; // empate
}