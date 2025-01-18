#include "CoutComuns.hpp"
#include "Cores.hpp"
#include <iostream>

void CoutComuns::displayComandos()
{
    std::cout << AMAR;
    std::cout << "----------------[C O M A N D O S]----------------" << std::endl;
    std::cout << "  CJ <Apelido> <Nome> - Cadastrar Jogador" << std::endl;
    std::cout << "  RJ <Apelido> - Remover Jogador" << std::endl;
    std::cout << "  LJ [A|N] - Listar Jogador por Apelido ou Nome" << std::endl;
    std::cout << "  EP [R|L|V] <Apelido Jogador 1> <Apelido Jogador 2> - Executar Partida de Reversi, Lig4 ou Jogo da Velha" << std::endl;
    std::cout << "  EST <Apelido Jogador> - Calcula e mostra as estatísticas do Jogador " << std::endl;
    std::cout << "  FS - Finalizar Sistema" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << FIMCOR;
}

void CoutComuns::espereEnter()
{
    std::cin.clear(); // Ignora o buffer restante
    std::cout << "Pressione Enter para continuar...";
    std::cin.get(); // Aguarda Enter
}

void CoutComuns::limparCmd()
{
#ifdef _WIN32
    system("cls"); // Comando para Windows
#else
    system("clear"); // Comando para Linux/Mac
#endif
}