#include "trata_string.h"


void lerString(std::shared_ptr<ListaLigada<char>> l)
{
	std::string s;

	getline(std::cin, s);

	for(unsigned int i = 0; i < s.size(); i++)
	{
		l->InsereNoFinal(s[i]);
	}
}