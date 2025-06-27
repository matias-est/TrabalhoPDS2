#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <string>

class Avaliacao
{
public:
// Construtor que define quem avaliou e qual foi a nota.
    Avaliacao(const std::string &usuario, int nota);

    int getNota() const;
    std::string getUsuario() const;

private:
    std::string usuario;
    int nota;
};

#endif

