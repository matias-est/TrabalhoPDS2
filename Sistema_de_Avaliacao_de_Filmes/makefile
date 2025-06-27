CXX = g++

CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -Isrc

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
	rm -f $(OBJS) $(TARGET)
