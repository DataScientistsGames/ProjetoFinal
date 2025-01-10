#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Cadastrador.hpp"
#include "CSV.hpp"

Cadastrador::Cadastrador() {}

Cadastrador::~Cadastrador() {}

std::string Cadastrador::removerJogador(std::string apelido_jogador)
{
    std::string resultado = "";
    CSV arquivo("../src/data/jogadores.csv");

    if (this->existeJogador(apelido_jogador))
    {
        std::string linha = arquivo.lerLinhaArquivo();
        while (!linha.empty())
        {
            bool contem = linha.find(apelido_jogador) != std::string::npos; // corrigir erro do find
            if (contem)
            {
                arquivo.apagarNoArquivo(linha);
                break;
            }
            linha = arquivo.lerLinhaArquivo();
        }

        return "Jogador " + apelido_jogador + " removido com sucesso";
    }
    else
    {
        return "ERRO: jogador inexistente";
    }
}

std::string Cadastrador::cadastrarJogador(std::string apelido_jogador, std::string nome_jogador)
{
    // caso não tenha encontrado nenhum apelido semelhante
    if (!this->existeJogador(apelido_jogador))
    {
        std::string adicionar_no_arquivo = "";
        adicionar_no_arquivo.append(apelido_jogador);
        adicionar_no_arquivo += ',';
        adicionar_no_arquivo.append(nome_jogador);
        adicionar_no_arquivo.append(",0,0,0,0,0,0\n");

        // agora a linha está formatada no estilo "apelido,nome sobrenome,0,0\n", pronto para adicionar no arquivo de jogadores
        CSV arquivo("../src/data/jogadores.csv");
        arquivo.escreverArquivo(adicionar_no_arquivo);

        return "Jogador " + apelido_jogador + " cadastrado com sucesso";
    }
    else
    {
        return "ERRO: jogador repetido";
    }
}

void Cadastrador::listarJogador(char metodo)
{
    CSV arquivo("../src/data/jogadores.csv");

    std::vector<std::string> chaves;
    std::string linha = arquivo.lerLinhaArquivo(); // ignora a primeira linha (template)

    // adiciona todas as linhas a um vector com a chave na frente
    // a chave pode ser tanto o nome registrado quanto o apelido
    linha = arquivo.lerLinhaArquivo();
    while (!linha.empty())
    {
        std::string chave = this->adicionaChave(metodo, linha);
        chaves.push_back(chave);
        linha = arquivo.lerLinhaArquivo();
    }

    // ordena as linhas com relação a chave
    std::sort(chaves.begin(), chaves.end());

    for (const auto &jogador : chaves)
    {
        traduzChaveCSV(jogador);
    }
}

std::string Cadastrador::pegaPalavraLinha(std::string linha)
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

std::string Cadastrador::retornaLinhaJogador(std::string apelido_jogador)
{
    CSV arquivo("../src/data/jogadores.csv");

    std::string linha = arquivo.lerLinhaArquivo(); // ignora a primeira linha (template)

    while (!linha.empty())
    {
        std::string apelido = pegaPalavraLinha(linha);
        if (apelido == apelido_jogador)
        {
            return linha;
        }

        linha = arquivo.lerLinhaArquivo();
    }

    return "";
}

bool Cadastrador::existeJogador(std::string apelido_jogador)
{
    CSV arquivo("../src/data/jogadores.csv");

    std::string linha = arquivo.lerLinhaArquivo(); // ignora a primeira linha (template)

    linha = arquivo.lerLinhaArquivo();
    while (!linha.empty())
    {
        std::string apelido = pegaPalavraLinha(linha);
        if (apelido == apelido_jogador)
        {
            return true;
        }

        linha = arquivo.lerLinhaArquivo();
    }

    return false;
}

std::string Cadastrador::adicionaChave(char metodo, std::string linha)
{
    if (metodo == 'A')
    {
        std::string apelido = "";
        for (int i = 0; linha[i] != ','; i++)
        {
            apelido += linha[i];
        }

        apelido.append("," + linha);

        return apelido;
    }
    else
    {
        std::string nome = "";

        int i;
        // passa pelo apelido sem fazer nada
        for (i = 0; linha[i] != ','; i++)
        {
        }

        // pega o nome do jogador
        i++;
        for (; linha[i] != ','; i++)
        {
            nome += linha[i];
        }

        nome.append("," + linha);

        return nome;
    }
}

void Cadastrador::traduzChaveCSV(std::string linha)
{
    long unsigned int i;
    // ignora o primeiro valor (chave)
    for (i = 0; linha[i] != ','; i++)
    {
    }

    i++;
    std::string apelido_jogador = "";
    for (; linha[i] != ','; i++)
    {
        apelido_jogador += linha[i];
    }

    i++;
    std::string nome_jogador = "";
    for (; linha[i] != ','; i++)
    {
        nome_jogador += linha[i];
    }

    i++;
    std::string vitorias_velha = "";
    for (; linha[i] != ','; i++)
    {
        vitorias_velha += linha[i];
    }

    i++;
    std::string derrotas_velha = "";
    for (; linha[i] != ','; i++)
    {
        derrotas_velha += linha[i];
    }

    i++;
    std::string vitorias_reversi = "";
    for (; linha[i] != ','; i++)
    {
        vitorias_reversi += linha[i];
    }

    i++;
    std::string derrotas_reversi = "";
    for (; linha[i] != ','; i++)
    {
        derrotas_reversi += linha[i];
    }

    i++;
    std::string vitorias_lig4 = "";
    for (; linha[i] != ','; i++)
    {
        vitorias_lig4 += linha[i];
    }

    i++;
    std::string derrotas_lig4 = "";
    for (; i < linha.size(); i++)
    {
        derrotas_lig4 += linha[i];
    }

    std::cout << apelido_jogador << " " << nome_jogador << std::endl;
    std::cout << "REVERSI - V: " << vitorias_reversi << " D: " << derrotas_reversi << std::endl;
    std::cout << "LIG4 - V: " << vitorias_lig4 << " D: " << derrotas_lig4 << std::endl;
    std::cout << "VELHA - V: " << vitorias_velha << " D: " << derrotas_velha << std::endl;
    std::cout << std::endl;
}
