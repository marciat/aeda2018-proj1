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
protected:
	double codigo; //C�digo do Produto
	std::string nome; //Nome do Produto
	float preco; //Pre�o do Produto
	std::string descricao; //Descri��o do Produto
	bool passivelReceita; //true se produto for do tipo PassivelReceita
	float taxaDesconto; //Taxa de Desconto de um Medicamento pass�vel de receita
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
	 * M�todo para saber se o produto � do tipo PassivelReceita
	 * @return true se for PassivelReceita, se n�o retorna false
	 */
	bool getPassivelReceita() const;
	/**
	 * Operador de igualdade: Compara dois produtos com regras pr�-definidas
	 * @param p1 Produto que ir� ser comparado
	 * @return Retorna true se o produto for igual a p1. Caso contr�rio, retorna false
	 */
	bool operator== (const Produto &p1) const;
	/**
	 * M�todo para obter a taxa de desconto com receita
	 * @return Taxa de Desconto
	 */
	virtual float getTaxaDesconto() const {return 0;};
};

/**
 * Class Medicamento, derivada publicamente de Produto
 */
class Medicamento : public Produto {
public:
	/**
	 * Construtor da classe Medicamento
	 * @param cod, nome, preco, desc Atributos da classe Produto
	 */
	Medicamento(double cod, std::string nome, float preco, std::string desc);
};

class PassivelReceita : public Medicamento {
private:
	bool vendaSemReceita; //Booleano que indica se o medicamento pode ser vendido sem receita
public:
	/**
	 * Construtor da classe PassivelReceita
	 * @param cod, nome, preco, desc Atributos da classe Produto
	 * @param desconto Taxa de Desconto
	 * @param semRec Booleano que indica se o produto pode ser vendido sem receita
	 */
	PassivelReceita(double cod, std::string nome, float preco, std::string desc, float desconto, bool semRec);
	/**
	 * M�todo para obter a taxa de desconto com receita
	 * @return Taxa de Desconto
	 */
	float getTaxaDesconto() const;
	/**
	 * M�todo para alterar a taxa de desconto de um produto com receita
	 * @param taxaDesconto Taxa de desconto a alterar
	 */
	void setTaxaDesconto(float taxaDesconto);
	/**
	 * M�todo utilizado para saber se o medicamento pode ser vendido sem receita
	 * @return True se puder ser vendido sem receita. Caso contr�rio, retorna false
	 */
	bool getVendaSemReceita() const;
	/**
	 * M�todo para alterar a venda sem receita
	 * @param vendaSemReceita Deve ser true se o medicamento passar a poder ser vendido sem receita
	 */
	void setVendaSemReceita(bool vendaSemReceita);
};

/**
 * Classe ProdutoInexistente
 */
class ProdutoInexistente {
	std::string nome; //Nome do produto inexistente
public:
	/**
	 * Construtor da classe ProdutoInexistente
	 * @param nomeProd Nome do Produto
	 */
	ProdutoInexistente(std::string nomeProd) { nome = nomeProd; }
	/**
	 * M�todo para obter o nome do produto inexistente
	 * @return Nome do Produto
	 */
	std::string getNome() const { return nome; }
};


#endif
