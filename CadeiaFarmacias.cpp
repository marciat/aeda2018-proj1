#include "CadeiaFarmacias.h"

using namespace std;

/**
 *  Construtor da classe
 * 	Inicializa um objeto da classe colocando todos os vetores vazios
 */
CadeiaFarmacias::CadeiaFarmacias() {
	farmacias.resize(0);
	clientes.resize(0);
	funcionarios.resize(0);
}

/**
 * M�todo que retorna o n�mero de farm�cias
 * @return Tamanho do vetor de farm�cias(unsigned int)
 */
unsigned int CadeiaFarmacias::getNumFarmacias() const {
	return farmacias.size();
}

/**
 * M�todo que retorna o n�mero de clientes
 * @return Tamanho do vetor de clientes(unsigned int)
 */
unsigned int CadeiaFarmacias::getNumClientes() const {
	return clientes.size();
}

/**
 * M�todo que retorna o n�mero de funcion�rios
 * @return Tamanho do vetor de funcion�rios(unsigned int)
 */
unsigned int CadeiaFarmacias::getNumFuncionarios() const {
	return funcionarios.size();
}

/**
 * M�todo que retorna um vetor de farm�cias
 * @return Vetor farmacias (atributo da classe)
 */
vector<Farmacia *> CadeiaFarmacias::getFarmacias() const {
	return farmacias;
}

/**
 * M�todo que retorna um vetor de clientes
 * @return Vetor clientes (atributo da classe)
 */
vector <Cliente*>  CadeiaFarmacias::getClientes() const {
	return clientes;
}

/**
 * M�todo que retorna um vetor de funcion�rios
 * @return Vetor funcionarios (atributo da classe)
 */
vector <Funcionario*> CadeiaFarmacias::getFuncionarios() const {
	return funcionarios;
}

/**
 * M�todo que permite adicionar um apontador para Farm�cia ao respetivo vetor
 * @param farmacia Apontador para objeto do tipo Farmacia que ser� adicionado ao vetor farmacias
 */
void CadeiaFarmacias::addFarmacia(Farmacia* farmacia) {
	farmacias.push_back(farmacia);
}

/**
 * M�todo que permite eliminar a Farmacia nomeF do respetivo vetor. Tamb�m remove o apontador Farmacia de todos os funcionarios caso seja o mesmo
 * @param nomeF Nome da farm�cia que ser� removida do vetor
 * @return Retorna um apontador para o objeto removido ou, se este n�o existir, lan�a uma exce��o do tipo FarmaciaInexistente
 */
Farmacia* CadeiaFarmacias::removeFarmacia(const string &nomeF){
	vector<Farmacia*>::iterator it = farmacias.begin();
	for (; it != farmacias.end(); it++){ //Percorrer o vetor farmacias
		if ((*it)->getNome() == nomeF){
			farmacias.erase(it); //Eliminar o elemento pretendido
			vector<Funcionario*>::iterator itFunc = funcionarios.begin();
			for(; itFunc != funcionarios.end(); itFunc++){ //Percorrer o vetor funcionarios
				Farmacia* f = (*itFunc)->getFarmacia();
				if (nomeF == f->getNome()) //Se a Farmacia a eliminar � igual � Farmacia onde trabalha o Funcionario, esta � apagada
					(*itFunc)->setFarmacia(NULL);
			}
			return *it;
		}
	}
	throw FarmaciaInexistente(nomeF); //Lan�amento de uma exce��o caso a Farmacia n�o exista
}

/**
 * M�todo que permite ordenar as farm�cias
 * @param tipo Enumera��o do tipo tipoSort que permite ao utilizador escolher o modo de ordena��o do vetor
 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordena��o por ordem crescente ou decrescente
 */
void CadeiaFarmacias::sortFarmacias(enum tipoSort tipo, bool crescente){
	//sort(farmacias.begin(), farmacias.end(), funcSort<Farmacia>);
	quickSort(farmacias, 0, farmacias.size()-1, tipo, crescente);
}

/**
 * M�todo que permite adicionar um apontador para Cliente ao respetivo vetor
 * @param cliente Apontador para objeto do tipo Cliente que ser� adicionado ao vetor clientes
 */
void CadeiaFarmacias::addCliente(Cliente* cliente) {
	clientes.push_back(cliente);
}

/**
 * M�todo que permite eliminar o Cliente nomeC do respetivo vetor
 * @param nomeC Nome do cliente que ser� removido do vetor
 * @return Retorna um apontador para o objeto removido ou, se este n�o existir, lan�a uma exce��o do tipo ClienteInexistente
 */
Cliente* CadeiaFarmacias::removeCliente(const std::string &nomeC){
	vector<Cliente*>::iterator it = clientes.begin();
	for(; it != clientes.end(); it++){ //Percorrer o vetor clientes
		if ((*it)->getNome() == nomeC){
			clientes.erase(it);
			return *it;
		}
	}
	throw ClienteInexistente(nomeC); //Lan�amento de uma exce��o caso o cliente n�o exista
}

/**
 * M�todo que permite ordenar os clientes
 * @param tipo Enumera��o do tipo tipoSort que permite ao utilizador escolher o modo de ordena��o do vetor
 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordena��o por ordem crescente ou decrescente
 */
void CadeiaFarmacias::sortClientes(enum tipoSort tipo, bool crescente){
	//sort(clientes.begin(), clientes.end(), funcSort<Cliente>);
	quickSort(clientes, 0, clientes.size()-1, tipo, crescente);
}

/**
 * M�todo que permite adicionar um apontador para Funcionario ao respetivo vetor
 * @param funcionario Apontador para objeto do tipo Funcionario que ser� adicionado ao vetor funcionarios
 */
void CadeiaFarmacias::addFuncionario(Funcionario* funcionario) {
	funcionarios.push_back(funcionario);
}

/**
 * M�todo que permite eliminar o Funcionario nomeF do respetivo vetor
 * @param nomeF Nome do funcionario que ser� removido do vetor
 * @return Retorna um apontador para o objeto removido ou, se este n�o existir, lan�a uma exce��o do tipo FuncionarioInexistente
 */
Funcionario* CadeiaFarmacias::removeFuncionario(const std::string &nomeF){
	vector<Funcionario*>::iterator it = funcionarios.begin();
	for(; it != funcionarios.end(); it++){//Percorrer o vetor de funcionarios
		if ((*it)->getNome() == nomeF){
			funcionarios.erase(it);
			return *it;
		}
	}
	throw FuncionarioInexistente(nomeF); //Lan�amento de uma exce��o caso o funcionario n�o exista
}

/**
 * M�todo que permite ordenar os funcion�rios
 * @param tipo Enumera��o do tipo tipoSort que permite ao utilizador escolher o modo de ordena��o do vetor
 * @param crescente Booleano que permite ao utilizador escolher se quer realizar a ordena��o por ordem crescente ou decrescente
 */
void CadeiaFarmacias::sortFuncionarios(enum tipoSort tipo, bool crescente){
	//sort(funcionarios.begin(), funcionarios.end(), funcSort<Funcionario>);
	quickSort(funcionarios, 0, funcionarios.size()-1, tipo, crescente);
}



