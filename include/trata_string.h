#ifndef TRATA_STRING_H
#define TRATA_STRING_H

#include <string>
#include "pilha.h"
#include "lista.h"

void lerString(std::shared_ptr<ListaLigada<char>> l, string s);

void removeEspacos(std::shared_ptr<ListaLigada<char>> l);

void tudoMinuscula(std::shared_ptr<ListaLigada<char>> l);

void removeCaracEspeciais(std::shared_ptr<ListaLigada<char>> l);

bool verificaPalindromo(std::shared_ptr<ListaLigada<char>> l);

#endif