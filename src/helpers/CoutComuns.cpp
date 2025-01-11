#include <iostream>

void displayComandos()
{
    std::cout << "----------------[C O M A N D O S]----------------" << std::endl;
    std::cout << "  CJ <Apelido> <Nome> - Cadastrar Jogador" << std::endl;
    std::cout << "  RJ <Apelido> - Remover Jogador" << std::endl;
    std::cout << "  LJ [A|N] - Listar Jogador por Apelido ou Nome" << std::endl;
    std::cout << "  EP [R|L|V] <Apelido Jogador 1> <Apelido Jogador 2> - Executar Partida de Reversi, Lig4 ou Jogo da Velha" << std::endl;
    std::cout << "  FS - Finalizar Sistema" << std::endl;
    std::cout << "----------[DIGITE DA MANEIRA INFORMADA]----------" << std::endl;
}

void espereEnter()
{
    std::cout << "Pressione Enter para continuar...";
    std::cin.ignore(); // Ignora o buffer restante
    std::cin.get();    // Aguarda Enter
}

void limparCmd()
{
#ifdef _WIN32
    system("cls"); // Comando para Windows
#else
    system("clear"); // Comando para Linux/Mac
#endif
}
