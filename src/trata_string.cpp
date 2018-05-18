#include "trata_string.h"


void lerString(std::shared_ptr<ListaLigada<char>> l, string s)
{
	for(unsigned int i = 0; i < s.size(); i++)
	{
		l->InsereNoFinal(s[i]);
	}
}

void removeEspacos(std::shared_ptr<ListaLigada<char>> l)
{
	int pos = 1;
	for(shared_ptr<Node<char>>iterator = l->getCabeca(); iterator != l->getCauda(); iterator = iterator->getNext())
	{
		if(iterator->getValor() == ' ')
		{
			l->RemoveNaPosicao(pos-1);
			pos--;
		}
		pos++;
	}
}

void tudoMinuscula(std::shared_ptr<ListaLigada<char>> l)
{
	for(shared_ptr<Node<char>>iterator = l->getCabeca(); iterator != l->getCauda(); iterator = iterator->getNext())
	{
		if(iterator->getValor() < ('Z'+1))
		{
			iterator->setValor(iterator->getValor()+32);
		}
	}	
}

void removeCaracEspeciais(std::shared_ptr<ListaLigada<char>> l)
{
	string especiais = "àÀáÁãÃâÂèÈéÉẽẼêÊìÌíÍĩĨîÎòÒóÓõÕôÔùÙúÚũŨûÛçÇ";
	string normais = "aaaaaaaaeeeeeeeeiiiiiiiioooooooouuuuuuuucc";
	int j;
	for(shared_ptr<Node<char>>iterator = l->getCabeca(); iterator != l->getCauda(); iterator = iterator->getNext())
	{
		for(unsigned int i = 0; i < especiais.size(); i++)
		{
			if(iterator->getValor() == especiais[i])
			{
				iterator->setValor(normais[i]);
			}
		}
	}
}

bool verificaPalindromo(std::shared_ptr<ListaLigada<char>> l)
{
	Pilha<char> pilha(l->size());

	for(shared_ptr<Node<char>>iterator = l->getCabeca(); iterator != l->getCauda(); iterator = iterator->getNext())
	{
		pilha.push(iterator->getValor());
	}

	for(shared_ptr<Node<char>>iterator = l->getCabeca(); iterator != l->getCauda(); iterator = iterator->getNext())
	{
		if(iterator->getValor() != pilha.top())
		{
			return false;
		}
		pilha.pop();
	}
	return true;
}

