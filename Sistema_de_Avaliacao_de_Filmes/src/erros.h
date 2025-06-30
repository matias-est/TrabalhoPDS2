#ifndef ERROS_H
#define ERROS_H

#include <stdexcept>  // Inclui a biblioteca padrão de exceções
#include <string>     // Necessária para usar std::string

/*
    Classe ErroSistema
    ------------------
    Esta classe define um tipo de exceção personalizada para o sistema de avaliação de filmes.
    Ao herdar de `std::runtime_error`, ela permite lançar e capturar erros com mensagens
    mais específicas e descritivas, facilitando o tratamento de falhas durante a execução.

    A ideia aqui é centralizar os erros em uma hierarquia própria, tornando o sistema mais organizado
    e preparado para lidar com situações inesperadas (como falhas ao carregar dados,
    autenticações inválidas, ou ações não permitidas).

    Como usar:
    - Basta lançar um `throw ErroSistema("mensagem de erro")` quando ocorrer algum problema.
    - Pode ser capturado em um bloco `try-catch` para tratar o erro de forma apropriada.

    Essa abordagem ajuda a tornar o sistema mais robusto e facilita o diagnóstico de problemas.
*/

class ErroSistema : public std::runtime_error {
public:
    // Construtor que recebe uma mensagem de erro e passa para o construtor da classe base
    explicit ErroSistema(const std::string &mensagem)
        : std::runtime_error(mensagem) {}
};

#endif
