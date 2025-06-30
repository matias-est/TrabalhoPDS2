#ifndef FILME_H
#define FILME_H

#include <string>
#include <vector>
#include "avaliacao.h"

/*
    Classe Filme
    ------------
    Esta classe representa um filme e reúne informações básicas como título, gênero e data de lançamento.
    Além disso, permite armazenar avaliações feitas por usuários (com notas) e comentários livres.

    A ideia é facilitar o gerenciamento de dados de um filme em um sistema que lide com avaliações,
    como um catálogo ou plataforma de recomendação.

    Funcionalidades principais:
    - Adicionar uma avaliação (nota) de um usuário.
    - Adicionar comentários sobre o filme.
    - Calcular a média das notas recebidas.
    - Exibir todas as informações do filme de forma organizada.
    - Acessar diretamente a lista de avaliações e comentários.
    - Comparar títulos de filmes para verificar similaridade (útil para buscas).

    Observação: esta classe depende da definição da classe Avaliacao (avaliacao.h).
*/

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
