#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <string>

/*
    Classe Avaliacao
    ----------------
    Essa classe representa uma avaliação feita por um usuário para um determinado filme.
    Cada avaliação contém duas informações principais: o nome do usuário que avaliou
    e a nota que ele atribuiu.

    É uma classe simples e direta, pensada para ser utilizada como parte de um sistema
    de avaliação de filmes, onde várias avaliações podem ser agregadas a um filme
    (como feito na classe Filme).

    Funcionalidades principais:
    - Criar uma nova avaliação com usuário e nota.
    - Recuperar a nota atribuída.
    - Recuperar o nome do usuário que fez a avaliação.
*/

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
