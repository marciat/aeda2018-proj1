#ifndef RECEITA_H
#define RECEITA_H

#include "Produto.h"
#include "Pessoa.h"

#include <vector>
#include <string>
#include <map>

/**
 * Classe Receita
 */
class Receita {
private:
	double numero; //N�mero da Receita
	 //TODO criar classe medico para a receita
	std::string medico; //Nome do m�dico que prescreveu a Receita
	std::map<Produto, double>  produtos; //Map com os Produtos contidos na receita e respetiva quantidade
	Cliente* cliente; //Apontador para o Cliente ao qual a receita foi prescrita
public:
	/**
	 * Construtor da classe Receita
	 * @param numero N�mero da Receita
	 * @param medico Nome do m�dico que receitou
	 * @param cliente Apontador para objeto da classe Cliente ao qual a Receita foi prescrita
	 */
	Receita(double numero, std::string medico, Cliente* cliente);
	/**
	 * M�todo para obter o n�mero da Receita
	 * @return N�mero da Receita
	 */
	double getNumero() const;
	/**
	 * M�todo para obter o Cliente ao qual a Receita foi prescrita
	 * @return Apontador para objeto da classe Cliente
	 */
	Cliente* getCliente() const;
	/**
	 * M�todo para obter o nome do m�dico
	 * @return Nome do M�dico
	 */
	std::string getMedico() const;
	/**
	 * M�todo para obter os produtos da receita
	 * @return Vetor de objetos da classe Produto
	 */
	std::vector<Produto> getProdutos() const;
	/**
	 * M�todo para obter o pre�o m�ximo de um produto
	 * @param nomeProd Nome do produto a procurar
	 * @return Retorna o pre�o m�ximo do produto. Caso n�o exista, lan�a uma exce��o do tipo ProdutoInexistente
	 */
	double getPrecoMax(std::string nomeProd) const;
	/**
	 * M�todo para adicionar um Produto ao map de Produtos
	 * @param produto Apontador para objeto da classe Produto
	 * @param quant Quantidade do Produto
	 */
	void addProduto(Produto* produto, double quant);
	/**
	 * M�todo para remover um produto do map
	 * @param nome Nome do produto a remover
	 * @return Retorna o Produto removido. Caso n�o exista, lan�a uma exce��o do tipo ProdutoInexistente
	 */
	Produto removeProduto(std::string nome);
};

#endif
