#include "Reversi.hpp"
#define STRING_JOGADOR_1 "\e[0;34m @ \033[0m"
#define STRING_JOGADOR_2 "\e[0;31m O \033[0m"

Reversi::Reversi() : Tabuleiro(8, 8, STRING_JOGADOR_1, STRING_JOGADOR_2)
{
    this->_tipo = 1; // identificador para reversi

    // sempre começa com o tabuleiro assim:
    /*
        ---------------------------------
        |   |   |   |   |   |   |   |   |
        ---------------------------------
        |   |   |   |   |   |   |   |   |
        ---------------------------------
        |   |   |   |   |   |   |   |   |
        ---------------------------------
        |   |   |   | 2 | 1 |   |   |   |
        ---------------------------------
        |   |   |   | 1 | 2 |   |   |   |
        ---------------------------------
        |   |   |   |   |   |   |   |   |
        ---------------------------------
        |   |   |   |   |   |   |   |   |
        ---------------------------------
        |   |   |   |   |   |   |   |   |
        ---------------------------------
    */
    this->_board[3][3] = JOGADOR_2;
    this->_board[3][4] = JOGADOR_1;
    this->_board[4][4] = JOGADOR_2;
    this->_board[4][3] = JOGADOR_1;
}

// verifica se uma jogada é valida para um jogador na posicao x, y do tabuleiro
bool Reversi::jogadaValida(int x, int y, Casa jogador, bool posicionar = false)
{
    bool resposta = false;

    if ((x < 0 && x >= this->_x) || (y < 0 && y >= this->_y) || (this->_board[x][y] != VAZIO))
    {
        return resposta; // posicao ocupada ou fora do tabuleiro - resposta false
    }

    // direcoes possíveis para percorrer o tabuleiro e validar a jogada
    int direcoes[8][2] = {
        // direcoes horizontais
        {0, 1},
        {0, -1},
        // direcoes verticais
        {1, 0},
        {-1, 0},
        // direcoes diagonais
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1}};

    for (int i_direcao = 0; i_direcao < 8; i_direcao++)
    {
        int direcao_x = direcoes[i_direcao][0];
        int direcao_y = direcoes[i_direcao][1];
        int i_x = x + direcao_x;
        int i_y = y + direcao_y;

        bool encontrouAdversario = false;

        while (i_x >= 0 && i_x < 8 && i_y >= 0 && i_y < 8)
        {
            Casa atual = this->_board[i_x][i_y];

            if (atual == VAZIO)
            {
                break; // direcao invalida
            }

            if (atual != jogador)
            {
                encontrouAdversario = true;
            }
            else
            {
                if (encontrouAdversario)
                {
                    if (posicionar) // se quer ja posicionar, precisa reverter as casas para o jogador
                    {

                        if (x == i_x) // reversao horizontal
                        {
                            if (y <= i_y)
                            {
                                for (int j = y; j <= i_y; j++) // para direita
                                {
                                    this->_board[x][j] = jogador;
                                }
                            }
                            else
                            {
                                for (int j = y; j >= i_y; j--) // para esquerda
                                {
                                    this->_board[x][j] = jogador;
                                }
                            }
                        }
                        else
                        {

                            if (y == i_y) // reversao vertical
                            {
                                if (x <= i_x)
                                {
                                    for (int i = x; i <= i_x; i++) // para baixo
                                    {
                                        this->_board[i][y] = jogador;
                                    }
                                }
                                else
                                {
                                    for (int i = x; i >= i_x; i--) // para cima
                                    {
                                        this->_board[i][y] = jogador;
                                    }
                                }
                            }
                            else // reversao diagonais
                            {
                                if (x < i_x) // para baixo
                                {
                                    if (y < i_y) // e para direita
                                    {
                                        for (int i = x, j = y; i <= i_x && j <= i_y; i++, j++)
                                        {
                                            this->_board[i][j] = jogador;
                                        }
                                    }
                                    else // e para esquerda
                                    {
                                        for (int i = x, j = y; i <= i_x && j >= i_y; i++, j--)
                                        {
                                            this->_board[i][j] = jogador;
                                        }
                                    }
                                }
                                else // para cima
                                {
                                    if (y < i_y) // e para direita
                                    {
                                        for (int i = x, j = y; i >= i_x && j <= i_y; i--, j++)
                                        {
                                            this->_board[i][j] = jogador;
                                        }
                                    }
                                    else // e para esquerda
                                    {
                                        for (int i = x, j = y; i >= i_x && j >= i_y; i--, j--)
                                        {
                                            this->_board[i][j] = jogador;
                                        }
                                    }
                                }
                            }
                        }
                    }

                    resposta = true; // encontrou uma jogada valida, pois precisa da condicao POCICAO_JOGADA -> OPONENTE -> JOGADOR em qualquer direcao
                }
                break;
            }

            i_x += direcao_x;
            i_y += direcao_y;
        }
    }

    return resposta; // retorna a resposta se false - nenhuma jogada valida encontrada, se true - alguma jogada valida
}

// verifica se um jogador tem alguma jogada valida
bool Reversi::temJogadaValida(Casa jogador)
{
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            if (jogadaValida(x, y, jogador))
            {
                return true;
            }
        }
    }
    return false;
}

int Reversi::finalizarJogo()
{
    // varifica se os jogadores tem jogadas validas
    bool jogador1PodeJogar = temJogadaValida(JOGADOR_1);
    bool jogador2PodeJogar = temJogadaValida(JOGADOR_2);

    // se nenhum jogador pode jogar, o jogo termina
    if (!jogador1PodeJogar && !jogador2PodeJogar)
    {
        // contador de pecas no tabuleiro
        int jogador1Pecas = 0;
        int jogador2Pecas = 0;

        for (int x = 0; x < 8; x++)
        {
            for (int y = 0; y < 8; y++)
            {
                if (this->_board[x][y] == JOGADOR_1)
                {
                    jogador1Pecas++;
                }
                else if (this->_board[x][y] == JOGADOR_2)
                {
                    jogador2Pecas++;
                }
            }
        }

        if (jogador1Pecas > jogador2Pecas)
        {
            return 1; // jogador_1 venceu
        }
        else if (jogador2Pecas > jogador1Pecas)
        {
            return 2; // jogador_2 venceu
        }
        else
        {
            return 3; // empate
        }
    }

    return 0; // jogo continua
}

bool Reversi::posicionarPeca(int x, int y, int num_jogador)
{
    // valida a jogada e posicionar = true
    return jogadaValida(x, y, (Casa)num_jogador, true);
}

void Reversi::imprimeTabuleiro()
{
    Tabuleiro::imprimeTabuleiro();
    std::cout << "Formato de jogada: <Coluna> <Linha>" << std::endl;
}