/**
 * Header File que contem enumeracoes e metodos sort importantes para o projeto
 *
 * @author Marcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef UTIL_H
#define UTIL_H

#include <vector>

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
 * Valores: QUANTIDADE = unidades do produto vendidas; IVA = percentagem de IVA do produto; COMPARTICIPACAO = percentagem de comparticipacao do produto; PRECO_PAGO = preco pago pelo produto, tendo em conta o IVA e a comparticipacao
 */
enum dadosProd {QUANTIDADE, IVA, COMPARTICIPACAO, PRECO_PAGO};

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
}

class Receita;
class Pessoa;
class Cliente;
class Funcionario;
class Venda;

#endif
