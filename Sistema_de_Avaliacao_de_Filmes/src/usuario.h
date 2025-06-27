#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
public:
    // Construtor que recebe dados reais do usuário
    Usuario(const std::string& nomeCompleto, const std::string& dataNascimento, const std::string& senha);

    // Retorna o nome público (com anonimato parcial)
    std::string getNomePublico() const;

    // Verifica se a senha está correta
    bool autenticar(const std::string& senhaTentativa) const;

    std::string getNomeCompleto() const;
    std::string getDataNascimento() const;

private:
    std::string nomeCompleto;
    std::string dataNascimento;
    std::string senha;
    std::string nomePublico; // Nome anônimo

    // Função auxiliar que gera o nome público (anônimo) com base no sobrenome
    std::string gerarNomePublico(const std::string& sobrenome) const; 

    // Pega apenas o último sobrenome do nome completo
    std::string obterSobrenome() const;
};

#endif
