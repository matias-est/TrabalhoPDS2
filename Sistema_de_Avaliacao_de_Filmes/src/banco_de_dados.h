#ifndef BANCO_DE_DADOS_H
#define BANCO_DE_DADOS_H

#include <map>
#include <string> 
#include "usuario.h"
#include "filme.h"

class BancoDeDados {
public: 
bool    criarConta(const  std::string&
nomeCompleto, const       std::string&
dataNascimento, const     std::string&
senha, std::string& nomePublico); 
bool autenticar(const  std::string& nomePublico, const std::string& senha); 

void adicionarFilme(const Filme& filme); 
Filme* buscarFilme(const std::string& titulo); 
void listarFilmesPorCategoria(const std::string& genero) const; 

private: 
std::map<std::string, Usuario>usuarios; 
std::map<std::string, Filme>filmes; 
};
#endif
