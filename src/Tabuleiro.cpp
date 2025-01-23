#include "Tabuleiro.hpp"
#include "Casa.hpp"
#include <iostream>

Tabuleiro::Tabuleiro(int x, int y, std::string string_player1, std::string string_player2) : _x(x), _y(y), _string_pecas{" ", string_player1, string_player2}
{
    this->_board = new Casa *[x];
    for (int i = 0; i < x; ++i)
    {
        this->_board[i] = new Casa[y];
        for (int j = 0; j < y; j++)
        {
            this->_board[i][j] = VAZIO;
        }
    }
}

Tabuleiro::~Tabuleiro()
{
    for (int i = 0; i < this->_x; i++)
    {
        delete[] (this->_board[i]);
    }
    delete[] this->_board;
}

int Tabuleiro::finalizarJogo() { return 1; };

bool Tabuleiro::posicionarPeca(int x, int y, int num_jogador)
{
    if ((x >= 0 && x < this->_x) && (y >= 0 && y < this->_y) && (this->_board[x][y] == VAZIO))
    {
        this->_board[x][y] = intParaCasa(num_jogador);
        return true;
    }

    return false;
}

Casa Tabuleiro::localizarPeca(int x, int y)
{
    return this->_board[x][y];
}

Casa Tabuleiro::intParaCasa(const int num_jogador)
{
    switch (num_jogador)
    {
    case 1:
        return JOGADOR_1;
        break;

    case 2:
        return JOGADOR_2;
        break;

    default:
        return VAZIO;
        break;
    }
}

PosicaoCartesiana Tabuleiro::centralizaCoordenadas(int posX, int posY)
{
    return PosicaoCartesiana((double) posX - (this->_x-1) * 1.0/2, (double) ((this->_y-1) * 1.0/2) - posY);
}

PosicaoCartesiana Tabuleiro::calculaVies(int jogador)
{
    double somaX = 0, somaY = 0;
    int numPercorridas = 0;

    for (int i = 0; i < this->_x; i++) 
    {
        for (int j = 0; j < this->_y; j++) 
        {
            if (this->_board[i][j] == intParaCasa(jogador)) 
            {
                PosicaoCartesiana coordsCentralizadas(centralizaCoordenadas(i, j));

                somaX += coordsCentralizadas.getX();
                somaY += coordsCentralizadas.getY();

                numPercorridas++;
            }
        }
    }

    somaX /= numPercorridas;
    somaY /= numPercorridas;

    std::cout << "Viés do jogador " << jogador << " calculado" << std::endl;

    return PosicaoCartesiana(somaX, somaY);
}

int Tabuleiro::getTipo()
{
    return this->_tipo;
}

void Tabuleiro::imprimeBordaVertical()
{
    std::cout << '\t';
    for (int i = 0; i < (this->_x * 8); i++)
    // Multiplica x por 4 porque toda casa impressa vem junto com um '#' e dois espaços. Soma 1 porque existe uma parede de '#'s antes de cada linha.
    {
        std::cout << CHAR_BORDA_LINHA;
    }
    std::cout << CHAR_BORDA_LINHA;

    std::cout << std::endl;
}

void Tabuleiro::imprimeTabuleiro()
{
    std::cout << '\t';
    for (int i = 0; i < this->_x; i++)
    {
        std::cout << "    " << i + 1 << '\t';
    }
    std::cout << std::endl;

    imprimeBordaVertical();

    for (int i = 0; i < this->_y; i++)
    {
        std::cout << i + 1 << '\t';
        std::cout << CHAR_BORDA_COLUNA;
        for (int j = 0; j < this->_x; j++)
        {
            int pecaAtual = this->localizarPeca(j, i);

            std::cout << ' ' << ' ' << this->_string_pecas[pecaAtual] << '\t' << CHAR_BORDA_COLUNA;
        }

        std::cout << std::endl;
        imprimeBordaVertical();
    }
}

// esse método só será sobrescrito na classe Reversi, já que é o único jogo que possibilita não ter jogadas válidas
bool Tabuleiro::temJogadaValida(Casa jogador)
{
    return true;
}