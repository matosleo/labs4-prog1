/**
* @file     trata_string.h
* @brief    Definição das funções para tratar a expressão pos-fixa
* @author	Leonardo Matos (matos_leo95@live.com)
* @since	17/05/2018
* @date		18/05/2018
 * @sa		https://github.com/matosleo/labs4-prog1
*/

#ifndef TRATA_STRING_H
#define TRATA_STRING_H

#include <string>
#include "pilha.h"
#include "lista.h"

void lerString(std::shared_ptr<ListaLigada<char>> l, string s);

void removeEspacosPontos(std::shared_ptr<ListaLigada<char>> l);

void tudoMinuscula(std::shared_ptr<ListaLigada<char>> l);

void removeCaracEspeciais(std::shared_ptr<ListaLigada<char>> l);

bool verificaPalindromo(std::shared_ptr<ListaLigada<char>> l);

#endif