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
    Filme(const std::string &titulo, const std::string &genero, const std::string &dataLancamento);

    // Adiciona uma avaliação de um usuário
    void adicionarAvaliacao(const std::string &usuario, int nota);
    // Adiciona um comentário sobre o filme
    void adicionarComentario(const std::string &comentario);
    // Calcula a média das avaliações feitas no filme
    double calcularMedia() const;
    // Mostra todas as informações sobre o filme
    void exibirInformacoes() const; 
    // Retorna o título original do filme
    std::string getTitulo() const;
    // Retorna o título do filme (evitando duplicadas)
    std::string getTituloNormalizado() const;
    // Retorna a categoria do filme
    std::string getGenero() const;
    // Retorna a data de lançamento do filme
    std::string getDataLancamento() const;
    // Verifica a similaridade entre dois títulos de filme
    static bool compararTitulosSimilaridade(const std::string &titulo1, const std::string &titulo2);

private:
    std::string titulo;
    std::string genero;
    std::string dataLancamento;
    std::vector<Avaliacao> avaliacoes;
    std::vector<std::string> comentarios;

};

#endif
