#ifndef  ERROS_H
#define  ERROS_H

#include <stdexcept>  // Inclui a biblioteca padrão de exceções
#include <string>     // Necessária para usar std::string

// Classe base de exceções personalizadas do sistema
// Herda de std::runtime_error, permitindo lançar e capturar erros com mensagens
class ErroSistema : public std::runtime_error {
public:
    // Construtor que recebe uma mensagem de erro e passa para o construtor da classe base
    explicit ErroSistema(const std::string &mensagem)
        : std::runtime_error(mensagem) {}
};

#endif
