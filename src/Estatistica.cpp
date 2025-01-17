#include "Estatistica.hpp"
#include "Jogador.hpp"
#include "CSV.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

void Estatistica::calculaEstatisticasJogador(std::string linha_jogador)
{
    Jogador jogador(linha_jogador);

    std::vector<int> media_vitoria;

    media_vitoria.push_back(jogador.getVitoriasV());
    media_vitoria.push_back(jogador.getVitoriasR());
    media_vitoria.push_back(jogador.getVitoriasL());

    std::cout << "Média de vitórias: " << Estatistica::media(media_vitoria) << std::endl;

    std::vector<int> media_derrota;

    media_derrota.push_back(jogador.getDerrotasV());
    media_derrota.push_back(jogador.getDerrotasR());
    media_derrota.push_back(jogador.getDerrotasL());

    std::cout << "Média de derrotas: " << Estatistica::media(media_derrota) << std::endl;

    std::vector<double> vies_v = Estatistica::vies(jogador.getApelido(), 'V');
    std::vector<double> vies_r = Estatistica::vies(jogador.getApelido(), 'R');
    std::vector<double> vies_l = Estatistica::vies(jogador.getApelido(), 'L');

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Viés Jogador Velha: " << vies_v[0] << " na direção X e " << vies_v[1] << " na direção Y." << std::endl;
    std::cout << "Viés Jogador Reversi: " << vies_r[0] << " na direção X e " << vies_r[1] << " na direção Y." << std::endl;
    std::cout << "Viés Jogador Lig4: " << vies_l[0] << " na direção X e " << vies_l[1] << " na direção Y." << std::endl;

    std::vector<int> valores_v;

    valores_v.push_back(jogador.getVitoriasV());
    valores_v.push_back(jogador.getDerrotasV());

    std::vector<int> valores_r;

    valores_r.push_back(jogador.getVitoriasR());
    valores_r.push_back(jogador.getDerrotasR());

    std::vector<int> valores_l;

    valores_l.push_back(jogador.getVitoriasL());
    valores_l.push_back(jogador.getDerrotasL());

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Porcentagem de Vitórias Velha: " << Estatistica::porcentagem(valores_v) << std::endl;
    std::cout << "Porcentagem de Vitórias Reversi: " << Estatistica::porcentagem(valores_r) << std::endl;
    std::cout << "Porcentagem de Vitórias Lig4: " << Estatistica::porcentagem(valores_l) << std::endl;
}

double Estatistica::media(std::vector<int> valores)
{
    int tamanho = valores.size();
    double media = 0;
    for (auto &i : valores)
    {
        media += i;
    }

    return media / tamanho;
}

double Estatistica::porcentagem(std::vector<int> valores)
{
    return valores[0] / valores[1];
}

std::vector<double> Estatistica::vies(std::string apelido_jogador, char jogo)
{

    std::vector<double> vies;
    int vies_x = 0, vies_y = 0, n = 0;
    CSV arquivo_partidas("../src/data/partidas.csv");

    std::string linha = arquivo_partidas.lerLinhaArquivo(); // ignora a primeira linha (template)

    linha = arquivo_partidas.lerLinhaArquivo();
    while (!linha.empty())
    {
        std::string apelido_linha = Estatistica::pegaApelido(linha);
        if (apelido_linha == apelido_jogador)
        {
            if (jogo == Estatistica::pegaJogo(linha))
            {
                vies_x += Estatistica::pegaVies(linha, 'X');
                vies_y += Estatistica::pegaVies(linha, 'Y');
                n++;
            }
        }

        linha = arquivo_partidas.lerLinhaArquivo();
    }

    vies.push_back(vies_x * 1.0 / n * 1.0);
    vies.push_back(vies_y * 1.0 / n * 1.0);

    return vies;
}

std::string Estatistica::pegaApelido(std::string linha)
{
    std::string apelido = "";
    int i = 0;
    while (linha[i] != ',')
    {
        apelido += linha[i];
        i++;
    }
    return apelido;
}

char Estatistica::pegaJogo(std::string linha)
{
    char jogo;
    int i = 0;
    while (linha[i] != '\n')
    {
        jogo = linha[i];
        i++;
    }
    return jogo;
}

int Estatistica::pegaVies(std::string linha, char direcao)
{
    int vies = 0;
    long unsigned int i;
    std::string vies_s = "";

    for (i = 0; linha[i] != ','; i++)
    {
    }

    i++;

    for (; linha[i] != ','; i++)
    {
    }

    i++;

    for (; linha[i] != ','; i++)
    {
        vies_s += linha[i];
    }

    if (direcao == 'X')
    {
        vies = std::stoi(vies_s);
        return vies;
    }

    vies_s.clear();

    i++;

    for (; linha[i] != ','; i++)
    {
        vies_s += linha[i];
    }

    vies = std::stoi(vies_s);

    return vies;
}