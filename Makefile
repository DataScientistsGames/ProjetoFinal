CC = g++
CFLAGS = -std=c++11 -Wall
DEBUG_FLAGS = -g

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = obj
BIN_DIR = bin

all: sistema

debug: CFLAGS += $(DEBUG_FLAGS)
debug: sistema

$(BUILD_DIR)/Controlador.o: $(INCLUDE_DIR)/Controlador.hpp $(INCLUDE_DIR)/Comandos.hpp $(INCLUDE_DIR)/Cadastrador.hpp  $(INCLUDE_DIR)/helpers/CSV.hpp $(SRC_DIR)/Controlador.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/helpers -c $(SRC_DIR)/Controlador.cpp -o $(BUILD_DIR)/Controlador.o

$(BUILD_DIR)/main.o: $(INCLUDE_DIR)/Controlador.hpp $(INCLUDE_DIR)/Comandos.hpp  $(SRC_DIR)/main.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/CSV.o: $(INCLUDE_DIR)/helpers/CSV.hpp  $(SRC_DIR)/helpers/CSV.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/helpers -c $(SRC_DIR)/helpers/CSV.cpp -o $(BUILD_DIR)/CSV.o

$(BUILD_DIR)/Cadastrador.o: $(INCLUDE_DIR)/Cadastrador.hpp  $(SRC_DIR)/Cadastrador.cpp $(INCLUDE_DIR)/helpers/CSV.hpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/helpers -c $(SRC_DIR)/Cadastrador.cpp -o $(BUILD_DIR)/Cadastrador.o

sistema: $(BUILD_DIR)/main.o $(BUILD_DIR)/Controlador.o $(BUILD_DIR)/CSV.o $(BUILD_DIR)/Cadastrador.o 
	$(CC) $(CFLAGS) $(BUILD_DIR)/main.o $(BUILD_DIR)/Controlador.o $(BUILD_DIR)/CSV.o $(BUILD_DIR)/Cadastrador.o -o $(BIN_DIR)/sistema

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)/*.o $(BIN_DIR)/sistema
