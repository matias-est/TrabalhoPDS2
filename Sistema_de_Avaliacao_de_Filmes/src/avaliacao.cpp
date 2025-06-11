#include "avaliacao.h"

Avaliacao::Avaliacao(const std::string &usuario, int nota) : usuario(usuario), nota(nota) {}

int Avaliacao::getNota() const
{
    return nota;
}

std::string Avaliacao::getUsuario() const
{
    return usuario;
}
