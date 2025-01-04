#include <iostream>
#include <fstream>
#include <string>
#include "Controlador.hpp"
#include "Cadastrador.hpp"
#include "Comandos.hpp"

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
        std::string nome_jogador;
        std::string apelido_jogador;

        std::cout << "Digite um apelido: ";
        std::cin >> apelido_jogador;
        std::cin.ignore();
        std::cout << "Digite seu nome: ";
        std::getline(std::cin, nome_jogador);

        Cadastrador *cadastrar = new Cadastrador;
        std::string resultado = cadastrar->cadastrarJogador(apelido_jogador, nome_jogador);
        std::cout << resultado << std::endl;

        delete (cadastrar);
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
}

void Controlador::finalizarSistema()
{
}
