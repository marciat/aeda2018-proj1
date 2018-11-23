#include "CadeiaFarmacias.h"
#include "Data.h"
#include "Farmacia.h"
#include "Pessoa.h"
#include "Produto.h"
#include "Receita.h"
#include "util.h"
#include "Venda.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static CadeiaFarmacias cadeiaF;

void menu();

//TODO //- PASSAR PARA CADEIAFARMACIAS.H OU FARMACIAS.H
Farmacia* findFarmacia(string nomeFarmacia, vector<Farmacia*> farmacias ){
	vector<Farmacia*>::iterator it;

	for(it=farmacias.begin() ; it != farmacias.end();it++){
		if((*it)->getNome() == nomeFarmacia)
			return *it;
	}
	throw FarmaciaInexistente(nomeFarmacia);
}

//TODO switch case 5
void menuFuncionarios(){
	int opcao;

	cout << "FUNCIONARIOS" << endl;

	cout << "1. Definir/modificar Gerente." << endl;
	cout << "2. Definir/modificar Diretor T�cnico." << endl;
	cout << "3. Adicionar funcion�rio." << endl;
	cout << "4. Remover funcion�rio." << endl;
	cout << "5. Mudar dados de um funcion�rio." << endl;
	cout << "6. Ordenar funcion�rios." << endl;
	cout << "7. Mostrar dados de um funcion�rio." << endl << endl;

	cout << "0. Voltar atr�s." << endl;

	cout << "Op��o: "; cin >> opcao; cout << endl;

	switch(opcao){
	case 1:
	{
		vector<Farmacia *> farmacias = cadeiaF.getFarmacias();
		string nomeFarmacia, nomeGerente, moradaGerente;
		double contribuinte, salario;
		Farmacia* it;
		bool valido = false;

		while(!valido){
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Farm�cia: "; cin >> nomeFarmacia;

			try{
				it = findFarmacia(nomeFarmacia, farmacias);
				valido = true;
			}catch (FarmaciaInexistente& nomeFarmacia){
				cerr << "Farm�cia inexistente!" << endl;
				valido = false;
			}
		}

		cout << "Nome do Gerente: " ; cin >> nomeGerente;
		cout << "Morada do Gerente: "; cin >> moradaGerente;
		cout << "N� de contribuinte: "; cin >> contribuinte;
		cout << "Salario: "; cin >> salario;

		Funcionario gerente(nomeGerente, moradaGerente, contribuinte, salario);

		it->setGerente(&gerente);
		cadeiaF.addFuncionario(&gerente);
		break;
	}

	case 2:
	{
		vector<Farmacia *> farmacias = cadeiaF.getFarmacias();
		string nomeFarmacia, nomeDir, moradaDir;
		double contribuinte, salario;
		Farmacia* it;
		bool valido = false;

		while(!valido){
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Farm�cia: "; cin >> nomeFarmacia;
			valido = true;

			try{
				it = findFarmacia(nomeFarmacia, farmacias);
			} catch (FarmaciaInexistente& nomeFarmacia){
				cerr << "Farm�cia inexistente!" << endl;
				valido = false;
			}
		}

		cout << "Nome do Diretor: " ; cin >> nomeDir;
		cout << "Morada do Diretor: "; cin >> moradaDir;
		cout << "N� de contribuinte: "; cin >> contribuinte;
		cout << "Salario: "; cin >> salario;

		Funcionario diretor(nomeDir, moradaDir, contribuinte, salario);

		it->setDiretorTecnico(&diretor);
		cadeiaF.addFuncionario(&diretor);
		break;
	}

	case 3:
	{
		string nomeFarmacia, nome, morada;
		double contribuinte, salario;


		cout << "Nome do Funcionario: " ; cin >> nome;
		cout << "Morada do Gerente: "; cin >> morada;
		cout << "N� de contribuinte: "; cin >> contribuinte;
		cout << "Salario: "; cin >> salario;

		Funcionario funcionario(nome, morada, contribuinte, salario);

		cadeiaF.addFuncionario(&funcionario);
		break;
	}

	case 4:
	{
		string nomeFunc;
		vector<Funcionario*> funcionarios = cadeiaF.getFuncionarios();
		vector<Funcionario*>::iterator it;
		bool valido = false;

		while(!valido){
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Nome do funcion�rio a remover: " ;
			cin >> nomeFunc;
			bool encontrou = false;

			try{
				for(it=funcionarios.begin() ; it != funcionarios.end();it++){
					if((*it)->getNome() == nomeFunc){
						encontrou = true;
						break;
					}
				}
				if (!encontrou) throw FuncionarioInexistente(nomeFunc);
				valido = true;
			} catch (FuncionarioInexistente& nomeFunc){
				cerr << "Funcion�rio inexistente!" << endl;
				valido = false;
			}
		}

		cadeiaF.removeFuncionario(nomeFunc);
		break;
	}

	/*case 5:
	{
		string nomeFunc, dado;
		vector<Funcionario*> funcionarios = cadeiaF.getFuncionarios();
		vector<Funcionario*>::iterator it;
		bool valido = false;

		while(!valido){
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Nome do funcion�rio: " ;
			cin >> nomeFunc;
			bool encontrou = false;

			try{
				for(it=funcionarios.begin() ; it != funcionarios.end();it++){
					if((*it)->getNome() == nomeFunc){
						encontrou = true;
						break;
					}
				}
				if (!encontrou) throw FuncionarioInexistente(nomeFunc);
				valido = true;
			} catch (FuncionarioInexistente& nomeFunc){
				cerr << "Funcion�rio inexistente!" << endl;
				valido = false;
			}
		}

	//Funcionario f;



		cout << "(Morada / "
		cin >> dado;

		if(dado == "Morada")

	}*/


	case 6:
	{
		string fator;
		string ordem;
		bool valido = false;
		tipoSort sort;

		cout << "Ordenar com base em que fator?" << endl;
		cout << "(Nome / Contribuinte / Salario / Default)" << endl;
		cout << "Fator: "; cin >> fator;

		while(!valido){
			if (fator == "Nome"){
				sort = NOME;
				valido=true;
			}
			else if (fator == "Contribuinte"){
				sort = CONTRIBUINTE;
				valido= true;
			}
			else if (fator == "Salario"){
				sort = SALARIO;
				valido = true;
			}
			else if (fator == "Default"){
				sort=DEFAULT;
				valido = true;
			}
			else{
				cin.clear();
				cin.ignore(100000, '\n');
				cerr << "Insira Nome, Contribuinte, Salario ou Default: ";
				cin >> fator;
			}
		}

		cout << "Ordenar por que ordem?(Crescente / Decrescente) " << endl;
		cout << "Ordem: "; cin >> ordem;

		valido = false;

		while(!valido){
			if(ordem =="Crescente"){
				cadeiaF.sortFuncionarios(sort,1);
				valido = true;
			}
			else if(ordem == "Decrescente"){
				cadeiaF.sortFuncionarios(sort,0);
				valido = true;
			}
			else{
				cin.clear();
				cin.ignore(100000, '\n');
				cerr << "Insira Crescente ou Decrescente: ";
				cin >> ordem;
			}
		}
		break;
	}

	case 7:
	{
		string nomeFunc;
		vector<Funcionario*> funcionarios = cadeiaF.getFuncionarios();
		vector<Funcionario*>::iterator it;
		bool valido = false;

		while(!valido){
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Nome do funcion�rio: " ;
			cin >> nomeFunc;
			bool encontrou = false;

			try{
				for(it=funcionarios.begin() ; it != funcionarios.end();it++){
					if((*it)->getNome() == nomeFunc){
						encontrou = true;
						break;
					}
				}
				if (!encontrou) throw FuncionarioInexistente(nomeFunc);
				valido = true;
			} catch (FuncionarioInexistente& nomeFunc){
				cerr << "Funcion�rio inexistente!" << endl;
				valido = false;
			}
		}

		(*it)->showInfo();
		break;
	}

	case 0:
		menu();
		break;

	default:
		cerr <<"Opcao inexistente!" << endl;
		break;
	}
}

