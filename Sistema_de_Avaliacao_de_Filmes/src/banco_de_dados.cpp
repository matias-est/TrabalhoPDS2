#include "banco_de_dados.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

BancoDeDados::BancoDeDados() {}

BancoDeDados::~BancoDeDados() {
    for (auto const& [key, val] : usuarios)
        delete val;
    for (auto const& [key, val] : filmes)
        delete val;
}

bool BancoDeDados::criarConta(const std::string &nomeCompleto, const std::string &dataNascimento, const std::string &senha, std::string &nomePublico) {
    Usuario *novoUsuario = new Usuario(nomeCompleto, dataNascimento, senha);
    nomePublico = novoUsuario->getNomePublico();

    if (usuarios.find(nomePublico) == usuarios.end()) {
        usuarios[nomePublico] = novoUsuario;
        return true;
    } else {
        delete novoUsuario;
        return false;
    }
}

bool BancoDeDados::autenticar(const std::string &nomePublico, const std::string &senha) {
    auto it = usuarios.find(nomePublico);
    return it != usuarios.end() && it->second->autenticar(senha);
}

void BancoDeDados::adicionarFilme(Filme *filme) {
    std::string tituloNormalizado = filme->getTituloNormalizado();
    if (filmes.find(tituloNormalizado) == filmes.end()) {
        filmes[tituloNormalizado] = filme;
        std::cout << "Filme '" << filme->getTitulo() << "' adicionado com sucesso.\n";
    } else {
        std::cout << "Filme com título similar '" << filme->getTitulo() << "' já existe. Não adicionado.\n";
        delete filme;
    }
}

Filme* BancoDeDados::buscarFilme(const std::string &titulo) {
    std::string chaveBusca = titulo;
    std::transform(chaveBusca.begin(), chaveBusca.end(), chaveBusca.begin(), ::tolower);
    chaveBusca.erase(remove_if(chaveBusca.begin(), chaveBusca.end(), ::isspace), chaveBusca.end());

    auto it = filmes.find(chaveBusca);
    return (it != filmes.end()) ? it->second : nullptr;
}

void BancoDeDados::listarFilmesPorCategoria(const std::string &genero) const {
    bool encontrou = false;
    std::string generoBuscaLower = genero;
    std::transform(generoBuscaLower.begin(), generoBuscaLower.end(), generoBuscaLower.begin(), ::tolower);

    std::cout << "\n🎬 Filmes na categoria \"" << genero << "\":\n";
    for (const auto &pair : filmes) {
        std::string filmeGeneroLower = pair.second->getGenero();
        std::transform(filmeGeneroLower.begin(), filmeGeneroLower.end(), filmeGeneroLower.begin(), ::tolower);

        if (filmeGeneroLower.find(generoBuscaLower) != std::string::npos) {
            std::cout << "- Título: " << pair.second->getTitulo()
                      << " | Gênero: " << pair.second->getGenero()
                      << " | Média: " << pair.second->calcularMedia() << "\n";
            encontrou = true;
        }
    }
    if (!encontrou) {
        std::cout << "Nenhum filme encontrado nesta categoria.\n";
    }
}

bool BancoDeDados::salvarDados() const {
    // Salvar filmes
    std::ofstream arquivoFilmes("filmes.txt");
    if (!arquivoFilmes.is_open()) return false;

    for (const auto &[key, filme] : filmes) {
        arquivoFilmes << filme->getTitulo() << "|" << filme->getGenero() << "|" << filme->getDataLancamento() << "\n";
    }
    arquivoFilmes.close();

    // Salvar usuários
    std::ofstream arquivoUsuarios("usuarios.txt");
    if (!arquivoUsuarios.is_open()) return false;

    for (const auto& [nomePublico, usuario] : usuarios) {
    arquivoUsuarios << nomePublico << "|" 
                    << usuario->getNomeCompleto() << "|" 
                    << usuario->getDataNascimento() << "|" 
                    << usuario->getSenha() << "\n";
}

    arquivoUsuarios.close();

    // Salvar avaliações de usuários
    std::ofstream arquivoAvaliacoes("avaliacoes_usuario.txt");
    if (!arquivoAvaliacoes.is_open()) return false;

    for (const auto& [nomePublico, usuario] : usuarios) {
        for (const auto& [tituloFilme, nota] : usuario->getAvaliacoes()) {
            arquivoAvaliacoes << nomePublico << "|" << tituloFilme << "|" << nota << "\n";
        }
    }
    arquivoAvaliacoes.close();

    return true;
}

