#include "usuario.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <algorithm>

Usuario::Usuario(const std::string &nomeCompleto, const std::string &dataNascimento, const std::string &senha)
    : nomeCompleto(nomeCompleto), dataNascimento(dataNascimento), senha(senha) {
    nomePublico = gerarNomePublico(obterSobrenome());
}

std::string Usuario::getNomePublico() const {
    return nomePublico;
}

bool Usuario::autenticar(const std::string &senhaTentativa) const {
    return senha == senhaTentativa;
}

std::string Usuario::getNomeCompleto() const {
    return nomeCompleto;
}

std::string Usuario::getDataNascimento() const {
    return dataNascimento;
}

// NOVO: método para retornar a senha do usuário (para salvar em arquivo)
std::string Usuario::getSenha() const {
    return senha;
}

std::string Usuario::obterSobrenome() const {
    std::istringstream iss(nomeCompleto);
    std::string palavra, sobrenome;
    while (iss >> palavra) {
        sobrenome = palavra;
    }
    return sobrenome;
}

std::string Usuario::gerarNomePublico(const std::string &sobrenome) const {
    std::vector<std::string> personagens = {
        "Neo", "Trinity", "Yoda", "Leia", "Frodo", "Gandalf", "Vader", "Hermione", "Batman",
        "IronMan", "Thor", "Loki", "BlackPanther", "Joker", "Katniss", "Buzz", "Woody",
        "Elsa", "Moana", "Shrek", "Donkey", "Simba", "Dory", "Wolverine", "Deadpool"};

    std::string personagem = personagens[rand() % personagens.size()];
    return personagem + " " + sobrenome;
}

void Usuario::registrarAvaliacao(const std::string& tituloFilme, int nota) {
    avaliacoes[tituloFilme] = nota;
}

const std::map<std::string, int>& Usuario::getAvaliacoes() const {
    return avaliacoes;
}

bool Usuario::jaAvaliou(const std::string& tituloFilme) const {
    return avaliacoes.find(tituloFilme) != avaliacoes.end();
}
