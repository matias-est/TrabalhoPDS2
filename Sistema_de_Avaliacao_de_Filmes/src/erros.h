#ifndef ERROS_H
#define ERROS_H

#include <stdexcept>
#include <string>

class ErroSistema : public std::runtime_error {
public:
    explicit ErroSistema(const std::string &mensagem)
        : std::runtime_error(mensagem) {}
};

#endif
