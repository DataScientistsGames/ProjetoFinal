#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include "Cadastrador.hpp"
#include "CSV.hpp"
#include "Cores.hpp"

Cadastrador::Cadastrador() {}

Cadastrador::~Cadastrador() {}

std::string Cadastrador::removerJogador(std::string apelido_jogador)
{
    std::string resultado = "";

    // verifica se o jogador está registrado e apaga
    if (this->existeJogador(apelido_jogador))
    {
        CSV arq_jogadores("../src/data/jogadores.csv");
        arq_jogadores.apagarNoArquivo(apelido_jogador);
    }
    else
    {
        // std::cin.clear();
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Jogador inexistente");
    }

    // remover os dados do jogador das estatíticas (se houver)
    if (this->existeEstatistica(apelido_jogador))
    {
        CSV arq_estatisticas("../src/data/partidas.csv");
        arq_estatisticas.apagarNoArquivo(apelido_jogador);
    }

    return "Jogador " + apelido_jogador + " removido com sucesso";
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
        // std::cin.clear();
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Apelido já cadastrado");
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

bool Cadastrador::existeEstatistica(std::string apelido_jogador)
{
    CSV arquivo("../src/data/partidas.csv");
    std::string linha = arquivo.lerLinhaArquivo();
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

    std::cout << AZUL << apelido_jogador << MAGE << " " << nome_jogador << FIMCOR << std::endl;
    std::cout << "REVERSI - " << VERD << "V: " << vitorias_reversi << VERM << " D: " << derrotas_reversi << FIMCOR << std::endl;
    std::cout << "LIG4 - " << VERD << "V: " << vitorias_lig4 << VERM << " D: " << derrotas_lig4 << FIMCOR << std::endl;
    std::cout << "VELHA - " << VERD << "V: " << vitorias_velha << VERM << " D: " << derrotas_velha << FIMCOR << std::endl;
    std::cout << std::endl;
}
