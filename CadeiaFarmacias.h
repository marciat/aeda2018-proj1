/**
 * Header File que cont�m a classe CadeiaFarmacias.
 *
 * @author M�rcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef CADEIAFARMACIAS_H
#define CADEIAFARMACIAS_H

#include "Farmacia.h"
#include <vector>

/**
 * Classe CadeiaFarmacias
 */
class CadeiaFarmacias {
private:
	std::vector<Farmacia *> farmacias; //Vetor de apontadores para objetos do tipo Farmacia
	std::vector <Cliente*> clientes; //Vetor de apontadores para objetos do tipo Cliente
	std::vector <Funcionario*> funcionarios; //Vetor de apontadores para objetos do tipo Funcionario
public:
	/**
	 *  Construtor da classe
	 * 	Inicializa um objeto da classe colocando todos os vetores vazios
	 */
	CadeiaFarmacias();
	/**
	 * M�todo que retorna o n�mero de farm�cias
	 * @return Tamanho do vetor de farm�cias(unsigned int)
	 */
	unsigned int getNumFarmacias() const;
	/**
	 * M�todo que retorna o n�mero de clientes
	 * @return Tamanho do vetor de clientes(unsigned int)
	 */
	unsigned int getNumClientes() const;
	/**
	 * M�todo que retorna o n�mero de funcion�rios
	 * @return Tamanho do vetor de funcion�rios(unsigned int)
	 */
	unsigned int getNumFuncionarios() const;
	/**
	 * M�todo que retorna um vetor de farm�cias
	 * @return Vetor farmacias (atributo da classe)
	 */
	std::vector<Farmacia *> getFarmacias() const;
	/**
	 * M�todo que retorna um vetor de clientes
	 * @return Vetor clientes (atributo da classe)
	 */
	std::vector <Cliente*> getClientes() const;
	/**
	 * M�todo que retorna um vetor de funcion�rios
	 * @return Vetor funcionarios (atributo da classe)
	 */
	std::vector <Funcionario*> getFuncionarios() const;
	/**
	 * M�todo que permite adicionar um apontador para Farm�cia ao respetivo vetor
	 * @param farmacia Apontador para objeto do tipo Farmacia que ser� adicionado ao vetor farmacias
	 */
	void addFarmacia(Farmacia* farmacia);
	/**
	 * M�todo que permite eliminar a Farmacia nomeF do respetivo vetor. Tamb�m remove o apontador Farmacia de todos os funcionarios caso seja o mesmo
	 * @param nomeF Nome da farm�cia que ser� removida do vetor
	 * @return Retorna um apontador para o objeto removido ou, se este n�o existir, lan�a uma exce��o do tipo FarmaciaInexistente
	 */
	Farmacia* removeFarmacia(const std::string &nomeF);
	/**
	 * M�todo que permite ordenar as farm�cias
	 * @param tipo Enumera��o do tipo tipoSort que permite ao utilizador escolher o modo de ordena��o do vetor
	 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordena��o por ordem crescente ou decrescente
	 */
	void sortFarmacias(enum tipoSort tipo, bool crescente);
	/**
	 * M�todo que permite adicionar um apontador para Cliente ao respetivo vetor
	 * @param cliente Apontador para objeto do tipo Cliente que ser� adicionado ao vetor clientes
	 */
	void addCliente(Cliente* cliente);
	/**
	 * M�todo que permite eliminar o Cliente nomeC do respetivo vetor
	 * @param nomeC Nome do cliente que ser� removido do vetor
	 * @return Retorna um apontador para o objeto removido ou, se este n�o existir, lan�a uma exce��o do tipo ClienteInexistente
	 */
	Cliente* removeCliente(const std::string &nomeC);
	/**
	 * M�todo que permite ordenar os clientes
	 * @param tipo Enumera��o do tipo tipoSort que permite ao utilizador escolher o modo de ordena��o do vetor
	 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordena��o por ordem crescente ou decrescente
	 */
	void sortClientes(enum tipoSort tipo, bool crescente);
	/**
	 * M�todo que permite adicionar um apontador para Funcionario ao respetivo vetor
	 * @param funcionario Apontador para objeto do tipo Funcionario que ser� adicionado ao vetor funcionarios
	 */
	void addFuncionario(Funcionario* funcionario);
	/**
	 * M�todo que permite eliminar o Funcionario nomeF do respetivo vetor
	 * @param nomeF Nome do funcionario que ser� removido do vetor
	 * @return Retorna um apontador para o objeto removido ou, se este n�o existir, lan�a uma exce��o do tipo FuncionarioInexistente
	 */
	Funcionario* removeFuncionario(const std::string &nomeF);
	/**
	 * M�todo que permite ordenar os funcion�rios
	 * @param tipo Enumera��o do tipo tipoSort que permite ao utilizador escolher o modo de ordena��o do vetor
	 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordena��o por ordem crescente ou decrescente
	 */
	void sortFuncionarios(enum tipoSort tipo, bool crescente);
};

#endif
