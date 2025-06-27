#ifndef BANCO_DE_DADOS_H
#define BANCO_DE_DADOS_H

#include <map>
#include <string> 
#include "usuario.h"
#include "filme.h"

// Banco de dados que guarda todos os usuários e filmes da plataforma.
class BancoDeDados {
public: 

// Cria uma nova conta de usuário. Recebe dados pessoais e senha.
// Também gera um nome público (com semi-anonimato).
// Retorna true se o cadastro foi bem-sucedido, false se o nome já existir.
bool    criarConta(const  std::string&
nomeCompleto, const       std::string&
dataNascimento, const     std::string&
senha, std::string& nomePublico); 

// Autentica um usuário a partir do nome público e da senha fornecida.
bool autenticar(const  std::string& nomePublico, const std::string& senha); 

// Adiciona um novo filme ao mapa de filmes (evitando duplicadas).
void adicionarFilme(const Filme& filme); 

// Busca um filme pelo título normalizado.
// Retorna um ponteiro para o filme (ou nullptr se não existir).
Filme* buscarFilme(const std::string& titulo); 

// Lista todos os filmes que pertencem a uma determinada categoria (gênero).
void listarFilmesPorCategoria(const std::string& genero) const; 

private: 
std::map<std::string, Usuario>usuarios; 
std::map<std::string, Filme>filmes; 
};
#endif