//TODO switch case 3/5
void menuFarmacia(){

	int opcao;

	cout << "FARM�CIA" << endl;

	cout << "O que pretende fazer?" << endl;
	cout << "1. Adicionar farm�cia." << endl;
	cout << "2. Remover farm�cia." << endl;
	cout << "3. Ordenar farm�cias." << endl << endl;
	cout << "";
	cout << "4. Mostrar farm�cias existentes." << endl;
	cout << "5. Mostrar dados de uma farm�cia." << endl << endl;

	cout << "0. Voltar atr�s." << endl;


	cout << "Op��o: "; cin >> opcao; cout << endl;

	switch (opcao){
	case 1:
	{
		string nomeFarmacia;
		string moradaFarmacia;
		cout << "Que nome pretende dar � farm�cia? ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, nomeFarmacia);
		cout << "Qual � a morada da farm�cia? ";
		//cin.clear();
		//cin.ignore(10000, '\n');
		getline(cin, moradaFarmacia);
		cout << moradaFarmacia << endl;
		Farmacia* farmacia = new Farmacia(nomeFarmacia, moradaFarmacia);
		cadeiaF.addFarmacia(farmacia);
		break;
	}
	case 2:
	{
		string nomeFarmacia;
		cout << "Qual o nome da farm�cia que pretende remover? ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, nomeFarmacia);
		cout << endl;

		if(cadeiaF.getFarmacias().empty())
			cerr << "A cadeia de farm�cias n�o tem nenhuma farm�cia!" <<endl;

		else{
			try {
				cadeiaF.removeFarmacia(nomeFarmacia);
			} catch(FarmaciaInexistente& (nomeFarmacia)){
				cerr << "Farm�cia inexistente! \n" <<endl;

			}
		}
		break;
	}
	case 3: //TODO N�O FUNCIONA
	{
		string fator;
		string ordem;
		bool valido = false;
		tipoSort sort;

		cout << "Ordenar com base em que fator?" << endl;
		cout << "(Nome / NumProdutos / NumCompras / Default)" << endl;
		cout << "Fator: "; cin >> fator;

		while(!valido){
			if (fator == "Nome"){
				sort = NOME;
				valido=true;
			}
			else if (fator == "NumProdutos"){
				sort = NUM_PROD;
				valido= true;
			}
			else if (fator == "NumCompras"){
				sort = NUM_VENDA;
				valido = true;
			}
			else if (fator == "Default"){
				sort=DEFAULT;
				valido = true;
			}
			else{
				cin.clear();
				cin.ignore(100000, '\n');
				cerr << "Insira Nome, NumProdutos, NumCompras ou Default: ";
				cin >> fator;
			}
		}

		cout << "Ordenar por que ordem?(Crescente / Decrescente) " << endl;
		cout << "Ordem: "; cin >> ordem;

		valido = false;

		while(!valido){
			if(ordem=="Crescente"){
				cout << "1" << endl;
				//cadeiaF.sortFarmacias(sort,true);
				cout << "2" << endl;
				valido = true;
			}
			else if(ordem == "Decrescente"){
				cadeiaF.sortFarmacias(sort,false);
				valido = true;
			}
			else{
				cin.clear();
				cin.ignore(100000, '\n');
				cerr << "Insira Crescente ou Decrescente: ";
				cin >> ordem;
			}
		}
		cout << "3" << endl;
		break;
	}

	case 4:
	{
		vector<Farmacia*> farmacias=cadeiaF.getFarmacias();
		vector<Farmacia*>::const_iterator it=farmacias.begin();

		if (farmacias.size() == 0)
			cout << "N�o existem farm�cias." << endl;
		else {
			cout << "As farm�cias existentes s�o: ";

			for(; it != farmacias.end();it++){
				Farmacia* farmacia= *it;
				if (it == farmacias.end()-1)
					cout <<  farmacia->getNome() <<".";
				else cout << farmacia->getNome() << ", ";

			}
		}
		break;
	}

	case 5:
	{
		vector<Farmacia*> farmacias=cadeiaF.getFarmacias();
		Farmacia* it;
		string nomeFarmacia;
		bool valido = false;

		while(!valido){
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Farm�cia: "; cin >> nomeFarmacia;

			try{
				cout << nomeFarmacia << endl;
				it = findFarmacia(nomeFarmacia, farmacias);
				valido = true;
			}catch (FarmaciaInexistente& nomeFarmacia){
				cerr << "Farm�cia inexistente!" << endl;
				valido = false;
			}
		}

		cout << *it;
		break;
	}

	case 0:
		menu();
		break;
	default:
		cerr <<"Opcao inexistente!" << endl;
		break;
	}
	cout << string(3, '\n');
	menuFarmacia();
}

