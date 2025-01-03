#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <csignal>
#include "Controlador.hpp"
#include "Comandos.hpp"
#include "CSV.hpp"

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
    std::string nome_jogador;
    std::string apelido_jogador;

    std::cout << "Digite um apelido: ";
    std::cin >> apelido_jogador;
    std::cin.ignore();
    std::cout << "Digite seu nome: ";
    std::getline(std::cin, nome_jogador);

    std::cout << nome_jogador << std::endl
              << apelido_jogador << std::endl;

    // abrir o arquivo de jogadores
    CSV arquivo("../src/data/jogadores.csv");

    // verificar se há jogador com nome igual
    bool nome_unico = true;
    std::string linha = arquivo.lerLinhaArquivo();
    while (!linha.empty())
    {
        std::string apelido = pegaPalavraLinha(linha);
        if (apelido == apelido_jogador)
        {
            nome_unico = false;
        }

        linha = arquivo.lerLinhaArquivo();
    }

    // caso não tenha encontrado nenhum apelido semelhante
    if (nome_unico == true)
    {
        std::string adicionar_no_arquivo = "";
        adicionar_no_arquivo.append(apelido_jogador);
        adicionar_no_arquivo += ',';
        adicionar_no_arquivo.append(nome_jogador);
        adicionar_no_arquivo.append(",0,0\n");
        // agora a linha está formatada no estilo "apelido,nome sobrenome,0,0\n", pronto para adicionar no arquivo de jogadores
        arquivo.escreverArquivo(adicionar_no_arquivo);
    }
}

void Controlador::removerJogador()
{
}

void Controlador::listarJogador()
{
}

void Controlador::executarPartida()
{
}

void Controlador::finalizarSistema()
{
}

std::string Controlador::traduzCSV(std::string linha)
{
    for (long unsigned int i = 0; i < linha.size(); i++)
    {
        if (linha[i] == ',')
        {
            linha[i] = ' ';
        }
    }
    return linha;
}

std::string Controlador::pegaPalavraLinha(std::string linha)
{
    std::string palavra = "";
    int i = 0;
    while (linha[i] != ',')
    {
        palavra += linha[i];
        i++;
    }
    return palavra;
}