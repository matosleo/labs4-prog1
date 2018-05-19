/**
 * @file	pilha.h
 * @brief	Definicao da classe Pilha, que representa uma pilha e a implementação dos seus metodos genericos
 * @author	Teobaldo
 * @since	17/05/2018
 * @date	18/05/2018
 */

#ifndef Pilha_H
#define Pilha_H

#include <iostream>
#include <memory>


/**
 * @class   Pilha pilha.h
 * @brief   Classe que representa uma pilha
 * @details Os atributos de uma pilha são o vetor com dados, o tamanho maximo do vetor 
 *          e a quantidade de dados no vetor
 */

template <typename T>
class Pilha {
private:
	T* m_elementos;   /**< Elementos armazenados na pilha */
	int m_tamanho;    /**< Qtde de elementos */
	int m_capacidade; /**< Qtde Max de elementos */
public:

	/** @brief Construtor parametrizado */
	Pilha (int n_capacidade = 50);

	/** @brief Destrutor padrão */
	~Pilha ();
	
	/** @brief verifica se a pilha esta vazia */
	bool empty ();

	/** @brief verifica se a pilha esta cheia */
	bool full ();

	/** @brief Retorna o último elemento da pilha */
	T& top ();
	
	/** @brief Inseri um elemento na pilha */
	int push ( T novo );
	
	/** @brief Remove o último elemento da pilha */
	int pop ();
	
	/** @brief Retorna o tamanho da pilha */
	int size();
};

/**
 * @details O metodo generico inseri o elemento passado na proxima posicao livre do vetor
 * @param   el Elemento para inserir no vetor 
 */
template <typename T>
Pilha<T>::Pilha (int n_capacidade): m_tamanho(0), m_capacidade(n_capacidade)
{
	m_elementos = new T[n_capacidade];
}

/**
 * @details A pilha de dados é liberada
 */
template <typename T>
Pilha<T>::~Pilha ()
{
	delete [] m_elementos;
}

/**
 * @return True se estiver vazia e False caso contrário
 */
template <typename T>
bool Pilha<T>::empty ()
{
	return m_tamanho == 0;
}

/**
 * @return True se estiver cheia e False caso contrário
 */
template <typename T>
bool Pilha<T>::full ()
{
	return m_tamanho == m_capacidade;
}

/**
 * @details O metodo generico inseri o elemento passado na proxima posicao livro da pilha
 * @param   novo Elemento para inserir no vetor 
 */
template <typename T>
int Pilha<T>::push ( T novo )
{
	if (full())
		return 0;
	m_elementos[m_tamanho++] = novo;
	return 1;
}

/**
 * @return 1 se conseguir remover o elemento e 0 se não conseguir remover o elemento
 */	
template <typename T>
int Pilha<T>::pop ()
{
	if (empty())
		return 0;
	m_tamanho--; 
	return 1;
}

/**
 * @return O elemento do topo
 */
template <typename T>
T& Pilha<T>::top ()
{	
	if (empty()) {
		std::cerr << "Acesso invalido a elemento no topo. O programa sera fechado!" << std::endl;
		exit(EXIT_FAILURE);
	}
	return m_elementos[m_tamanho-1];
}

/**
 * @return O tamanho da pilha
 */
template <typename T>
int Pilha<T>::size ()
{
	return m_tamanho;
}

#endif // End of Pilha_H