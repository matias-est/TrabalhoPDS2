
#include "usuario.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

Usuario::Usuario(const std::string& nomeCompleto, const std::string& dataNascimento, const std::string& senha)
    : nomeCompleto(nomeCompleto), dataNascimento(dataNascimento), senha(senha) {
    nomePublico = gerarNomePublico(obterSobrenome());
}

std::string Usuario::getNomePublico() const {
    return nomePublico;
}

bool Usuario::autenticar(const std::string& senhaTentativa) const {
    return senha == senhaTentativa;
}

std::string Usuario::getNomeCompleto() const {
    return nomeCompleto;
}

std::string Usuario::getDataNascimento() const {
    return dataNascimento;
}

std::string Usuario::obterSobrenome() const {
    std::istringstream iss(nomeCompleto);
    std::string palavra, sobrenome;
    while (iss >> palavra) {
        sobrenome = palavra;
    }
    return sobrenome;
}

std::string Usuario::gerarNomePublico(const std::string& sobrenome) const {
    std::vector<std::string> personagens = {
        "Neo", "Trinity", "Yoda", "Leia", "Frodo", "Gandalf", "Vader", "Hermione", "Batman"
    };
    srand(time(0) + rand());
    std::string personagem = personagens[rand() % personagens.size()];
    return personagem + sobrenome;
}
