#ifndef FILME_H
#define FILME_H

#include <string>
#include <vector>
#include "avaliacao.h"

// Contém título, gênero, avaliações e comentários.
class Filme
{
public:
    // Criação do filme com título e categoria (gênero)
    Filme(const std::string &titulo, const std::string &genero);

    // Adiciona uma avaliação de um usuário
    void adicionarAvaliacao(const std::string &usuario, int nota);
    // Adiciona um comentário sobre o filme
    void adicionarComentario(const std::string &comentario);
    // Calcula a média das avaliações feitas no filme
    double calcularMedia() const;
    // Mostra todas as informações sobre o filme
    void exibirInformacoes() const;
    // Retorna o título do filme (evitando duplicadas)
    std::string getTituloNormalizado() const;
    // Retorna a categoria do filme
    std::string getGenero() const;

private:
    std::string titulo;
    std::string genero;
    std::vector<Avaliacao> avaliacoes;
    std::vector<std::string> comentarios;
};

#endif
