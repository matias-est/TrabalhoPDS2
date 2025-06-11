#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <string>

class Avaliacao
{
public:
    Avaliacao(const std::string &usuario, int nota);

    int getNota() const;
    std::string getUsuario() const;

private:
    std::string usuario;
    int nota;
};

#endif

