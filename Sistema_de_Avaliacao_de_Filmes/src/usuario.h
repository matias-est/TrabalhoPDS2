#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
public:
    Usuario(const std::string& nomeCompleto, const std::string& dataNascimento, const std::string& senha);

    std::string getNomePublico() const;
    bool autenticar(const std::string& senhaTentativa) const;

    std::string getNomeCompleto() const;
    std::string getDataNascimento() const;

private:
    std::string nomeCompleto;
    std::string dataNascimento;
    std::string senha;
    std::string nomePublico;

    std::string gerarNomePublico(const std::string& sobrenome) const;
    std::string obterSobrenome() const;
};

#endif
