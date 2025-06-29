#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <string>

class Avaliacao
{
public:
// Construtor que define quem avaliou e qual foi a nota.
    Avaliacao(const std::string &usuario, int nota);

// Retorna a nota dada pelo usuário
    int getNota() const;
// Retorna o nome do usuário que fez a avaliação
    std::string getUsuario() const;

private:
    std::string usuario;
    int nota;
};

#endif

// Fim do arquivo: Sistema_de_Avaliacao_de_Filmes/src/avaliacao.h
