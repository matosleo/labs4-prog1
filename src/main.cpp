/**
* @file     main.cpp
* @brief    Programa, usando TAD de lista, verifica se um conjunto de caracteres é palindromo atraves da TAD Pilha
* @author   Leonardo Matos (matos_leo95@live.com)
* @since	17/05/2018
* @date		18/05/2018
*/

#include <iostream>
#include <memory>
#include "trata_string.h"


/** 
 * @brief Função principal
 */
int main(int argc, char const *argv[])
{

	shared_ptr<ListaLigada<char>> lista = make_shared<ListaLigada<char>>();
	
	string palavra;

	getline(std::cin, palavra);

	lerString(lista, palavra);
	

	removeCaracEspeciais(lista);
	tudoMinuscula(lista);
	removeEspacosPontos(lista);


	if(verificaPalindromo(lista))
	{
		cout << palavra << " é palíndromo" << endl;
	}
	else
	{
		cout << palavra << " não é palíndromo" << endl;	
	}




	return 0;
}