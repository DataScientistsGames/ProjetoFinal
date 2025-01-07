#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Controlador.hpp"
#include "Cadastrador.hpp"
#include "Comandos.hpp"
#include "Jogador.hpp"

Controlador::Controlador() {}
Controlador::~Controlador() {}

void Controlador::leitorComando(Comandos comando)
{
    switch (comando)
    {
    case CJ:
        this->cadastrarJogador();
        break;

    case RJ:
        this->removerJogador();
        break;

    case LJ:
        this->listarJogador();
        break;

    case EP:
        this->executarPartida();
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

        std::cout << "Digite um apelido: ";
        std::cin >> apelido_jogador;
        std::cin.ignore();
        std::cout << "Digite seu nome: ";
        std::getline(std::cin, nome_jogador);

        if (apelido_jogador.find(',') != std::string::npos)
        {
            resultado = "ERRO: dados incorretos";
        }
        else
        {
            Cadastrador *cadastrar = new Cadastrador;
            resultado = cadastrar->cadastrarJogador(apelido_jogador, nome_jogador);
            delete (cadastrar);
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

        std::cout << "Digite o apelido do jogador que deseja remover: ";
        std::cin >> apelido_jogador;
        /*
            caso alguem coloque o nome "Enzo Braz",
            o "Braz" volta na entrada de comando no loop e gera erro
        */
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Cadastrador *remover = new Cadastrador;

        std::string resultado = remover->removerJogador(apelido_jogador);
        std::cout << resultado << std::endl;

        delete (remover);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Controlador::listarJogador()
{
    char metodo;
    std::cout << "Digite o método pelo qual os jogadores serão listados, Apelido ou Nome (A|N): ";
    std::cin >> metodo;

    if (metodo == 'A' || metodo == 'N')
    {
        Cadastrador *listar = new Cadastrador;
        listar->listarJogador(metodo);
        delete (listar);
    }
    else
    {
        std::invalid_argument(metodo + " não é método comando válido!");
    }
}

void Controlador::executarPartida()
{
    /*
        Pegar partida
    */

    //...

    /*
        Pegar jogador
    */

    std::string _apelido_primeiro, _apelido_segundo;
    std::cin >> _apelido_primeiro >> _apelido_segundo;

    Cadastrador *retornar = new Cadastrador;
    std::string _linha_primeiro, _linha_segundo;

    // pega ambos os jogadores no CSV
    _linha_primeiro = retornar->retornaLinhaJogador(_apelido_primeiro);
    _linha_segundo = retornar->retornaLinhaJogador(_apelido_segundo);

    if (_linha_primeiro.empty() || _linha_segundo.empty())
    {
        // ERRO: jogador inexistente
    }
    else
    {
        Jogador *jogador_1 = new Jogador(_linha_primeiro, 0);
        Jogador *jogador_2 = new Jogador(_linha_segundo, 1);

        delete (jogador_1);
        delete (jogador_2);
    }
}

void Controlador::finalizarSistema()
{
    std::cout << "Finalizando...";
}
