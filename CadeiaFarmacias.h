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
	CadeiaFarmacias(); //Construtor da classe
	unsigned int getNumFarmacias() const; //M�todo que retorna o n�mero de farm�cias
	unsigned int getNumClientes() const; //M�todo que retorna o n�mero de clientes
	unsigned int getNumFuncionarios() const; //M�todo que retorna o n�mero de funcion�rios
	std::vector<Farmacia *> getFarmacias() const; //M�todo que retorna um vetor de farm�cias
	std::vector <Cliente*> getClientes() const; //M�todo que retorna um vetor de clientes
	std::vector <Funcionario*> getFuncionarios() const; //M�todo que retorna um vetor de funcion�rios
	void addFarmacia(Farmacia* farmacia); //M�todo que permite adicionar um apontador para Farm�cia ao respetivo vetor
	Farmacia* removeFarmacia(const std::string &nomeF); //M�todo que permite eliminar a Farm�cia nomeF do respetivo vetor
	void sortFarmacias(enum tipoSort tipo, bool crescente); //M�todo que permite ordenar as farm�cias
	void addCliente(Cliente* cliente); //M�todo que permite adicionar um apontador para Cliente ao respetivo vetor
	Cliente* removeCliente(const std::string &nomeC); //M�todo que permite eliminar o Cliente nomeC do respetivo vetor
	void sortClientes(enum tipoSort tipo, bool crescente); //M�todo que permite ordenar os clientes
	void addFuncionario(Funcionario* funcionario); //M�todo que permite adicionar um apontador para Funcionario ao respetivo vetor
	Funcionario* removeFuncionario(const std::string &nomeF); //M�todo que permite eliminar o Funcionario nomeF do respetivo vetor
	void sortFuncionarios(enum tipoSort tipo, bool crescente); //M�todo que permite ordenar os funcion�rios
};

#endif
