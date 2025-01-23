#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <memory>
#include "Controlador.hpp"
#include "CoutComuns.hpp" // helper do embelezamento do cmd
#include "Cadastrador.hpp"
#include "Comandos.hpp"
#include "Jogador.hpp"
#include "Estatistica.hpp"
#include "Tabuleiro.hpp"
#include "Reversi.hpp"
#include "Lig4.hpp"
#include "Velha.hpp"
#include "Partida.hpp"
#include "Cores.hpp"

Controlador::Controlador() {}
Controlador::~Controlador() {}

void Controlador::leitorComando(Comandos comando)
{
    switch (comando)
    {
    case CJ:

        this->cadastrarJogador();
        CoutComuns::espereEnter();
        CoutComuns::limparCmd();
        break;

    case RJ:
        this->removerJogador();
        CoutComuns::limpaBuffer();
        CoutComuns::espereEnter();
        CoutComuns::limparCmd();
        break;

    case LJ:
        CoutComuns::limparCmd();
        this->listarJogador();
        CoutComuns::limpaBuffer();
        CoutComuns::espereEnter();
        CoutComuns::limparCmd();
        break;

    case EP:
        this->executarPartida();
        CoutComuns::limpaBuffer();
        CoutComuns::espereEnter();
        CoutComuns::limparCmd();
        break;

    case EST:
        CoutComuns::limparCmd();
        this->estatisticasJogador();
        CoutComuns::limpaBuffer();
        CoutComuns::espereEnter();
        CoutComuns::limparCmd();
        break;

    case FS:
        CoutComuns::limparCmd();
        this->finalizarSistema();
        break;

    default:
        throw std::invalid_argument("Comando inválido!");
        break;
    }
}

void Controlador::cadastrarJogador()
{
    std::string resultado;
    std::string nome_jogador;
    std::string apelido_jogador;

    std::cin >> apelido_jogador;
    std::getline(std::cin, nome_jogador);

    if ((apelido_jogador.find(',') != std::string::npos) || (nome_jogador.find(',') != std::string::npos))
    {
        if (!std::cin.eof())
        {
            std::cin.clear();
            std::cout << VERM << "Buffer corrompido, precione enter para ler o erro..." << FIMCOR;
        }
        throw std::invalid_argument("Caractere (,) não permitido");
    }
    else
    {
        std::unique_ptr<Cadastrador> cadastrar(new Cadastrador);
        resultado = cadastrar->cadastrarJogador(apelido_jogador, nome_jogador);
    }

    std::cout << resultado << std::endl;
}

void Controlador::removerJogador()
{
    std::string apelido_jogador;
    std::cin >> apelido_jogador;


    std::unique_ptr<Cadastrador> remover(new Cadastrador);

    std::string resultado = remover->removerJogador(apelido_jogador);
    std::cout << resultado << std::endl;
}

void Controlador::listarJogador()
{
    char metodo;
    std::cin >> metodo;

    if (metodo == 'A' || metodo == 'N')
    {
        std::unique_ptr<Cadastrador> listar(new Cadastrador);
        listar->listarJogador(metodo);
    }
    else
    {
        throw std::invalid_argument("O método digitado não é válido");
    }
}

void Controlador::executarPartida()
{
    /*
        Pegar jogo
    */
    std::unique_ptr<Tabuleiro> tabuleiro;
    char nome_jogo;
    std::cin >> nome_jogo;
    switch (nome_jogo)
    {
    case 'R':
        tabuleiro = std::unique_ptr<Tabuleiro>(new Reversi());
        break;
    case 'L':
        tabuleiro = std::unique_ptr<Tabuleiro>(new Lig4());
        break;
    case 'V':
        tabuleiro = std::unique_ptr<Tabuleiro>(new Velha());
        break;
    default:
        throw std::invalid_argument("O jogo digitado não existe.");
        break;
    }

    /*
        Pegar jogador
    */
    std::string apelido_primeiro, apelido_segundo;
    std::cin >> apelido_primeiro >> apelido_segundo;

    if (apelido_primeiro == apelido_segundo)
    {
        // std::cin.clear();
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("jogadores repetidos.");
    }

    std::unique_ptr<Cadastrador> retornar(new Cadastrador);
    std::string linha_primeiro, linha_segundo;

    linha_primeiro = retornar->retornaLinhaJogador(apelido_primeiro);
    linha_segundo = retornar->retornaLinhaJogador(apelido_segundo);

    std::unique_ptr<Jogador> jogador_1;
    std::unique_ptr<Jogador> jogador_2;

    if (linha_primeiro.empty() || linha_segundo.empty())
    {
        // std::cin.clear();
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("jogador não encontrado.");
    }
    else
    {
        jogador_1 = std::unique_ptr<Jogador>(new Jogador(linha_primeiro));
        jogador_2 = std::unique_ptr<Jogador>(new Jogador(linha_segundo));
    }

    Partida partida(std::move(tabuleiro), std::move(jogador_1), std::move(jogador_2));
}

void Controlador::estatisticasJogador()
{
    std::string apelido;
    std::cin >> apelido;

    std::string linha_jogador;

    std::unique_ptr<Cadastrador> retornar;

    linha_jogador = retornar->retornaLinhaJogador(apelido);

    if (linha_jogador.empty())
    {
        throw std::invalid_argument("jogador não encontrado.");
    }

    else
    {
        Estatistica::calculaEstatisticasJogador(linha_jogador);
    }
}

void Controlador::finalizarSistema()
{
    std::cout << VERD << "Finalizando..." << FIMCOR << std::endl;
}
