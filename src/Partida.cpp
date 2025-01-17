#include <iostream>
#include <vector>
#include <string>
#include "Partida.hpp"
#include "Jogador.hpp"
#include "Velha.hpp"
#include "Lig4.hpp"
#include "Reversi.hpp"
#include "CSV.hpp"
#include "CoutComuns.hpp" // helper do embelezamento do cmd

Partida::Partida(std::unique_ptr<Tabuleiro> tabuleiro, std::unique_ptr<Jogador> player1, std::unique_ptr<Jogador> player2) : _rounds(0)
{

    this->_tabuleiro = std::move(tabuleiro);
    this->_player1 = std::move(player1);
    this->_player2 = std::move(player2);
    this->round();
}

Partida::~Partida() {}

void Partida::round()
{
    int registro = this->_tabuleiro->finalizarJogo();
    while (registro == 0)
    {
        if (this->_rounds % 2 == 0)
            this->leitorJogada(1);

        else
            this->leitorJogada(2);

        this->_rounds++;
        registro = this->_tabuleiro->finalizarJogo();
    }
    this->finalizarPartida(registro);
}

void Partida::leitorJogada(int num_jogador)
{
    bool valido = false;
    bool jogada_possivel = true;
    int linha = 0, coluna;
    while (!valido)
    {
        this->_tabuleiro->imprimeTabuleiro();
        jogada_possivel = this->_tabuleiro->temJogadaValida(this->_tabuleiro->stringParaCasa(num_jogador));

        if (!jogada_possivel)
        {
            std::cout << "Infelizmente o jogador " << num_jogador << " não tem jogadas possíveis." << std::endl;
            CoutComuns::espereEnter();
            break;
        }

        std::cout << "Jogador " << num_jogador << "! É a sua vez:";

        if(this->_tabuleiro->getTipo() == 2) 
        {
            std::cin >> coluna;
            coluna--;
        }
        else
        {
            std::cin >> coluna >> linha;
            coluna--;
            linha--;
        }

        valido = this->_tabuleiro->posicionarPeca(coluna, linha, num_jogador);
        if (!valido)
            std::cout << "Jogada inválida" << std::endl;
    }
};

void Partida::finalizarPartida(int vencedor)
{

    if (vencedor == 1)
    {
        std::cout << this->_player1->getApelido() << " foi o vencedor!" << std::endl;
        std::cout << this->_player2->getApelido() << " foi o derrotado." << std::endl;
        this->atualizaDadosJogador(std::move(this->_player1), std::move(this->_player2));
    }

    else if (vencedor == 2)
    {
        std::cout << this->_player2->getApelido() << " foi o vencedor!" << std::endl;
        std::cout << this->_player1->getApelido() << " foi o derrotado." << std::endl;
        this->atualizaDadosJogador(std::move(this->_player2), std::move(this->_player1));
    }
    else // empate
    {
        std::cout << "A partida terminou em empate!" << std::endl;
        this->atualizaDadosPartida();
    }
};

void Partida::atualizaDadosJogador(std::unique_ptr<Jogador> jogador_vencedor, std::unique_ptr<Jogador> jogador_perdedor)
{
    int vitoriasV = jogador_vencedor->getVitoriasV();
    int vitoriasR = jogador_vencedor->getVitoriasR();
    int vitoriasL = jogador_vencedor->getVitoriasL();
    int derrotasV = jogador_perdedor->getDerrotasV();
    int derrotasR = jogador_perdedor->getDerrotasR();
    int derrotasL = jogador_perdedor->getDerrotasL();

    if (this->_tabuleiro->getTipo() == 0)
    {
        vitoriasV++;
        derrotasV++;
    }
    else if (this->_tabuleiro->getTipo() == 1)
    {
        vitoriasR++;
        derrotasR++;
    }
    else
    {
        vitoriasL++;
        derrotasL++;
    }

    // string vitoria
    std::string adicionar_vitoria = "";
    adicionar_vitoria.append(jogador_vencedor->getApelido());
    adicionar_vitoria += ',';
    adicionar_vitoria.append(jogador_vencedor->getNome());
    adicionar_vitoria += ',';
    adicionar_vitoria.append(std::to_string(vitoriasV));
    adicionar_vitoria += ',';
    adicionar_vitoria.append(std::to_string(jogador_vencedor->getDerrotasV()));
    adicionar_vitoria += ',';
    adicionar_vitoria.append(std::to_string(vitoriasR));
    adicionar_vitoria += ',';
    adicionar_vitoria.append(std::to_string(jogador_vencedor->getDerrotasR()));
    adicionar_vitoria += ',';
    adicionar_vitoria.append(std::to_string(vitoriasL));
    adicionar_vitoria += ',';
    adicionar_vitoria.append(std::to_string(jogador_vencedor->getDerrotasL()));

    // string derrota
    std::string adicionar_derrota = "";
    adicionar_derrota.append(jogador_perdedor->getApelido());
    adicionar_derrota += ',';
    adicionar_derrota.append(jogador_perdedor->getNome());
    adicionar_derrota += ',';
    adicionar_derrota.append(std::to_string(jogador_perdedor->getVitoriasV()));
    adicionar_derrota += ',';
    adicionar_derrota.append(std::to_string(derrotasV));
    adicionar_derrota += ',';
    adicionar_derrota.append(std::to_string(jogador_perdedor->getVitoriasR()));
    adicionar_derrota += ',';
    adicionar_derrota.append(std::to_string(derrotasR));
    adicionar_derrota += ',';
    adicionar_derrota.append(std::to_string(jogador_perdedor->getVitoriasL()));
    adicionar_derrota += ',';
    adicionar_derrota.append(std::to_string(derrotasL));

    CSV *arquivo_vitoria = new CSV("../src/data/jogadores.csv");
    arquivo_vitoria->atualizarNoArquivo(jogador_vencedor->getApelido(), adicionar_vitoria);
    delete (arquivo_vitoria);

    CSV *arquivo_derrota = new CSV("../src/data/jogadores.csv");
    arquivo_derrota->atualizarNoArquivo(jogador_perdedor->getApelido(), adicionar_derrota);
    delete (arquivo_derrota);

    std::cout << "Dados jogador atualizados." << std::endl;
    this->atualizaDadosPartida(std::move(jogador_vencedor), std::move(jogador_perdedor));
};

