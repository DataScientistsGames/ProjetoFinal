CC = g++
CFLAGS = -std=c++11 -Wall
DEBUG_FLAGS = -g

SRC_DIR = src
INCLUDE_DIR = include
HELPERS_DIR = helpers
BUILD_DIR = obj
BIN_DIR = bin

all: $(BIN_DIR)/sistema

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(BIN_DIR)/sistema

$(BUILD_DIR)/Controlador.o: $(INCLUDE_DIR)/Controlador.hpp $(INCLUDE_DIR)/$(HELPERS_DIR)/CoutComuns.hpp $(INCLUDE_DIR)/Estatistica.hpp $(INCLUDE_DIR)/Cadastrador.hpp $(INCLUDE_DIR)/Comandos.hpp $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/Tabuleiro.hpp $(INCLUDE_DIR)/Reversi.hpp $(INCLUDE_DIR)/Lig4.hpp $(INCLUDE_DIR)/Velha.hpp $(INCLUDE_DIR)/Partida.hpp $(INCLUDE_DIR)/Cores.hpp $(SRC_DIR)/Controlador.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/$(HELPERS_DIR) -c $(SRC_DIR)/Controlador.cpp -o $(BUILD_DIR)/Controlador.o

$(BUILD_DIR)/main.o: $(INCLUDE_DIR)/$(HELPERS_DIR)/CoutComuns.hpp $(INCLUDE_DIR)/Controlador.hpp $(INCLUDE_DIR)/Comandos.hpp $(SRC_DIR)/main.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/$(HELPERS_DIR) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/CSV.o: $(INCLUDE_DIR)/$(HELPERS_DIR)/CSV.hpp  $(SRC_DIR)/$(HELPERS_DIR)/CSV.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/$(HELPERS_DIR) -c $(SRC_DIR)/$(HELPERS_DIR)/CSV.cpp -o $(BUILD_DIR)/CSV.o

$(BUILD_DIR)/CoutComuns.o: $(INCLUDE_DIR)/$(HELPERS_DIR)/CoutComuns.hpp $(INCLUDE_DIR)/Cores.hpp $(SRC_DIR)/$(HELPERS_DIR)/CoutComuns.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/$(HELPERS_DIR) -c $(SRC_DIR)/$(HELPERS_DIR)/CoutComuns.cpp -o $(BUILD_DIR)/CoutComuns.o

$(BUILD_DIR)/Cadastrador.o: $(INCLUDE_DIR)/Cadastrador.hpp $(INCLUDE_DIR)/$(HELPERS_DIR)/CSV.hpp $(INCLUDE_DIR)/Cores.hpp $(SRC_DIR)/Cadastrador.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/$(HELPERS_DIR) -c $(SRC_DIR)/Cadastrador.cpp -o $(BUILD_DIR)/Cadastrador.o

$(BUILD_DIR)/Jogador.o: $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/PosicaoCartesiana.hpp $(SRC_DIR)/Jogador.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/Jogador.cpp -o $(BUILD_DIR)/Jogador.o

$(BUILD_DIR)/Tabuleiro.o: $(INCLUDE_DIR)/Tabuleiro.hpp $(INCLUDE_DIR)/Casa.hpp $(SRC_DIR)/Tabuleiro.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/Tabuleiro.cpp -o $(BUILD_DIR)/Tabuleiro.o

$(BUILD_DIR)/Reversi.o: $(INCLUDE_DIR)/Reversi.hpp $(INCLUDE_DIR)/Tabuleiro.hpp $(INCLUDE_DIR)/Casa.hpp $(SRC_DIR)/Reversi.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/Reversi.cpp -o $(BUILD_DIR)/Reversi.o

$(BUILD_DIR)/Lig4.o: $(INCLUDE_DIR)/Lig4.hpp $(INCLUDE_DIR)/Tabuleiro.hpp $(INCLUDE_DIR)/Casa.hpp $(SRC_DIR)/Lig4.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/Lig4.cpp -o $(BUILD_DIR)/Lig4.o

$(BUILD_DIR)/Velha.o: $(INCLUDE_DIR)/Velha.hpp $(INCLUDE_DIR)/Tabuleiro.hpp $(INCLUDE_DIR)/Casa.hpp $(SRC_DIR)/Velha.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/Velha.cpp -o $(BUILD_DIR)/Velha.o

$(BUILD_DIR)/Partida.o: $(INCLUDE_DIR)/Partida.hpp $(INCLUDE_DIR)/$(HELPERS_DIR)/CSV.hpp $(INCLUDE_DIR)/$(HELPERS_DIR)/CoutComuns.hpp $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/Tabuleiro.hpp $(INCLUDE_DIR)/PosicaoCartesiana.hpp $(INCLUDE_DIR)/Reversi.hpp $(INCLUDE_DIR)/Lig4.hpp $(INCLUDE_DIR)/Velha.hpp $(INCLUDE_DIR)/Cores.hpp $(SRC_DIR)/Partida.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/$(HELPERS_DIR) -c $(SRC_DIR)/Partida.cpp -o $(BUILD_DIR)/Partida.o

$(BUILD_DIR)/PosicaoCartesiana.o: $(INCLUDE_DIR)/PosicaoCartesiana.hpp $(SRC_DIR)/PosicaoCartesiana.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/PosicaoCartesiana.cpp -o $(BUILD_DIR)/PosicaoCartesiana.o

$(BUILD_DIR)/Estatistica.o: $(INCLUDE_DIR)/Estatistica.hpp $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/$(HELPERS_DIR)/CSV.hpp $(INCLUDE_DIR)/Cores.hpp $(SRC_DIR)/Estatistica.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/$(HELPERS_DIR) -c $(SRC_DIR)/Estatistica.cpp -o $(BUILD_DIR)/Estatistica.o

$(BIN_DIR)/sistema: $(BUILD_DIR)/main.o $(BUILD_DIR)/Controlador.o $(BUILD_DIR)/CSV.o $(BUILD_DIR)/CoutComuns.o $(BUILD_DIR)/Cadastrador.o $(BUILD_DIR)/Jogador.o $(BUILD_DIR)/Tabuleiro.o $(BUILD_DIR)/Reversi.o $(BUILD_DIR)/Lig4.o $(BUILD_DIR)/Velha.o $(BUILD_DIR)/Partida.o $(BUILD_DIR)/PosicaoCartesiana.o $(BUILD_DIR)/Estatistica.o
	$(CC) $(CFLAGS) $(BUILD_DIR)/main.o $(BUILD_DIR)/Controlador.o $(BUILD_DIR)/CSV.o $(BUILD_DIR)/CoutComuns.o $(BUILD_DIR)/Cadastrador.o $(BUILD_DIR)/Jogador.o $(BUILD_DIR)/Tabuleiro.o $(BUILD_DIR)/Reversi.o $(BUILD_DIR)/Lig4.o $(BUILD_DIR)/Velha.o $(BUILD_DIR)/Partida.o $(BUILD_DIR)/PosicaoCartesiana.o $(BUILD_DIR)/Estatistica.o -o $(BIN_DIR)/sistema

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)/*.o $(BIN_DIR)/sistema
