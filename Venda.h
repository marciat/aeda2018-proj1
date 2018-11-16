/**
 * Header File que cont�m a classe Venda
 *
 * @author M�rcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef VENDA_H
#define VENDA_H

#include "Data.h"
#include "Produto.h"
#include "Receita.h"

#include <vector>
#include <string>
#include <map>

class Receita;

/**
 * Declara��o de uma enumera��o: tipoSort
 * � utilizada para todas as opera��es de sort
 * Valores: NOME = ordena��o por nome; CONTIBUINTE = ordena��o por contribuinte; NUM_PROD = ordena��o por n�mero de produtos;
 * 			NUM_VENDA = ordena��o por n�mero de vendas/compras; SALARIO = ordena��o por sal�rio; DATA = ordena��o por data;
 * 			HORA = ordena��o por hora; DEFAULT = ordena��o por um crit�rio pr�-definido
 */
enum tipoSort {NOME, CONTRIBUINTE, NUM_PROD, NUM_VENDA, SALARIO, DATA, HORA, DEFAULT};

/**
 * Declara��o de uma enumera��o: dadosProd
 * � utilizada para facilitar o acesso a dados de um produto numa venda
 * Valores: QUANTIDADE = unidades do produto vendidas; IVA = percentagem de IVA do produto; COMPARTICIPACAO = percentagem de comparticipacao do produto
 */
enum dadosProd {QUANTIDADE, IVA, COMPARTICIPACAO};

/**
 * Classe Venda
 */
class Venda {
private:
	std::map<Produto, std::vector<float>> produtosVendidos; //Map cujas keys s�o objetos do tipo Produto e o valor � um vetor com quantidade, iva e comparticipa��o
	Data data; //Data na qual foi realizada a venda
	Hora hora; //Hora � qual foi realizada a venda
	double totalVenda; //Valor total da venda
	bool temReceita; //Indica se a venda tem uma receita associada (true quando tem)
	Receita* receitaVenda; //Caso a venda tenha uma receita associada, receitaVenda guarda um apontador para essa receita

public:
	/**
	 * Construtor da classe Venda
	 */
	Venda();
	/**
	 * Construtor da classe Venda
	 * @param receitaVenda Apontador para a receita associada � venda
	 */
	Venda(Receita* receitaVenda);
	/**
	 * Construtor da classe Venda
	 * @param dia, mes, ano, horas, min, segundos Dados correspondentes � data e hora da venda
	 */
	Venda(unsigned short dia, unsigned short mes, int ano, unsigned short horas, unsigned short min, unsigned short segundos);
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
	 * @return True se foi poss�vel atribuir a receita e false se n�o tiver sido poss�vel
	 */
	bool setReceita(Receita* receitaVenda);
	/**
	 * M�todo que permite obter o n�mero de produtos vendidos
	 * @return Tamanho de proudtosVenidos (atributo da classe)
	 */
	unsigned int getNumProdutos() const;
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
	 * M�todo que permite obter o pre�o de um produto
	 * @param nomeProd Nome do produto que ir� ser procurado
	 * @return Pre�o do produto especificado como argumento. Retorna -1 se n�o existir
	 */
	float getPrecoProduto(std::string nomeProd) const;
	/**
	 * M�todo que permite adicionar um produto � venda
	 * @param prod Apontador para objeto da classe Produto
	 * @param quant, iva, comparticipacao Valores do tipo float que ser�o colocados do vetor do map produtosVendidos
	 */
	void addProduto(Produto* prod, float quant, float iva, float comparticipacao);
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
};

#endif
