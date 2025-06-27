# Flags de compilação
CXXFLAGS = -std=c++11 -Wall -Wextra

# Arquivos fonte
SRC = src/main.cpp src/usuario.cpp src/filme.cpp src/avaliacao.cpp src/banco_de_dados.cpp

# Arquivo de saída
TARGET = avaliador

# Regra principal
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Executar o programa
run: $(TARGET)
	./$(TARGET)

# Limpar arquivos compilados
clean:
	rm -f $(TARGET)

# Limpar tudo
purge: clean
	rm -rf *.o
