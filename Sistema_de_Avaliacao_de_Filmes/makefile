CXX = g++

# Alterado para C++17 para suportar "decomposition declarations" e outras features modernas.
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Isrc

SRCDIR = src

SRCS = $(SRCDIR)/main.cpp \
       $(SRCDIR)/usuario.cpp \
       $(SRCDIR)/filme.cpp \
       $(SRCDIR)/avaliacao.cpp \
       $(SRCDIR)/banco_de_dados.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = avaliador

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	del /Q $(subst /,\,$(OBJS)) $(TARGET).exe 2>nul || exit 0
