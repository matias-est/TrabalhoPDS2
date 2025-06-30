#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <map>

/*
    Classe Usuario
    --------------
    Representa um usuário do sistema de avaliação de filmes.

    Esta classe armazena dados pessoais do usuário, como nome completo,
    data de nascimento e senha, além de gerenciar o nome público (um identificador único
    usado para interações no sistema). Também é responsável por registrar e consultar
    avaliações feitas pelo usuário em filmes.

    Funcionalidades principais:
    - Autenticar o usuário com base na senha.
    - Gerar e fornecer o nome público automaticamente (usado como identificador no sistema).
    - Registrar avaliações feitas em filmes.
    - Verificar se um usuário já avaliou um determinado filme.
    - Acessar todas as avaliações feitas (título do filme → nota).
    - Permitir acesso à senha (exclusivamente para fins de salvamento em arquivo).

    Observações:
    - O nome público é gerado automaticamente com base no sobrenome do usuário, 
      garantindo um identificador mais informal e prático.
    - A senha é armazenada como texto (em um sistema real, seria ideal aplicar criptografia).

    Essa classe é essencial para lidar com a identidade e o histórico de avaliações de cada usuário.
*/

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
