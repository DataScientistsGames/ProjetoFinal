#include "Estatistica.hpp"
#include "Jogador.hpp"
#include "CSV.hpp"
#include "Cores.hpp"
#include "CoutComuns.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

void Estatistica::calculaEstatisticasJogador(std::string linha_jogador)
{
    CoutComuns::limparCmd();
    Jogador jogador(linha_jogador);

    std::vector<int> media_vitoria;

    media_vitoria.push_back(jogador.getVitoriasV());
    media_vitoria.push_back(jogador.getVitoriasR());
    media_vitoria.push_back(jogador.getVitoriasL());

    std::cout << "Média de vitórias: " << VERD << Estatistica::media(media_vitoria) << FIMCOR << std::endl;

    std::vector<int> media_derrota;

    media_derrota.push_back(jogador.getDerrotasV());
    media_derrota.push_back(jogador.getDerrotasR());
    media_derrota.push_back(jogador.getDerrotasL());

    std::cout << "Média de derrotas: " << VERD << Estatistica::media(media_derrota) << FIMCOR << std::endl;

    std::vector<double> vies_v = Estatistica::vies(jogador.getApelido(), 'V');
    std::vector<double> vies_r = Estatistica::vies(jogador.getApelido(), 'R');
    std::vector<double> vies_l = Estatistica::vies(jogador.getApelido(), 'L');

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Viés Jogador Velha: " << VERD << vies_v[0] << FIMCOR << " na direção " << AZUL << "X" << FIMCOR << " e "
              << VERD << vies_v[1] << FIMCOR << " na direção " << MAGE << "Y" << FIMCOR << "." << std::endl;
    std::cout << "Viés Jogador Reversi: " << VERD << vies_r[0] << FIMCOR << " na direção " << AZUL << "X" << FIMCOR << " e "
              << VERD << vies_r[1] << FIMCOR << " na direção " << MAGE << "Y" << FIMCOR << "." << std::endl;
    std::cout << "Viés Jogador Lig4: " << VERD << vies_l[0] << FIMCOR << " na direção " << AZUL << "X" << FIMCOR << " e "
              << VERD << vies_l[1] << FIMCOR << " na direção " << MAGE << "Y" << FIMCOR << "." << std::endl;

    std::vector<double> valores_v;

    valores_v.push_back(jogador.getVitoriasV());
    valores_v.push_back(jogador.getDerrotasV());

    std::vector<double> valores_r;

    valores_r.push_back(jogador.getVitoriasR());
    valores_r.push_back(jogador.getDerrotasR());

    std::vector<double> valores_l;

    valores_l.push_back(jogador.getVitoriasL());
    valores_l.push_back(jogador.getDerrotasL());

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Proporcao de Vitórias Velha: " << VERD << Estatistica::proporcao(valores_v) << FIMCOR << std::endl;
    std::cout << "Proporcao de Vitórias Reversi: " << VERD << Estatistica::proporcao(valores_r) << FIMCOR << std::endl;
    std::cout << "Proporcao de Vitórias Lig4: " << VERD << Estatistica::proporcao(valores_l) << FIMCOR << std::endl;
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

double Estatistica::proporcao(std::vector<double> valores)
{
    int n = valores[0] + valores[1];
    return valores[0] / n;
}

std::vector<double> Estatistica::vies(std::string apelido_jogador, char jogo)
{
    try
    {
        std::vector<double> vies;
        double vies_x = 0, vies_y = 0, n = 0;
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
                    n += 1;
                }
            }

            linha = arquivo_partidas.lerLinhaArquivo();
        }

        vies.push_back(vies_x / n);
        vies.push_back(vies_y / n);

        return vies;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << VERM << "ERRO:" << e.what() << '\n'
                  << "Impossível Calcular viés." << FIMCOR;
        std::vector<double> vies;
        CoutComuns::espereEnter();
        vies.push_back(0);
        vies.push_back(0);
        return vies;
    }
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
    char jogo = linha[linha.size() - 1];
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