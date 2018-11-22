
/**
 * Header File que contem a classe Venda
 *
 * @author Marcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef VENDA_H
#define VENDA_H

#include "util.h"

#include "Data.h"
#include "Produto.h"
#include "Receita.h"
#include "Pessoa.h"

#include <vector>
#include <string>
#include <map>

/**
 * Classe Venda
 */
class Venda {
private:
	double codigo; //Codigo da venda
	static double codigo_sequencial; //Variavel usada para que os codigos das vendas sejam sequenciais (primeira venda tem codigo 0)
	std::map<Produto, std::vector<float>> produtosVendidos; //Map cujas keys s�o objetos do tipo Produto e o valor � um vetor com quantidade, iva e comparticipa��o
	Data data; //Data na qual foi realizada a venda
	Hora hora; //Hora � qual foi realizada a venda
	double totalVenda; //Valor total da venda
	bool temReceita; //Indica se a venda tem uma receita associada (true quando tem)
	Receita* receitaVenda; //Caso a venda tenha uma receita associada, receitaVenda guarda um apontador para essa receita
	Cliente* clienteVenda; //Cliente ao qual est� associada a venda

public:
	/**
	 * Construtor da classe Venda
	 */
	Venda();
	/**
	 * Construtor da classe Venda
	 * @param receitaVenda Apontador para a receita associada � venda
	 * @param clienteVenda Apontador para o cliente associado � venda
	 */
	Venda(Receita* receitaVenda, Cliente* clienteVenda);
	/**
	 * Construtor da classe Venda
	 * @param dia, mes, ano, horas, min, segundos, codigo Dados correspondentes � data, hora e codigo da venda
	 */
	Venda(unsigned short dia, unsigned short mes, int ano, unsigned short horas, unsigned short min, unsigned short segundos, double codigo);
	/**
	 * M�todo que permite obter o valor total da venda
	 * @return totalVenda (atributo da classe)
	 */
	double getTotalVenda() const;
	/**
	 * M�todo que permite obter o map com os produtos vendidos
	 * @return produtosVendidos (atributo da classe)
	 */
	std::map<Produto, std::vector<float>> getProdutosVendidos() const;
	/**
	 * M�todo que permite atribuir uma receita � venda
	 * S� � poss�vel atribuir uma receita � venda se esta n�o tiver ainda nenhuma receita associada
	 * @param receitaVenda Apontador para a receita a associar
	 * @return True se foi poss�vel atribuir a receita e false se n�o tiver sido poss�vel
	 */
	bool setReceita(Receita* receitaVenda);
	/**
	 * M�todo que permite atribuir um cliente � venda
	 * S� � poss�vel atribuir um cliente � venda se esta n�o tiver ainda nenhum cliente associado
	 * @param clienteVenda Apontador para o cliente a associar
	 * @return True se foi poss�vel atribuir o cliente e false se n�o tiver sido poss�vel
	 */
	void setCliente(Cliente* clienteVenda);
	/**
	 * M�todo que permite obter o n�mero de produtos vendidos
	 * @return Tamanho de produtosVendidos (atributo da classe)
	 */
	unsigned int getNumProdutos() const;
	/**
	 * M�todo que permite obter o cliente da venda
	 * @return Cliente associado � venda, se ainda n�o houver nenhum cliente associado retorna NULL
	 */
	Cliente* getCliente();
	/**
	 * M�todo que permite obter a receita da venda
	 * @return Receita associada � venda, se n�o houver nenhuma receita associada retorna NULL
	 */
	Receita* getReceita();
	/**
	 * M�todo que permite obter a data da venda
	 * @return Objeto do tipo Data
	 */
	Data getData() const;
	/**
	 * M�todo que permite obter a hora da venda
	 * @return Objeto do tipo Hora
	 */
	Hora getHora() const;
	/**
	 * Metodo que permite obter o codigo da venda
	 * @return codigo da venda
	 */
	double getCodigo() const;
	/**
	 * M�todo que permite obter o pre�o de um produto
	 * @param nomeProd Nome do produto que ir� ser procurado
	 * @return Pre�o do produto especificado como argumento. Retorna -1 se n�o existir
	 */
	float getPrecoProduto(std::string nomeProd) const;
	/**
	 * M�todo que permite adicionar um produto � venda
	 * @param prod Apontador para objeto da classe Produto
	 * @param quant, iva Valores do tipo float que ser�o colocados do vetor do map produtosVendidos
	 * @return True se foi possivel adicionar o produto, false se nao foi (se necessitar de ser vendido com receita e nao estiver contido na receita associada a venda)
	 */
	bool addProduto(Produto* prod, float quant, float iva);
	/**
	 * Operador menor: compara dois objetos do tipo Venda com regras pr�-definidas
	 * @param v1 Objeto do tipo Venda
	 * @return Retorna true se a venda for menor que v1. Caso contr�rio, retorna false
	 */
	bool operator< (const Venda &v1) const;
	/**
	 * M�todo que permite imprimir no ecr� uma fatura
	 */
	void imprimeFatura() const;
	/**
	 * M�todo semelhante ao operador menor, no qual o utilizador escolhe a forma de compara��o
	 * @param v1 Venda que ir� ser comparada
	 * @param tipo Enumera��o do tipo tipoSort que permite ao utilizador escolher o modo de compara��o das duas vendas
	 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu crit�rio de modo crescente(true) ou decrescente(false)
	 * @return Retorn true se a venda for menor que v1. Caso contr�rio, retorn false
	 */
	bool menorQue(const Venda &v1, enum tipoSort tipo, bool crescente) const;
	/**
	 * Overload de operador << para exportar a venda
	 * @param output Variavel para onde se quer exportar(ecra, ficheiro, ...)
	 * @param v1 Venda que se quer exportar
	 * @return Retorna referencia para a variavel para onde se quer exportar
	 */
	friend std::ostream& operator<<(std::ostream &output, const Venda &v1);
};

#endif
