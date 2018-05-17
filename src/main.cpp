#include <iostream>
#include <memory>
#include "trata_string.h"

int main(int argc, char const *argv[])
{

	shared_ptr<ListaLigada<char>> lista = make_shared<ListaLigada<char>>();
	
	string palavra;

	getline(std::cin, palavra);

	lerString(lista, palavra);

	cout << lista->size() << std::endl;


	for(shared_ptr<Node<char>>iterator = lista->getCabeca(); iterator != lista->getCauda(); iterator = iterator->getNext())
	{
		cout << iterator->getValor();
	}

	cout << endl;

	removerEspacos(lista);
	tudoMinuscula(lista);

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