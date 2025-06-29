#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <map>

class Usuario {
public:
    Usuario(const std::string& nomeCompleto, const std::string& dataNascimento, const std::string& senha);

    std::string getNomePublico() const;
    bool autenticar(const std::string& senhaTentativa) const;
    std::string getNomeCompleto() const;
    std::string getDataNascimento() const;

    // NOVO: método para obter a senha (para salvar no arquivo)
    std::string getSenha() const;

    // Outros métodos existentes
    void registrarAvaliacao(const std::string& tituloFilme, int nota);
    const std::map<std::string, int>& getAvaliacoes() const;
    bool jaAvaliou(const std::string& tituloFilme) const;

private:
    std::string nomeCompleto;
    std::string dataNascimento;
    std::string senha;
    std::string nomePublico;

    std::string gerarNomePublico(const std::string& sobrenome) const;
    std::string obterSobrenome() const;

    std::map<std::string, int> avaliacoes; // mapa de título → nota
};

#endif
