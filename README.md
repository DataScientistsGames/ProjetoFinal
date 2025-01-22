# Projeto Final - Jogos de Tabuleiro (PDS II)

## Descrição Geral do Sistema
Este é um sistema que implementa três jogos de tabuleiro clássicos usando o paradigma de orientação a objetos em C++:

- **Jogo da Velha:** Um tabuleiro 3x3 onde dois jogadores tentam alinhar três peças consecutivas (horizontal, vertical ou diagonalmente).
- **Lig4:** Um tabuleiro 6x7 onde dois jogadores alternam turnos para tentar alinhar quatro peças consecutivas (horizontal, vertical ou diagonalmente).
- **Reversi:** Um tabuleiro 8x8 onde os jogadores colocam peças para capturar as do oponente, cercando-as em linhas, colunas ou diagonais.

### Funcionalidades Principais
1. **Hierarquia de Classes:**
   - Uma classe base abstrata `Tabuleiro` e classes derivadas para cada jogo.
   - Uso de herança, polimorfismo e encapsulamento para organização do código.

2. **Cadastro de Jogadores:**
   - Registra jogadores com nome e apelido único em um arquivo CSV.
   - Mantém estatísticas de vitórias e derrotas para cada jogo.

3. **Execução de Partidas:**
   - Permite jogar partidas entre dois jogadores com validações de jogadas e atualização do tabuleiro.

4. **Documentação (Doxygen):**
   - Gera uma documentação das classes e funções do projeto.

---

## Estrutura do Diretório
O projeto segue a seguinte organização:

```
ProjetoFinal/
|-- bin/           # Executáveis gerados pela compilação
|-- doc/           # Arquivos de documentação gerados pelo Doxygen
|-- include/       # Arquivos de cabeçalho (.hpp)
|-- src/           # Arquivos de código-fonte e de dados (.cpp/.csv)
|-- obj/           # Arquivos objeto gerados na compilação
|-- Doxyfile       # Configuração para geração da documentação Doxygen
|-- Makefile       # Arquivo de automação de compilação
|-- README.md      # Informações gerais sobre o projeto
```

---

## Como Compilar o Projeto

Este projeto utiliza um **Makefile** para facilitar a compilação. Certifique-se de ter o compilador g++ instalado no sistema.

### Passos para Compilar:
1. Clone o repositório do projeto:
   ```bash
   git clone <URL_DO_REPOSITORIO>
   cd ProjetoFinal
   ```

2. Execute o comando `make` para compilar o projeto:
   ```bash
   make
   ```
   Os executáveis serão gerados na pasta `bin/`.

3. Para limpar os arquivos gerados (objetos e executáveis):
   ```bash
   make clean
   ```

---

## Como Rodar o Projeto

Os executáveis estão localizados na pasta `bin/`. A execução do sistema segue o seguinte formato:

```bash
./bin/sistema
```

### Comandos Disponíveis no Sistema
1. **Cadastrar Jogador:**
   ```
   CJ <Apelido> <Nome>
   ```
   Exemplo: `CJ joaozinho João`

2. **Remover Jogador:**
   ```
   RJ <Apelido>
   ```
   Exemplo: `RJ joaozinho`

3. **Listar Jogadores:**
   ```
   LJ [A|N]
   ```
   Exemplo: `LJ A` (ordena por apelido).

4. **Executar Partida:**
   ```
   EP <Jogo: (V|L|R)> <Apelido Jogador1> <Apelido Jogador2>
   ```
   Exemplo: `EP L joaozinho gabriel` (inicia uma partida de Lig4).

5. **Calcular e mostrar as estatísticas de um Jogador:**
   ```
   EST <Apelido>
   ```
   Exemplo: `EST joaozinho`

6. **Finalizar Sistema:**
   ```
   FS
   ```

---

## Como Gerar a Documentação com Doxygen
Este projeto utiliza o **Doxygen** para documentar o código.

### Passos para Gerar a Documentação:
1. Certifique-se de que o Doxygen está instalado no sistema:
   ```bash
   doxygen -v
   ```
   Se não estiver instalado, use:
   - Ubuntu/Debian: `sudo apt install doxygen`
   - Windows: Baixe em [doxygen.nl](https://www.doxygen.nl/download.html)

2. No diretório raiz do projeto, execute:
   ```bash
   doxygen Doxyfile
   ```

3. A documentação será gerada na pasta `doc/`.

4. Abra o arquivo `./doc/html/index.html` para visualizar a documentação no navegador.

---

## Obrigado por explorar nosso projeto!