void Partida::atualizaDadosPartida(std::unique_ptr<Jogador> jogador_vencedor, std::unique_ptr<Jogador> jogador_perdedor)
{
    CSV arquivo_partidas("../src/data/partidas.csv");

    char jogo;
    if (this->_tabuleiro->getTipo() == 0)
    {
        jogo = 'V';
    }
    else if (this->_tabuleiro->getTipo() == 1)
    {
        jogo = 'R';
    }
    else
    {
        jogo = 'L';
    }

    PosicaoCartesiana vies_ganhador = this->_tabuleiro->calculaVies(1);

    std::string adicionar_vitoria = "";
    adicionar_vitoria.append(jogador_vencedor->getApelido());
    adicionar_vitoria += ',';
    adicionar_vitoria.append("Vencedor");
    adicionar_vitoria += ',';
    adicionar_vitoria.append(std::to_string(vies_ganhador.getX()));
    adicionar_vitoria += ',';
    adicionar_vitoria.append(std::to_string(vies_ganhador.getY()));
    adicionar_vitoria += ',';
    adicionar_vitoria += jogo;
    adicionar_vitoria += '\n';

    arquivo_partidas.escreverArquivo(adicionar_vitoria);

    PosicaoCartesiana vies_perdedor = this->_tabuleiro->calculaVies(2);

    std::string adicionar_derrota = "";
    adicionar_derrota.append(jogador_perdedor->getApelido());
    adicionar_derrota += ',';
    adicionar_derrota.append("Derrotado");
    adicionar_derrota += ',';
    adicionar_derrota.append(std::to_string(vies_perdedor.getX()));
    adicionar_derrota += ',';
    adicionar_derrota.append(std::to_string(vies_perdedor.getY()));
    adicionar_derrota += ',';
    adicionar_derrota += jogo;
    adicionar_derrota += '\n';

    arquivo_partidas.escreverArquivo(adicionar_derrota);
    std::cout << "Dados partida atualizados." << std::endl;
};

void Partida::atualizaDadosPartida()
{
    CSV arquivo_partidas("../src/data/partidas.csv");

    char jogo;
    if (this->_tabuleiro->getTipo() == 0)
    {
        jogo = 'V';
    }
    else if (this->_tabuleiro->getTipo() == 1)
    {
        jogo = 'R';
    }
    else
    {
        jogo = 'L';
    }

    PosicaoCartesiana vies_1 = this->_tabuleiro->calculaVies(1);
    PosicaoCartesiana vies_2 = this->_tabuleiro->calculaVies(2);

    std::string linha_1 = "";
    linha_1.append(this->_player1->getApelido());
    linha_1.append(",Empate,");
    linha_1.append(std::to_string(vies_1.getX()));
    linha_1 += ',';
    linha_1.append(std::to_string(vies_1.getY()));
    linha_1 += ',';
    linha_1 += jogo;
    linha_1 += '\n';

    arquivo_partidas.escreverArquivo(linha_1);

    std::string linha_2 = "";
    linha_2.append(this->_player2->getApelido());
    linha_2.append(",Empate,");
    linha_2.append(std::to_string(vies_2.getX()));
    linha_2 += ',';
    linha_2.append(std::to_string(vies_2.getY()));
    linha_2 += ',';
    linha_2 += jogo;
    linha_2 += '\n';

    arquivo_partidas.escreverArquivo(linha_2);

    std::cout << "Dados partida atualizados." << std::endl;
}