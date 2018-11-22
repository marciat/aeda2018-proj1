#include "CadeiaFarmacias.h"
#include "Data.h"
#include "Farmacia.h"
#include "Pessoa.h"
#include "Produto.h"
#include "Receita.h"
#include "util.h"
#include "Venda.h"

#include <iostream>

void menu(){
	std::cout << "		FARM�CIA DO PEDRITO" << std::endl << std::endl;

	std::cout << "O que pretende fazer?" << std::endl;
	std::cout << "1. Gerir cadeia de farm�cias" << std::endl;
	std::cout << "2. Gerir uma farm�cia." << std::endl;
	std::cout << "3. Gerir clientes."
	std::cout << "3. Inserir receita." << std::endl;
	std::cout << "5. Gerir vendas."
}

void menuCadeia(){
	std::cout << "CADEIA DE FARM�CIAS" << std::endl;
	std::cout << "1. Criar cadeia de farm�cias." << std::endl;
	std::cout << "2. Alterar o nome da cadeia de farm�cias." << std::endl << std::endl;

	std::cout << "3. Adicionar farm�cia." << std::endl;
	std::cout << "4. Remover farm�cia." << std::endl;
	std::cout << "5. Ordenar farm�cia." << std::endl << std::endl;

	std::cout << "6. Adicionar novo cliente." << std::endl;
	std::cout << "7. Remover cliente." << std::endl;
	std::cout << "8. Ordenar clientes." << std::endl << std::endl;

	std::cout << "9. Adicionar funcion�rio." << std::endl;
	std::cout << "10. Remover funcion�rio." << std::endl;
	std::cout << "11. Ordenar funcion�rios." << std::endl << std::endl;

}

void menuFarmacia(){
	std::cout << "FARM�CIA" << std::endl;
	std::cout << "1. Definir/modificar Gerente." << std::endl;
	std::cout << "2. Definir/modificar Diretor T�cnico." << std::endl << std::endl;

	std::cout << "3. Adicionar 1 produto para venda." << std::endl;
	std::cout << "4. Adicionar v�rios produtos para venda." << std::endl;
	std::cout << "5. Alterar quantidade dispon�vel de um produto" << std::endl;
	std::cout << "6. Remover produto."<< std::endl << std::endl;

	std::cout << "7. Adicionar venda." << std::endl;
	std::cout << "8. Ordenar vendas." << std::endl;
	std::cout << "9. Ordenar clientes." << std::endl << std::endl;

	std::cout << "10. Imprimir fatura" << std::endl;


}

int main(){
	menuCadeia();
	return 0;
}
