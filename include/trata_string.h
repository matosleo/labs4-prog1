#ifndef TRATA_STRING_H
#define TRATA_STRING_H

#include <string>
#include <stack>
#include "lista.h"

void lerString(std::shared_ptr<ListaLigada<char>> l);

void removerEspacos(std::shared_ptr<ListaLigada<char>> l);

void tudoMinuscula(std::shared_ptr<ListaLigada<char>> l);

#endif