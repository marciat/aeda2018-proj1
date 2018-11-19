#ifndef UTIL_H
#define UTIL_H

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

class Receita;
class Pessoa;
class Cliente;
class Funcionario;
class Venda;

#endif
