/**
 * Header File que cont�m a classe Farmacia, a classe FarmaciaInexistente e um algoritmo para ordenar os vetores de todo o projeto.
 *
 * @author M�rcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef FARMACIA_H
#define FARMACIA_H

#include "Pessoa.h"
#include "Venda.h"

#include <vector>
#include <string>
#include <algorithm>
#include <map>

class Pessoa;
class Funcionario;
class Venda;

/**
 * Classe Farmacia
 */
class Farmacia {
private:
	std::string nome; //Nome da Farmacia
	std::string morada; //Morada da Farmacia
	Funcionario* gerente; //Apontador para o gerente da Farmacia(tipo Funcionario)
	Funcionario* diretorTecnico; //Apontador para o diretor t�cnico da Farmacia(tipo Funcionario)
	std::map<Produto, int> produtosVender; //Map cujas keys s�o objetos do tipo Produto e os valores s�o as quantidades desse produto. Serve para representar os produtos � venda
	std::vector<Venda*> vendas; //Vetor de apontador para objetos do tipo Venda
public:
	/**
	 * Construtor da Classe Farmacia
	 * @param nome Nome da farm�cia
	 * @param morada Morada da farm�cia
	 */
	Farmacia(std::string nome, std::string morada);
	/**
	 * M�todo que permite obter o nome da farm�cia
	 * @return Nome da farm�cia(atributo da classe)
	 */
	std::string getNome() const;
	/**
	 * M�todo que permite obter a morada da farm�cia
	 * @return Morada da farm�cia(atributo da classe)
	 */
	std::string getMorada() const;
	/**
	 * M�todo que permite obter o gerente da farm�cia
	 * @return Apontador para um objeto da classe Funcionario(atributo da classe)
	 */
	Funcionario* getGerente() const;
	/**
	 * M�todo que permite obter o diretor t�cnico da farm�cia
	 * @return Apontador para um objeto da classe Funcionario(atributo da classe)
	 */
	Funcionario* getDiretorTecnico() const;
	/**
	 * M�todo que permite obter todas as vendas realizadas na farm�cia
	 * @return Vetor de apontador para objetos da classe Venda(atributo da classse)
	 */
	std::vector<Venda*> getVendas() const;
	/**
	 * M�todo que permite obter os produtos dispon�veis para venda mais a sua quantidade
	 * @return Atributo da classe -> produtosVender
	 */
	std::map<Produto, int> getProdutosVender() const;
	/**
	 * M�todo que permite obter o n�mero de produtos dispon�veis para venda
	 * @return Tamanho do map produtosVender
	 */
	unsigned int getNumProdutos() const;
	/**
	 * M�todo que permite obter o n�mero de vendas realizadas na farm�cia
	 * @return Tamanho do vetor vendas
	 */
	unsigned int getNumVendas() const;
	/**
	 * M�todo que permite obter o n�mero de vendas realizadas entre dois dias
	 * @param d1, d2 Intervalo no qual se contam o n�mero de vendas
	 * @return N�mero de vendas realizadas no intervalo especificado
	 */
	unsigned int getNumVendasTempo(Data d1, Data d2) const;
	/**
	 * M�todo que permite obter as vendas realizadas entre dois dias
	 * @param d1, d2 Intervalo no qual se contabilizam as vendas
	 * @return Vetor de apontadores para objetos da classe Venda, com as vendas realizadas no intervalo especificado
	 */
	std::vector<Venda*> getVendasTempo(Data d1, Data d2) const;
	/**
	 * M�todo que permite obter o n�mero de vendas realizadas num dia
	 * @param d Dia no qual se realizaram as vendas
	 * @return N�mero de vendas realizadas no dia especificado
	 */
	unsigned int getNumVendasDia(Data d) const;
	/**
	 * M�todo que permite obter as vendas realizadas num dia
	 * @param d Dia no qual se realizaram as vendas
	 * @return Vetor de apontadores para objetos da classe Venda, com as vendas realizadas no dia especificado
	 */
	std::vector<Venda*> getVendasDia(Data d) const;
	/**
	 * M�todo que permite obter o pre�o de um determinado produto
	 * @param nomeProd Nome do produto do qual se quer saber o pre�o
	 * @return Pre�o do produto passado como argumento. Se n�o existir, retorna-se -1
	 */
	float getPrecoProduto(std::string nomeProd) const;
	/**
	 * M�todo que permite alterar o gerente da farm�cia
	 * @param gerente Apontador para Funcionario que ser� colocado no atributo gerente
	 */
	void setGerente(Funcionario* gerente);	
	/**
	 * M�todo que permite alterar o diretor t�cnico da farm�cia
	 * @param diretor Apontador para Funcionario que ser� colocado no atributo diretorTecnico
	 */
	void setDiretorTecnico(Funcionario* diretor){diretorTecnico = diretor;}
	/**
	 * M�todo que permite adicionar v�rios produtos ao map produtosVender
	 * @param produtosVender_new Vetor de apontadores para objetos da classe Produto
	 */
	void addProdutosVender(std::vector<Produto*> produtosVender_new);
	/**
	 * M�todo que permite adicionar um produto ao map produtosVender
	 * @param produtoVender Apontador para objeto da classe Porduto
	 * @return Booleano que indica se a opera��o foi efetuada com sucesso se for 0
	 */
	bool addProdutoVender(Produto* produtoVender);
	/**
	 * M�todo que permite remover um produto do map produtosVender
	 * @param nomeP Nome do produto a remover
	 * @return Retorna um apontador para o objeto removido ou, se este n�o existir, lan�a uma exce��o do tipo ProdutoInexistente
	 */
	Produto removeProduto(std::string nomeP);
	/**
	 * M�todo que permite realizar uma venda
	 * @param venda Apontador para objeto da classe Venda
	 */
	void addVenda(Venda* venda);
	/**
	 * M�todo que permite ordenar as vendas
	 * @param tipo Enumera��o do tipo tipoSort que permite ao utilizador escolher o modo de ordena��o do vetor
	 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordena��o por ordem crescente ou decrescente
	 */
	void sortVendas(enum tipoSort tipo, bool crescente);
	/**
	 * M�todo que permite saber se um determinado produto existe para venda
	 * @param nomeProduto Nome do produto a procurar
	 * @return Se existir, retorna-se true. Caso contr�rio, retorna-se false
	 */
	bool existeProduto(std::string nomeProduto) const;
	/**
	 * M�todo que permite saber se existe um determinado n�mero de unidades de um produto para venda
	 * @param nomeProduto Nome do produto a procurar
	 * @param quant N�mero de unidades do produto
	 * @return Se existir, retorna-se true. Caso contr�rio, retorna-se false
	 */
	bool existeProdutoQuant(std::string nomeProduto, int quant) const;
	/**
	 * M�todo que permite alterar a quantidade de um determinado produto
	 * @param nomeProd Nome do produto cuja quantidade ser� alterada
	 * @param quant Quantidade a alterar
	 * @return Retorna true se a opera��o foi realizada com sucesso. Caso contr�rio, retorna false
	 */
	bool setQuantidade(std::string nomeProd, int quant);
	/**
	 * Operador menor: Compara duas farm�cias com regras pr�-definidas
	 * @param f1 Farm�cia que ir� ser comparada
	 * @return Retorna true se a farm�cia for menor a f1. Caso contr�rio, retorna false
	 */
	bool operator< (const Farmacia &f1) const;
	/**
	 * M�todo semelhante ao operador menor, no qual o utilizador escolhe a forma de compara��o
	 * @param f1 Farm�cia que ir� ser comparada
	 * @param tipo Enumera��o do tipo tipoSort que permite ao utilizador escolher o modo de compara��o das duas farm�cias
	 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu crit�rio de modo crescente(true) ou decrescente(false)
	 * @return Retorna true se a farm�cia for menor que f1. Caso contr�rio, retorna false
	 */
	bool menorQue(const Farmacia &f1, enum tipoSort tipo, bool crescente) const;
	/**
	 * M�todo que permite imprimir no ecr� uma fatura
	 * @param v Apontador para objeto do tipo Venda que cont�m a venda da qual ser� impressa a fatura
	 */
	void imprimeFatura(Venda* v) const; //N�o sei se isto faz muito sentido aqui
};

