/**
 * Header File que contem a classe Receita
 *
 * @author Marcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef RECEITA_H
#define RECEITA_H

#include "Produto.h"
#include "Pessoa.h"

#include <vector>
#include <string>
#include <map>
#include <iostream>

class Pessoa;
class Cliente;

/**
 * Classe Receita
 */
class Receita {
private:
	double numero; //N�mero da Receita
	std::string medico; //Nome do medico que prescreveu a Receita
	std::map<Produto, double>  produtos; //Map com os Produtos contidos na receita e respetiva quantidade
	Cliente* cliente; //Apontador para o Cliente ao qual a receita foi prescrita

public:
	/**
	 * Construtor da classe Receita
	 * @param numero N�mero da Receita
	 * @param medico Nome do medico que receitou
	 * @param cliente Apontador para objeto da classe Cliente ao qual a Receita foi prescrita
	 */
	Receita(double numero, std::string medico, Cliente* cliente);
	/**
	 * Metodo para obter o n�mero da Receita
	 * @return N�mero da Receita
	 */
	double getNumero() const;
	/**
	 * Metodo para obter o Cliente ao qual a Receita foi prescrita
	 * @return Apontador para objeto da classe Cliente
	 */
	Cliente* getCliente() const;
	/**
	 * Metodo para obter o nome do medico
	 * @return Nome do Medico
	 */
	std::string getMedico() const;
	/**
	 * Metodo para obter os produtos da receita
	 * @return Vetor de objetos da classe Produto
	 */
	std::vector<Produto> getProdutos() const;
	/**
	 * Metodo para obter o preco maximo de um produto
	 * @param nomeProd Nome do produto a procurar
	 * @return Retorna o preco maximo do produto. Caso nao exista, lanca uma excecao do tipo ProdutoInexistente
	 */
	double getPrecoMax(std::string nomeProd) const;
	/**
	 * Metodo para adicionar um Produto ao map de Produtos
	 * @param produto Apontador para objeto da classe Produto
	 * @param quant Quantidade do Produto
	 */
	void addProduto(Produto* produto, double quant);
	/**
	 * Metodo para remover um produto do map
	 * @param nome Nome do produto a remover
	 * @return Retorna o Produto removido. Caso nao exista, lanca uma excecao do tipo ProdutoInexistente
	 */
	Produto removeProduto(std::string nome);
	/**
	 * Metodo que permite saber se um produto existe na receita
	 * @param prod Apontador para o produto que se pretende saber se existe
	 * @return True se produto existir, caso contrario retorna false
	 */
	bool existeProdReceita(Produto* prod) const;
	/**
	 * Overload do operador para exportar a receita
	 * @param output Variavel para onde se quer exportar(ecra, ficheiro, ...)
	 * @param Receita que se quer exportar
	 * @return Retorna referencia para a variavel para onde se quer exportar
	 */
	friend std::ostream& operator<<(std::ostream &output, const Receita &r);
};

#endif
