#include <iostream>
#include <string>
#include <stack>
#include "lista.h"

bool verificaPalindromo(std::string s);
void tudoMinuscula(std:: string &s);

int main(int argc, char const *argv[])
{
	std::string palavra;
	std::cin >> palavra;

	tudoMinuscula(palavra);

	if(verificaPalindromo(palavra)){
		std::cout << "A palavra " << palavra << " é um palindromo." << std::endl; 
	}
	else
	{
		std::cout << "A palavra " << palavra << " não é um palindromo." << std::endl; 
	}

	return 0;
}

bool verificaPalindromo(std::string s)
{
	std::stack<char> pilha;

	for(unsigned int i = 0; i < s.size(); i++)
	{
		pilha.push(s[i]);
	}

	for(unsigned int  i = 0; i < s.size(); i++)
	{
		if(s[i] != pilha.top())
		{
			return false;
		}
		pilha.pop();
	}

	return true;
}

void tudoMinuscula(std:: string &s) 
{
	for(unsigned int i = 0; i < s.size(); i++)
	{
		if(s[i] < 'a')
		{
			s[i] += 32;
		}
	}
}