/**
 * Classe FarmaciaInexistente
 */
class FarmaciaInexistente{
	std::string nome; //Nome da Farm�cia
public:
	/**
	 * Construtor da classe -> classe utilizada em exce��es
	 * @param nomeF Nome utilizado para a procura da farm�cia que n�o existe
	 */
	FarmaciaInexistente(std::string nomeF){nome = nomeF;}
	/**
	 * M�todo que permite obter o nome utilizado na procura da farm�cia
	 * @return Retorna o nome da farm�cia inexistente
	 */
	std::string getNome() const{return nome;}
};

/*
template<class T>
bool funcSort(T* a, T* b){
	return (*a)<(*b);
}*/


/**
 * M�todo usado no algoritmo quickSort
 * @param v Vetor a ordenar
 * @param left, rigth �ndices inicial e final do vetor
 * @param tipo Enumera��o do tipo tipoSort que permite ao utilizador escolher o modo de compara��o dos dois objetos
 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu crit�rio de modo crescente(true) ou decrescente(false)
 * @return Retorna o valor m�dio do vetor (?)
 */
template <class Comparable>
const Comparable &median3(std::vector<Comparable*> &v, int left,
		int right, enum tipoSort tipo, bool crescente)
{
	int center = (left+right) /2;
	if (v[center]->menorQue(*v[left], tipo, crescente))
		std::swap(v[left], v[center]);
	if (v[right]->menorQue(*v[left], tipo, crescente))
		std::swap(v[left], v[right]);
	if (v[right]->menorQue(*v[center], tipo, crescente))
		std::swap(v[center], v[right]);//coloca pivot na posicao right-1
	std::swap(v[center], v[right-1]);
	return *v[right-1];
}

/**
 * Algoritmo de Ordena��o
 * @param v Vetor a ordenar
 * @param left, rigth �ndices inicial e final do vetor
 * @param tipo Enumera��o do tipo tipoSort que permite ao utilizador escolher o modo de compara��o dos dois objetos
 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu crit�rio de modo crescente(true) ou decrescente(false)
 */
template <class Comparable>
void quickSort(std::vector<Comparable* > &v, int left, int right, enum tipoSort tipo, bool crescente)
{
	/*if (right-left <= 10)// se vetor pequeno
		insertionSort(v,left,right);
	else {*/
	Comparable x = median3(v,left,right, tipo, crescente); // x � o pivot
	int i = left; int j = right-1; // passo de parti��o
	for(; ; ) {
		while (v[++i]->menorQue(x, tipo, crescente)) ;
		while (x.menorQue(*v[--j], tipo, crescente)) ;
		if (i < j)
			std::swap(v[i], v[j]);
		else
			break;
	}
	std::swap(v[i], v[right-1]);//repoe pivot
	quickSort(v, left, i-1, tipo, crescente);
	quickSort(v, i+1, right, tipo, crescente);
	//}
}


#endif 
