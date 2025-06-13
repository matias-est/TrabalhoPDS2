#ifndef FILME_H
#define FILME_H

#include <string>
#include <vector>
#include "avaliacao.h"


class Filme
{
public:
    Filme(const std::string &titulo, const std::string &genero);

    void adicionarAvaliacao(const std::string &usuario, int nota);
    void adicionarComentario(const std::string &comentario);
    double calcularMedia() const;
    void exibirInformacoes() const;

    std::string getTituloNormalizado() const;
    std::string getGenero() const;


private:
    std::string titulo;
    std::string genero;
    std::vector<Avaliacao> avaliacoes;
    std::vector<std::string> comentarios;
};

#endif
