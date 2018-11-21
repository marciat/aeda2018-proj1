/**
 * Header File que contem as classes Produto, Medicamento, PassivelReceita e ProdutoInexistente
 *
 * @author Marcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef PESSOA_H
#define PESSOA_H

#include "Venda.h"
#include "Farmacia.h"

#include <string>
#include <vector>

class Farmacia;
/**
 * Classe Pessoa
 */
class Pessoa {
protected:
	std::string nome; //Nome da Pessoa
	std::string morada; //Morada da Pessoa
	double noContribuinte; //N�mero de Contribuinte da Pessoa
public:
	/**
	 * Construtor da classe Pessoa
	 * @param nome Nome da Pessoa
	 * @param morada Morada da Pessoa
	 * @param cont N�mero de contribuinte da Pessoa
	 */
	Pessoa(std::string nome, std::string morada, double cont);
	/**
	 * Destrutor da classe Pessoa
	 */
	virtual ~Pessoa() {}
	/**
	 * M�todo que permite obter o nome da pessoa
	 * @return Nome da Pessoa
	 */
	std::string getNome() const;
	/**
	 * M�todo que permite obter a morada da Pessoa
	 * @return Morada da Pessoa
	 */
	std::string getMorada() const;
	/**
	 * M�todo que permite obter o n�mero de contribuinte da pessoa
	 * @return N�mero de contribuinte
	 */
	double getNoContribuinte() const;
	/**
	 * M�todo puramente virtual que, nas classes derivadas, imprime no ecr� os atributos da classe
	 */
	virtual void showInfo() const = 0;
};

/**
 * Classe Funcionario
 */
class Funcionario : public Pessoa {
private:
	double salario; //Salario do Funcionario
	Farmacia* farmaciaTrabalho; //Apontador para a Farmacia onde o Funcionario trabalha
	std::string cargo; //Cargo na Farmacia (funcionario, gerente,...)
public:
	/**
	 * Construtor da classe Funcionario
	 * @param nome Nome do Funcionario/Pessoa
	 * @param morada Morada do Funcionario/Pessoa
	 * @param cont N�mero de Contribuinte do Funcionario/Pessoa
	 * @param sal Sal�rio do Funcionario: caso n�o seja atribu�do, ser� 500
	 */
	Funcionario(std::string nome, std::string morada, double cont, double sal = 500);
	/**
	 * Destrutor da classe Pessoa
	 */
	~Funcionario() {}
	/**
	 * M�todo para alterar a Farmacia onde o Funcionario trabalha
	 * @param f Apontador para Farmacia onde o Funcionario trabalha
	 */
	void setFarmacia(Farmacia* f);
	/**
	 * M�todo que permite obter a Farmacia onde o Funcionario trabalha
	 * @return Apontador para Farmacia
	 */
	Farmacia* getFarmacia() const {return farmaciaTrabalho;}
	/**
	 * M�todo que permite obter o sal�rio do Funcionario
	 * @return Sal�rio do Funcionario
	 */
	double getSalario() const;
	/**
	 * M�todo que permite obter o cargo do Funcionario
	 * @return Cargo do Funcionario na Farmacia onde trabalha
	 */
	std::string getCargo() const;
	/**
	 * M�todo que permite alterar o sal�rio do Funcionario
	 * @param salario Sal�rio do Funcionario a alterar
	 */
	void changeSalario(double salario);
	/**
	 * M�todo que imprime no ecr� os atributos de um Funcionario
	 */
	void showInfo() const;
	/**
	 * Operador menor: Compara dois funcion�rios com regras pr�-definidas
	 * @param f1 Funcion�rio que ir� ser comparado
	 * @return Retorna true se o funcion�rio for menor que f1. Caso contr�rio, retorna false
	 */
	bool operator< (const Funcionario &f1) const;
	/**
	 * M�todo semelhante ao operador menor, no qual o utilizador escolhe a forma de compara��o
	 * @param f1 Funcion�rio que ir� ser comparado
	 * @param tipo Enumera��o do tipo tipoSort que permite ao utilizador escolher o modo de compara��o dos dois funcion�rios
	 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu crit�rio de modo crescente(true) ou decrescente(false)
	 * @return Retorna true se o funcion�rio for menor que f1. Caso contr�rio, retorna false
	 */
	bool menorQue(const Funcionario &f1, enum tipoSort tipo, bool crescente) const;
};

/**
 * Classe Cliente
 */
class Cliente : public Pessoa {
private:
	std::vector<Venda*> historialCompras; //Historial de Compras do Cliente
public:
	/**
	 * Construtor da classe Cliente
	 * @param nome Nome do Cliente/Pessoa
	 * @param morada Morada do Cliente/Pessoa
	 * @param contribuinte N�mero de Contribuinte do Cliente/Pessoa
	 */
	Cliente(std::string nome, std::string morada, double contribuinte);
	/**
	 * Destrutor da classe Cliente
	 */
	~Cliente() {}
	/**
	 * M�todo para obter o historial de compras do Cliente
	 * @return Vetor de apontadores para objetos da classe Venda
	 */
	std::vector<Venda*> getHistorialCompras() const;
	/**
	 * M�todo para obter o n�mero de compras realizadas pelo Cliente
	 * @return Tamanho do vetor historialCompras
	 */
	unsigned int getNumCompras() const;
	/**
	 * M�todo para adicionar uma compra ao historial
	 * @param compra Apontador para objeto da classe Venda
	 */
	void addCompra(Venda* compra);
	/**
	 * M�todo que imprime no ecr� os atributos de um Funcionario
	 */
	void showInfo() const;
	/**
	 * Operador menor: Compara dois clientes com regras pr�-definidas
	 * @param c1 Cliente que ir� ser comparado
	 * @return Retorna true se o cliente for menor que c1. Caso contr�rio, retorna false
	 */
	bool operator< (const Cliente &c1) const;
	/**
	 * M�todo semelhante ao operador menor, no qual o utilizador escolhe a forma de compara��o
	 * @param c1 Cliente que ir� ser comparado
	 * @param tipo Enumera��o do tipo tipoSort que permite ao utilizador escolher o modo de compara��o dos dois clientes
	 * @param crescente Booleano que permite ao utilizador escolher se quer utilizar o seu crit�rio de modo crescente(true) ou decrescente(false)
	 * @return Retorna true se o cliente for menor que c1. Caso contr�rio, retorna false
	 */
	bool menorQue(const Cliente &c1, enum tipoSort tipo, bool crescente) const;
};

/**
 * Classe ClienteInexistente
 */
class ClienteInexistente{
	std::string nome; //Nome do Cliente
public:
	/**
	 * Construtor da classe -> classe utilizada em exce��es
	 * @param nomeC Nome utilizado para a procura do cliente que n�o existe
	 */
	ClienteInexistente(std::string nomeC){nome = nomeC;}
	/**
	 * M�todo que permite obter o nome utilizado na procura do cliente
	 * @return Retorna o nome do cliente inexistente
	 */
	std::string getNome() const {return nome;}
};

/**
 * Classe FuncionarioInexistente
 */
class FuncionarioInexistente{
	std::string nome; //Nome do Funcionario
public:
	/**
	 * Construtor da classe -> classe utilizada em exce��es
	 * @param nomeF Nome utilizado para a procura do funcion�rio que n�o existe
	 */
	FuncionarioInexistente(std::string nomeF){nome = nomeF;}
	/**
	 * M�todo que permite obter o nome utilizado na procura do funcion�rio
	 * @return Retorna o nome do funcion�rio inexistente
	 */
	std::string getNome() const {return nome;}
};

#endif