void menu(){

	int opcao;
	cout << "CADEIA DE FARM�CIAS (" << cadeiaF.getNome() << ") - AEDA 2018" << endl << endl;

	cout << "O que pretende fazer?" << endl;
	cout << "1. Alterar o nome da cadeia de farm�cias" << endl;
	cout << "2. Gerir uma farm�cia." << endl;
	cout << "3. Gerir funcion�rios." << endl;
	cout << "4. Gerir clientes." << endl;
	cout << "5. Inserir receita." << endl;
	cout << "6. Gerir vendas." << endl;
	cout << "7. Mostrar dados da cadeia de farm�cias" << endl;
	cout << "8. Importar novo ficheiro." <<  endl;
	//cout << 8. "Gravar e sair. << endl;


	cout << "Op��o: "; cin >> opcao; cout << endl;


	switch(opcao){
	case 1:
	{
		string nomeCadeia;
		cout << "Que nome pretende dar � cadeia de farm�cias? ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, nomeCadeia);
		cadeiaF.setNome(nomeCadeia);
		cout << string(3, '\n');
		break;
	}

	case 2:
		cout << string(3, '\n');
		menuFarmacia();
		break;

	case 3:
		cout << string(3, '\n');
		menuFuncionarios();
		break;

		//TODO
		//case 4: menuReceita();
		//case 5: menuVendas();
		//case 6:
		//case 7:
		//case 8:
	default:
		cerr << "Opcao inexistente!" << endl;
		break;

	}
	menu();
}

