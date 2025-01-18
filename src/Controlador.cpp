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
        CoutComuns::espereEnter();
        CoutComuns::limparCmd();
        break;

    case LJ:
        this->listarJogador();
        CoutComuns::espereEnter();
        CoutComuns::limparCmd();
        break;

    case EP:
        this->executarPartida();
        CoutComuns::espereEnter();
        CoutComuns::limparCmd();
        break;

    case EST:
        this->estatisticasJogador();
        CoutComuns::espereEnter();
        CoutComuns::limparCmd();
        break;

    case FS:
        this->finalizarSistema();
        break;

    default:
        throw std::invalid_argument("Comando inválido!");
        break;
    }
}

void Controlador::cadastrarJogador()
{
    try
    {
        std::string resultado;
        std::string nome_jogador;
        std::string apelido_jogador;

        std::cin >> apelido_jogador;
        std::cin.ignore();
        std::getline(std::cin, nome_jogador);

        if (apelido_jogador.find(',') != std::string::npos)
        {
            resultado = "ERRO: dados incorretos";
        }
        else
        {
            std::unique_ptr<Cadastrador> cadastrar(new Cadastrador);
            resultado = cadastrar->cadastrarJogador(apelido_jogador, nome_jogador);
        }

        std::cout << resultado << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Controlador::removerJogador()
{
    try
    {
        std::string apelido_jogador;
        std::cin >> apelido_jogador;
        /*
            caso alguem coloque o nome "Enzo Braz",
            o "Braz" volta na entrada de comando no loop e gera erro
        */
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::unique_ptr<Cadastrador> remover(new Cadastrador);

        std::string resultado = remover->removerJogador(apelido_jogador);
        std::cout << resultado << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
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
        std::invalid_argument(metodo + " não é método comando válido!");
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
        throw std::invalid_argument("ERRO: dados incorretos");
        break;
    }

    /*
        Pegar jogador
    */
    std::string apelido_primeiro, apelido_segundo;
    std::cin >> apelido_primeiro >> apelido_segundo;

    if (apelido_primeiro == apelido_segundo)
    {
        throw std::invalid_argument("ERRO: jogadores repetidos");
    }

    std::unique_ptr<Cadastrador> retornar(new Cadastrador);
    std::string linha_primeiro, linha_segundo;

    linha_primeiro = retornar->retornaLinhaJogador(apelido_primeiro);
    linha_segundo = retornar->retornaLinhaJogador(apelido_segundo);

    std::unique_ptr<Jogador> jogador_1;
    std::unique_ptr<Jogador> jogador_2;

    if (linha_primeiro.empty() || linha_segundo.empty())
    {
        throw std::invalid_argument("ERRO: jogador não encontrado");
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
        throw std::invalid_argument("ERRO: jogador não encontrado");
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
