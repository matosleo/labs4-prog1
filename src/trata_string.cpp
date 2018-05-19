/**
* @file     trata_string.cpp
* @brief    Implementacao das funcoes que fazem o tratamento de strings
* @author	Leonardo Matos (matos_leo95@live.com)
* @since	17/05/2018
* @date		18/05/2018
*/

#include "trata_string.h"


/**
 * @brief Funcao que insere numa TAD lista uma cadeia de caracteres
 * @param l ponteiro inteligente shared_ptr do tipo ListaLigada char e s do tipo string
 */
void lerString(std::shared_ptr<ListaLigada<char>> l, string s)
{
	for(unsigned int i = 0; i < s.size(); i++)
	{
		l->InsereNoFinal(s[i]);
	}
}

/**
 * @brief Funcao que remove espaços e pontos na cadeia de caracteres
 * @param l ponteiro inteligente shared_ptr do tipo ListaLigada char
 */
void removeEspacosPontos(std::shared_ptr<ListaLigada<char>> l)
{
	int pos = 1;
	for(shared_ptr<Node<char>>iterator = l->getCabeca(); iterator != l->getCauda(); iterator = iterator->getNext())
	{
		if(iterator->getValor() < 97 || iterator->getValor() > 122)
		{
			l->RemoveNaPosicao(pos-1);
			pos--;
		}
		pos++;
	}
}

/**
 * @brief Funcao que subistitui letras maiúsculas para minúsculas
 * @param l ponteiro inteligente shared_ptr do tipo ListaLigada char
 */
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

/**
 * @brief Funcao que remove caracteres especiais, como letras com pontuação
 * @param l ponteiro inteligente shared_ptr do tipo ListaLigada char
 */
void removeCaracEspeciais(std::shared_ptr<ListaLigada<char>> l)
{
	string especiais = "àÀáÁãÃâÂèÈéÉẽẼêÊìÌíÍĩĨîÎòÒóÓõÕôÔùÙúÚũŨûÛçÇ";
	string normais = "aaaaaaaaeeeeeeeeiiiiiiiiooooooooouuuuuuuucc";
	int cont = 0;
	int k = 0;
	for(shared_ptr<Node<char>>iterator = l->getCabeca(); iterator != l->getCauda(); iterator = iterator->getNext())
	{
		k = 0;
		for(unsigned int i = 0; i < especiais.size(); i += 2)
		{
			
			if(iterator->getValor() == especiais[i] && iterator->getNext()->getValor() == especiais[i+1])
			{
				iterator->setValor(normais[k]);
				l->RemoveNaPosicao(cont+1);
			}
			k++;
		}
		cont++;
	}
}

/**
 * @brief Funcao que verifica se a cadeia de caracteres é palíndromo
 * @param l ponteiro inteligente shared_ptr do tipo ListaLigada char
 * @return True se a cadeia de caracteres for palindromo ou False caso contrário
 */
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

