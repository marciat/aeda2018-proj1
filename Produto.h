/**
 * Header File que cont�m as classes Produto, Medicamento, PassivelReceita e ProdutoInexistente
 *
 * @author M�rcia, Pedro e Rita
 * @date Novembro, 2018
 */
#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

/**
 * Classe Produto
 */
class Produto {
private:
	double codigo; //C�digo do Produto
	std::string nome; //Nome do Produto
	float preco; //Pre�o do Produto
	std::string descricao; //Descri��o do Produto
public:
	/**
	 * Construtor da classe Produto
	 * @param cod C�digo do Produto
	 * @param nome Nome do Produto
	 * @param preco Pre�o do Produto
	 * @param descricao Descri��o do produto
	 */
	Produto(double cod, std::string nome, float preco, std::string descricao);
	/**
	 * M�todo para obter o c�digo do Produto
	 * @return C�digo do Produto
	 */
	double getCodigo() const;
	/**
	 * M�todo para obter o nome do Produto
	 * @return Nome do Produto
	 */
	std::string getNome() const;
	/**
	 * M�todo para obter o pre�o do Produto
	 * @return Pre�o do Produto
	 */
	float getPreco() const;
	/**
	 * M�todo para obter a descri��o do Produto
	 * @return Descri��o do Produto
	 */
	std::string getDescricao() const;
	/**
	 * M�todo que permite alterar o pre�o de um Produto
	 * @param preco Pre�o a alterar
	 */
	void changePreco(float preco);
	/**
	 * Operador menor: Compara dois produtos com regras pr�-definidas
	 * @param p1 Produto que ir� ser comparado
	 * @return Retorna true se o produto for menor que p1. Caso contr�rio, retorna false
	 */
	bool operator< (const Produto &p1) const;
	/**
	 * Operador de igualdade: Compara dois produtos com regras pr�-definidas
	 * @param p1 Produto que ir� ser comparado
	 * @return Retorna true se o produto for igual a p1. Caso contr�rio, retorna false
	 */
	bool operator== (const Produto &p1) const;
};

/**
 * Class Medicamento, derivada publicamente de Produto
 */
class Medicamento : public Produto {
private:
	bool vendaSemReceita; //Booleano que indica se o medicamento pode ser vendido sem receita
public:
	Medicamento(bool receita, double cod, std::string nome, int preco, std::string desc);
	bool getVendaSemReceita() const;
	void setVendaSemReceita(bool vendaSemReceita);

};

class PassivelReceita : public Medicamento {
private:
	float taxaDesconto;
public:
	PassivelReceita(double cod, std::string nome, int preco, std::string desc, int desconto, bool semRec);
	float getTaxaDesconto() const;
	void setTaxaDesconto(float taxaDesconto);
};

class ProdutoInexistente {
	std::string nome;
public:
	ProdutoInexistente(std::string nomeProd) { nome = nomeProd; }
	std::string getNome() const { return nome; }
};


#endif
