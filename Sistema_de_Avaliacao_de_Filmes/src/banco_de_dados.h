#ifndef BANCO_DE_DADOS_H
#define BANCO_DE_DADOS_H

#include <string>
#include <map>
#include <set>
#include <vector>
#include "filme.h"
#include "usuario.h"

/*
    Classe BancoDeDados
    -------------------
    Esta classe centraliza todas as operações relacionadas à persistência e ao gerenciamento
    dos dados do sistema de avaliação de filmes. É responsável por armazenar e gerenciar 
    usuários, filmes e interações entre eles, como avaliações e autenticação.

    É como o "cérebro" do sistema: concentra o cadastro de usuários, a autenticação,
    o registro de filmes, a recomendação de novos títulos com base no histórico do usuário,
    e ainda mantém controle sobre quais filmes já foram avaliados por cada pessoa.

    Funcionalidades principais:
    - Criar contas de usuários e autenticar logins.
    - Adicionar e buscar filmes pelo título.
    - Listar filmes por gênero (categoria).
    - Salvar e carregar os dados do sistema (para persistência).
    - Gerar recomendações de filmes para usuários cadastrados.
    - Registrar e verificar avaliações feitas por usuários.

    Estrutura interna:
    - Um mapa de usuários, usando o nome público como chave.
    - Um mapa de filmes, usando o título normalizado como chave.
    - Um controle de quais filmes cada usuário já avaliou, evitando avaliações duplicadas.

    Essa classe conecta os dados e garante que o sistema funcione de maneira coesa.
*/

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
