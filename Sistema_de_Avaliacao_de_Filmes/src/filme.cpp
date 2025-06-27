#include "filme.h"
#include <iostream>
#include <algorithm> 
#include <cctype>    

Filme::Filme(const std::string &titulo, const std::string &genero, const std::string &dataLancamento)
    : titulo(titulo), genero(genero), dataLancamento(dataLancamento) {}

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
    std::cout << "\nFilme: " << titulo
              << "\nGênero: " << genero
              << "\nData de Lançamento: " << dataLancamento 
              << "\nMédia das avaliações: " << calcularMedia() << "\n";
    std::cout << "Avaliações:\n";
    if (avaliacoes.empty())
    {
        std::cout << "  Nenhuma avaliação ainda.\n";
    }
    else
    {
        for (const auto &a : avaliacoes)
        {
            std::cout << "- " << a.getUsuario() << ": Nota " << a.getNota() << "\n";
        }
    }
    std::cout << "Comentários:\n";
    if (comentarios.empty())
    {
        std::cout << "  Nenhum comentário ainda.\n";
    }
    else
    {
        for (const auto &c : comentarios)
        {
            std::cout << "- " << c << "\n";
        }
    }
}
std::string Filme::getTitulo() const{
    return titulo;
}

std::string Filme::getTituloNormalizado() const{
    std::string resultado = titulo;
    std::transform(resultado.begin(), resultado.end(), resultado.begin(), ::tolower);
    resultado.erase(remove_if(resultado.begin(), resultado.end(), ::isspace), resultado.end());
    std::vector<std::string> artigos = {"o", "a", "os", "as", "the", "um", "uma", "uns", "umas"};
    for (const auto &artigo : artigos){
        size_t pos;
        while ((pos = resultado.find(artigo)) != std::string::npos){
            
            if ((pos == 0 || !isalpha(resultado[pos - 1])) && (pos + artigo.length() == resultado.length() || !isalpha(resultado[pos + artigo.length()]))){
                resultado.erase(pos, artigo.length());
            }
            else{
                
                pos += artigo.length();
            }
        }
    }

    return resultado;
}

std::string Filme::getGenero() const
{
    return genero;
}

std::string Filme::getDataLancamento() const
{
    return dataLancamento;
}


bool Filme::compararTitulosSimilaridade(const std::string &titulo1, const std::string &titulo2)
{
    
    std::string t1_normalizado = titulo1;
    std::string t2_normalizado = titulo2;

    std::transform(t1_normalizado.begin(), t1_normalizado.end(), t1_normalizado.begin(), ::tolower);
    std::transform(t2_normalizado.begin(), t2_normalizado.end(), t2_normalizado.begin(), ::tolower);

    t1_normalizado.erase(remove_if(t1_normalizado.begin(), t1_normalizado.end(), ::isspace), t1_normalizado.end());
    t2_normalizado.erase(remove_if(t2_normalizado.begin(), t2_normalizado.end(), ::isspace), t2_normalizado.end());

   
    return t1_normalizado == t2_normalizado;
}
