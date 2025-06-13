#include "filme.h"
#include <iostream>
#include <algorithm>

Filme::Filme(const std::string &titulo, const std::string &genero)
    : titulo(titulo), genero(genero) {}

void Filme::adicionarAvaliacao(const std::string &usuario, int nota)
{
    if (nota >= 1 && nota <= 5)
    {
        avaliacoes.emplace_back(usuario, nota);
    }
    else
    {
        std::cout << "Nota inválida. Deve estar entre 1 e 5.\n";
    }
}

void Filme::adicionarComentario(const std::string &comentario)
{
    comentarios.push_back(comentario);
}

double Filme::calcularMedia() const
{
    if (avaliacoes.empty())
        return 0.0;
    int soma = 0;
    for (const auto &a : avaliacoes)
        soma += a.getNota();
    return static_cast<double>(soma) / avaliacoes.size();
}

void Filme::exibirInformacoes() const
{
    std::cout << "\nFilme: " << titulo << "\nGênero: " << genero
              << "\nMédia das avaliações: " << calcularMedia() << "\n";
    std::cout << "Avaliações:\n";
    for (const auto &a : avaliacoes)
    {
        std::cout << "- " << a.getUsuario() << ": Nota " << a.getNota() << "\n";
    }
    std::cout << "Comentários:\n";
    for (const auto &c : comentarios)
    {
        std::cout << "- " << c << "\n";
    }
}

std::string Filme::getTituloNormalizado() const
{
    std::string resultado = titulo;
    std::transform(resultado.begin(), resultado.end(), resultado.begin(), ::tolower);

    
    resultado.erase(remove_if(resultado.begin(), resultado.end(), ::isspace), resultado.end());

    std::vector<std::string> artigos = {"o", "a", "os", "as", "the", "um", "uma", "uns", "umas"};

    for (const auto &artigo : artigos)
    {
        size_t pos;
        while ((pos = resultado.find(artigo)) != std::string::npos)
        {
            resultado.erase(pos, artigo.length());
        }
    }

    return resultado;
}

std::string Filme::getGenero() const
{
    return genero;
}
