#ifndef CSV_H
#define CSV_H

#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Classe comunicadora entre os arquivos CSV e as outras classes
 */
class CSV
{
private:
    std::string _arquivo_nome;
    std::fstream _arquivo;

public:

    /**
     * @brief Construtor padrão da classe
     * @param caminho Caminho do arquivo que deve ser lido
     * @exception Se auto-destrói e retorna exceção a ser tratada na main caso haja erro ao tentar acessar o arquivo
     */
    CSV(std::string caminho);

    /**
     * @brief Destrutor padrão que fecha o arquivo
     */
    ~CSV();

    /**
     * @brief Escreve no arquivo referente ao objeto
     * @param entrada Linha que será escrita no arquivo
     */
    void escreverArquivo(std::string entrada);

    
    /**
     * @brief Remove do arquivo referente ao objeto
     * @param apelido Apelido da linha que será removida
     */
    void apagarNoArquivo(std::string apelido);

    /**
     * @brief Substitui uma linha por outra no arquivo
     * @param apelido_jogador Apelido da linha que será removida
     * @param novos_dados Linha que será colocada no lugar da removida
     */
    void atualizarNoArquivo(std::string apelido_jogador, std::string novos_dados);

    /**
     * @brief Lê o apelido de uma linha do arquivo.
     * @param linha Linha que será lida.
     * @return Retorna o apelido da linha.
     */
    std::string pegaApelidoLinha(std::string linha);

    
    /**
     * @brief Lê uma linha do arquivo
     * @return Retorna a linha lida ou não retorna nada caso tenha atingido o fim do arquivo.
     */
    std::string lerLinhaArquivo();
};

#endif