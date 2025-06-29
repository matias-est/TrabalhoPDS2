#ifndef BANCO_DE_DADOS_H
#define BANCO_DE_DADOS_H

#include <string>
#include <map>
#include <set>
#include <vector>
#include "filme.h"
#include "usuario.h"

class BancoDeDados {
public:
    BancoDeDados();
    ~BancoDeDados();

    bool criarConta(const std::string &nomeCompleto, const std::string &dataNascimento, const std::string &senha, std::string &nomePublico);
    bool autenticar(const std::string &nomePublico, const std::string &senha);

    void adicionarFilme(Filme *filme);
    Filme* buscarFilme(const std::string &titulo);
    void listarFilmesPorCategoria(const std::string &genero) const;

    bool salvarDados() const;
    bool carregarDados();

    std::vector<Filme*> recomendarFilmes(const std::string &nomePublico, int maxRecomendacoes = 5);

    // Novos métodos para controlar avaliações por usuário
    bool usuarioJaAvaliou(const std::string &nomePublico, const std::string &tituloNormalizado) const;
    void registrarAvaliacaoUsuario(const std::string &nomePublico, const std::string &tituloNormalizado, int nota);

private:
    std::map<std::string, Usuario*> usuarios; // chave: nomePublico
    std::map<std::string, Filme*> filmes;     // chave: título normalizado

    // Controle de quais filmes cada usuário já avaliou
    std::map<std::string, std::set<std::string>> avaliacoesUsuario;
};

#endif
