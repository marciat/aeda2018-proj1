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
	/**
	 * Construtor da classe Medicamento
	 * @param receita Indica se o medicamento pode ser vendido sem receita
	 * @param cod, nome, preco, desc Atributos da classe Produto
	 */
	Medicamento(bool receita, double cod, std::string nome, int preco, std::string desc);
	/**
	 * M�todo que verifica se o medicamento pode ser ou n�o vendido sem receita
	 * @return Retorna true se puder ser vendido sem receita
	 */
	bool getVendaSemReceita() const;
	/**
	 * M�todo que permite alterar o atributo da classe
	 * @param vendaSemReceita Valor a colocar no atributo
	 */
	void setVendaSemReceita(bool vendaSemReceita);

};

/**
 * Classe PassivelReceita derivada publicamente de Medicamento
 */
class PassivelReceita : public Medicamento {
private:
	float taxaDesconto; //Taxa de desconto do medicamento caso sujeito a receita
public:
	/**
	 * Construtor da classe PassivelReceita
	 * @param desconto Taxa de desconto
	 * @param semRec Atributo da classe Medicamento
	 * @param cod, nome, preco, desc Atributos da classe Produto
	 */
	PassivelReceita(double cod, std::string nome, int preco, std::string desc, float desconto, bool semRec);
	/**
	 * M�todo que permite obter a taxa de desconto
	 * @return Taxa de Desconto do Medicamento caso sujeito a receita m�dica
	 */
	float getTaxaDesconto() const;
	/**
	 * M�todo que permite alterar a taxa de desconto
	 * @param taxaDesconto Taxa de desconto a ser alterada
	 */
	void setTaxaDesconto(float taxaDesconto);
};

/**
 * Classe ProdutoInexistente - utilizada em exce��es
 */
class ProdutoInexistente {
	std::string nome; //Nome do Produto inexistente
public:
	/**
	 * Construtor da classe Produto Inexistente
	 * @param nomeProd Nome do Produto Inexistente
	 */
	ProdutoInexistente(std::string nomeProd) { nome = nomeProd; }
	/**
	 * M�todo para obter o nome do produto que foi procurado e n�o existe
	 * @return Nome do Produto Inexistente
	 */
	std::string getNome() const { return nome; }
};


#endif
