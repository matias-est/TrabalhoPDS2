
#include "banco_de_dados.h"
#include <algorithm>
#include <iostream>

bool BancoDeDados::criarConta(const std::string & nomeCompleto, const std::string &dataNascimento, const std::string &senha, std::string &nomePublico){
    Usuario usuario(nomeCompleto, dataNascimento, senha);
    nomePublico = usuario.getNomePublico(); 
    if (usuarios.find(nomePublico) == usuarios.end()) {
        usuarios[nomePublico] = usuario;
        return true;
    }
    return false; 
}

bool BancoDeDados::autenticar(const std::string &nomePublico, const std::string &senha){
    auto it = usuarios.find(nomePublico);
    return it != usuarios.end() && it->second.autenticar(senha);
}

void BancoDeDados::adicionarFilme(const Filme &filme) {
    if (buscarFilme(filme.getTitulo()) == nullptr){ 
        filmes[filme.getTituloNormalizado()] = filme;
        std::cout << "Filme '" << filme.getTitulo() << "' adicionado com sucesso.\n";
    }
    else{
        std::cout << "Filme com título similar '" << filme.getTitulo() << "' já existe, filme não foi adicionado.\n";
    }
}

Filme* BancoDeDados::buscarFilme(const std::string &titulo){
    std::string chaveBusca = titulo;
    std::transform(chaveBusca.begin(), chaveBusca.end(), chaveBusca.begin(), ::tolower);
    chaveBusca.erase(remove_if(chaveBusca.begin(), chaveBusca.end(), ::isspace), chaveBusca.end());

    auto it = filmes.find(chaveBusca); 
    return (it != filmes.end()) ? &(it->second) : nullptr;
}

void BancoDeDados::listarFilmesPorCategoria(const std::string& genero) const{
    bool encontrou = false;
    std::string generoBuscaLower = genero;
    std::transform(generoBuscaLower.begin(), generoBuscaLower.end(), generoBuscaLower.begin(), ::tolower);

    std::cout << "\n🎬 Filmes na categoria \"" << genero << "\":\n";
    for (const auto& pair : filmes){
        
        std::string filmeGeneroLower = pair.second.getGenero();
        std::transform(filmeGeneroLower.begin(), filmeGeneroLower.end(), filmeGeneroLower.begin(), ::tolower);

        if (filmeGeneroLower.find(generoBuscaLower) != std::string::npos){ 
            std::cout << "- Título: " << pair.second.getTitulo()
                      << " | Gênero: " << pair.second.getGenero()
                      << " | Média: " << pair.second.calcularMedia() << "\n";
            encontrou = true;
        }
    }
    if (!encontrou) {
        std::cout << "Nenhum filme encontrado nesta categoria.\n";
    }
}