void menuInicial(){
	int opcao;
	string nomeCadeia;
	fstream ficheiro;

	cout << "CADEIA DE FARM�CIAS - AEDA 2018" << endl << endl;
	cout << "O que pretende fazer?" << endl;
	cout << "1. Importar ficheiro." << endl;
	cout << "2. Criar cadeia de farm�cias." << endl << endl;

	cout << "Op��o: "; cin >> opcao; cout << endl;

	switch(opcao){
	case 1:
	{
		cout << "Qual o nome da cadeia de farm�cias que quer importar? ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, nomeCadeia);
		cadeiaF.setNome(nomeCadeia);
		nomeCadeia += ".txt";
		ficheiro.open(nomeCadeia);
		while (!ficheiro.is_open())
		{
			cerr << "Ficheiro " << nomeCadeia << " n�o encontrado!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, nomeCadeia);
			cadeiaF.setNome(nomeCadeia);
			nomeCadeia += ".txt";
			ficheiro.open(nomeCadeia);
		}
		import(ficheiro,cadeiaF);
		cout << string(3, '\n');
		break;
	}
	case 2:
		cout << "Qual o nome da cadeia de farm�cias? ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, nomeCadeia);
		cadeiaF.setNome(nomeCadeia);
		cout << string(3, '\n');
		break;

	default:
		cout << string(3, '\n');
		cerr << "Opcao inexistente!" << endl;
		cout << string(3, '\n');
		menuInicial();
	}
	menu();
}

int main(){
	menuInicial();
	return 0;
}