bool BancoDeDados::carregarDados() {
    // Limpar dados atuais para evitar duplicação
    for (auto const& [key, val] : usuarios)
        delete val;
    usuarios.clear();
    for (auto const& [key, val] : filmes)
        delete val;
    filmes.clear();
    avaliacoesUsuario.clear();

    // Carregar filmes
    std::ifstream arquivoFilmes("filmes.txt");
    if (!arquivoFilmes.is_open()) return false;

    std::string linha;
    while (getline(arquivoFilmes, linha)) {
        std::stringstream ss(linha);
        std::string titulo, genero, data;
        if (getline(ss, titulo, '|') && getline(ss, genero, '|') && getline(ss, data)) {
            adicionarFilme(new Filme(titulo, genero, data));
        }
    }
    arquivoFilmes.close();

    // Carregar usuários
    std::ifstream arquivoUsuarios("usuarios.txt");
    if (!arquivoUsuarios.is_open()) return false;

    while (getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::string nomePublico, nomeCompleto, dataNascimento, senha;
        if (getline(ss, nomePublico, '|') && getline(ss, nomeCompleto, '|') && getline(ss, dataNascimento, '|') && getline(ss, senha)) {
            Usuario* usuario = new Usuario(nomeCompleto, dataNascimento, senha);
            // Como nomePublico é gerado, substituir pelo salvo
            usuarios[nomePublico] = usuario;
        }
    }
    arquivoUsuarios.close();

    // Carregar avaliações de usuários
    std::ifstream arquivoAvaliacoes("avaliacoes_usuario.txt");
    if (!arquivoAvaliacoes.is_open()) return false;

    while (getline(arquivoAvaliacoes, linha)) {
        std::stringstream ss(linha);
        std::string nomePublico, tituloFilme, notaStr;
        if (getline(ss, nomePublico, '|') && getline(ss, tituloFilme, '|') && getline(ss, notaStr)) {
            int nota = std::stoi(notaStr);
            // Atualizar mapa de avaliaçõesUsuario
            std::string normalizado = tituloFilme;
std::transform(normalizado.begin(), normalizado.end(), normalizado.begin(), ::tolower);
normalizado.erase(remove_if(normalizado.begin(), normalizado.end(), ::isspace), normalizado.end());

avaliacoesUsuario[nomePublico].insert(normalizado);

            // Atualizar avaliações no objeto Usuario
            auto it = usuarios.find(nomePublico);
            if (it != usuarios.end()) {
                it->second->registrarAvaliacao(tituloFilme, nota);
            }
            // Atualizar avaliações no objeto Filme
            Filme* filme = buscarFilme(tituloFilme);
            if (filme) {
                filme->adicionarAvaliacao(nomePublico, nota);
            }
        }
    }
    arquivoAvaliacoes.close();

    return true;
}


bool BancoDeDados::usuarioJaAvaliou(const std::string &nomePublico, const std::string &tituloNormalizado) const {
    auto it = avaliacoesUsuario.find(nomePublico);
    if (it == avaliacoesUsuario.end())
        return false;
    return it->second.find(tituloNormalizado) != it->second.end();
}

void BancoDeDados::registrarAvaliacaoUsuario(const std::string &nomePublico, const std::string &tituloOriginal, int nota) {
    // Normaliza título como as chaves do map de filmes
    std::string tituloNormalizado = tituloOriginal;
    std::transform(tituloNormalizado.begin(), tituloNormalizado.end(), tituloNormalizado.begin(), ::tolower);
    tituloNormalizado.erase(remove_if(tituloNormalizado.begin(), tituloNormalizado.end(), ::isspace), tituloNormalizado.end());

    // Marca que o usuário avaliou
    avaliacoesUsuario[nomePublico].insert(tituloNormalizado);

    // Salva avaliação no filme correspondente
    auto it = filmes.find(tituloNormalizado);
    if (it != filmes.end()) {
        it->second->adicionarAvaliacao(nomePublico, nota);
    }

    // Atualiza avaliação do usuário
    auto usuarioIt = usuarios.find(nomePublico);
    if (usuarioIt != usuarios.end()) {
        usuarioIt->second->registrarAvaliacao(tituloOriginal, nota);  // Use tituloOriginal para manter padrão
    }
}




std::vector<Filme*> BancoDeDados::recomendarFilmes(const std::string &nomePublico, int maxRecomendacoes) {
    std::vector<Filme*> recomendados;
    std::multimap<double, Filme*, std::greater<>> ordenado;

    for (const auto &[titulo, filme] : filmes) {
        if (!usuarioJaAvaliou(nomePublico, titulo)) {
            double media = filme->calcularMedia();
            ordenado.insert({media, filme});
        }
    }

    for (const auto &[media, filme] : ordenado) {
        if ((int)recomendados.size() >= maxRecomendacoes) break;
        recomendados.push_back(filme);
    }

    return recomendados;
}
