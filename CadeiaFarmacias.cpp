#include "CadeiaFarmacias.h"

using namespace std;

CadeiaFarmacias::CadeiaFarmacias() {
	this->nome = ""; //Inicializa��o de um nome vazio
	farmacias.resize(0); //Vetor de farm�cias vazio
	clientes.resize(0); //Vetor de clientes vazio
	funcionarios.resize(0); //Vetor de funcion�rios vazio
}


CadeiaFarmacias::CadeiaFarmacias(std::string nome) {
	this->nome=nome; //Inicializa��o de uma cadeia com nome
	farmacias.resize(0); //Vetor de farm�cias vazio
	clientes.resize(0); //Vetor de clientes vazio
	funcionarios.resize(0); //Vetor de funcion�rios vazio
}

void CadeiaFarmacias::setNome(string nome){
	this->nome = nome;
}

unsigned int CadeiaFarmacias::getNumFarmacias() const {
	return farmacias.size();
}

unsigned int CadeiaFarmacias::getNumClientes() const {
	return clientes.size();
}

unsigned int CadeiaFarmacias::getNumFuncionarios() const {
	return funcionarios.size();
}

vector<Farmacia *> CadeiaFarmacias::getFarmacias() const {
	return farmacias;
}

vector <Cliente*>  CadeiaFarmacias::getClientes() const {
	return clientes;
}

vector <Funcionario*> CadeiaFarmacias::getFuncionarios() const {
	return funcionarios;
}

void CadeiaFarmacias::addFarmacia(Farmacia* farmacia) {
	farmacias.push_back(farmacia);
}

Farmacia* CadeiaFarmacias::removeFarmacia(const string &nomeF){
	vector<Farmacia*>::iterator it = farmacias.begin();
	for (; it != farmacias.end(); it++){ //Percorrer o vetor farmacias
		if ((*it)->getNome() == nomeF){
			farmacias.erase(it); //Eliminar o elemento pretendido
			vector<Funcionario*>::iterator itFunc = funcionarios.begin();
			for(; itFunc != funcionarios.end(); itFunc++){ //Percorrer o vetor funcionarios
				Farmacia* f = (*itFunc)->getFarmacia();
				if (nomeF == f->getNome()) //Se a Farmacia a eliminar � igual � Farmacia onde trabalha o Funcionario, este � apagada
					(*itFunc)->setFarmacia(NULL);
			}
			return *it;
		}
	}
	throw FarmaciaInexistente(nomeF); //Lan�amento de uma exce��o caso a Farmacia n�o exista
}

void CadeiaFarmacias::sortFarmacias(enum tipoSort tipo, bool crescente){
	//sort(farmacias.begin(), farmacias.end(), funcSort<Farmacia>);
	quickSort(farmacias, 0, farmacias.size()-1, tipo, crescente);
}

void CadeiaFarmacias::addCliente(Cliente* cliente) {
	clientes.push_back(cliente); //Adicionar um apontador para cliente ao vetor
}

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

void CadeiaFarmacias::sortClientes(enum tipoSort tipo, bool crescente){
	//sort(clientes.begin(), clientes.end(), funcSort<Cliente>);
	quickSort(clientes, 0, clientes.size()-1, tipo, crescente);
}

void CadeiaFarmacias::addFuncionario(Funcionario* funcionario) {
	funcionarios.push_back(funcionario);
}

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

void CadeiaFarmacias::sortFuncionarios(enum tipoSort tipo, bool crescente){
	//sort(funcionarios.begin(), funcionarios.end(), funcSort<Funcionario>);
	quickSort(funcionarios, 0, funcionarios.size()-1, tipo, crescente);
}

std::ostream& operator<<(std::ostream &output, const CadeiaFarmacias &cF){
	output << cF.farmacias.size() << endl;
	for(size_t i = 0; i < cF.farmacias.size(); i++){
		//output << cF.farmacias[i] << endl;
	}
	output << cF.clientes.size() << endl;
	for(size_t i = 0; i < cF.clientes.size(); i++){
		//output << cF.clientes[i] << endl;
	}
	output << cF.funcionarios.size() << endl;
	for(size_t i = 0; i < cF.funcionarios.size(); i++){
		//output << cF.funcionarios[i] << endl;
	}
	return output;
}


