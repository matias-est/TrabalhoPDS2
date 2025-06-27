
#include "banco_de_dados.h"
#include <algorithm>
#include <iostream>

bool BancoDeDados::criarConta(const std::string& nomeCompleto, const std::string& dataNascimento, const std::string& senha, std::string& nomePublico) {
    Usuario usuario(nomeCompleto, dataNascimento, senha);
    nomePublico = usuario.getNomePublico();
    if (usuarios.find(nomePublico) == usuarios.end()) {
        usuarios[nomePublico] = usuario;
        return true;
    }
    return false;
}

bool BancoDeDados::autenticar(const std::string& nomePublico, const std::string& senha) {
    auto it = usuarios.find(nomePublico);
    return it != usuarios.end() && it->second.autenticar(senha);
}

void BancoDeDados::adicionarFilme(const Filme& filme) {
    filmes[filme.getTituloNormalizado()] = filme;
}

Filme* BancoDeDados::buscarFilme(const std::string& titulo) {
    std::string chave = titulo;
    std::transform(chave.begin(), chave.end(), chave.begin(), ::tolower);
    chave.erase(remove_if(chave.begin(), chave.end(), ::isspace), chave.end());
    auto it = filmes.find(chave);
    return (it != filmes.end()) ? &(it->second) : nullptr;
}

void BancoDeDados::listarFilmesPorCategoria(const std::string& genero) const {
    bool encontrou = false;
    std::cout << "\n🎬 Filmes na categoria \"" << genero << "\":\n";
    for (const auto& [chave, filme] : filmes) {
        if (filme.getGenero() == genero) {
            std::cout << "- " << filme.getDataLancamento() << " | " << filme.getGenero() << "\n";
            encontrou = true;
        }
    }
    if (!encontrou) {
        std::cout << "Nenhum filme encontrado nesta categoria.\n";
    }
}
