#ifndef FILME_H
#define FILME_H

#include <string>
#include <vector>
#include "avaliacao.h"

// Contém título, gênero, avaliações e comentários.
class Filme {
public:
    Filme(const std::string &titulo, const std::string &genero, const std::string &dataLancamento);

    void adicionarAvaliacao(const std::string &usuario, int nota);
    void adicionarComentario(const std::string &comentario);
    double calcularMedia() const;
    void exibirInformacoes() const;

    std::string getTitulo() const;
    std::string getTituloNormalizado() const;
    std::string getGenero() const;
    std::string getDataLancamento() const;

    // Retorna todas as avaliações
    std::vector<Avaliacao> getAvaliacoes() const;

    // Retorna todos os comentários
    std::vector<std::string> getComentarios() const;

    static bool compararTitulosSimilaridade(const std::string &titulo1, const std::string &titulo2);

private:
    std::string titulo;
    std::string genero;
    std::string dataLancamento;
    std::vector<Avaliacao> avaliacoes;
    std::vector<std::string> comentarios;
};

#endif
