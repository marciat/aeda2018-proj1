/**
 * Header File que contem as classes Data e Hora
 *
 * @author Marcia, Pedro e Rita
 * @date Novembro, 2018
 */

#ifndef DATA_H
#define DATA_H

#include <ctime>
#include <iostream>
/**
 * Classe Data
 */
class Data {
private:
	unsigned short dia; //Dia do m�s
	unsigned short mes; //M�s do ano
	int ano; //Ano

public:
	/**
	 * Construtor da Classe Data
	 * Data ser� a mesma do sistema
	 */
	Data();
	/**
	 * Construtor da Classe Data
	 * @param dia Dia da data
	 * @param mes M�s da data
	 * @param ano Ano da data
	 */
	Data(unsigned short dia, unsigned short mes, int ano);
	/**
	 * M�todo que permite obter o dia
	 * @return Dia do m�s
	 */
	unsigned short getDia() const;
	/**
	 * M�todo que permite obter o mes
	 * @return M�s do ano (em n�mero)
	 */
	unsigned short getMes() const;
	/**
	 * M�todo que permite obter o ano
	 * @return Ano
	 */
	int getAno() const;
	/**
	 * Operador menor que verifica se uma data � menor que outra
	 * @param data Data a ser comparada
	 * @return Retorna true se for menor que a data do par�metro. Caso contr�rio, retorna false
	 */
	bool operator< (const Data &data) const;
	/**
	 * M�todo que verifica se duas datas s�o iguais
	 * @param data Data a ser comparada
	 * @return Retorna true se as datas forem iguais. Caso contr�rio, retorna false
	 */
	bool operator==(const Data &data) const;
	/**
	 * Overload de operador << para exportar a data
	 * @param output Variavel para onde se quer exportar(ecra, ficheiro, ...)
	 * @param d1 Data que se quer exportar
	 * @return Retorna referencia para a variavel para onde se quer exportar
	 */
	friend std::ostream& operator<<(std::ostream &output, const Data &d1);

};

/**
 * Classe Hora
 */
class Hora {
private:
	unsigned short hora; //Hora do dia
	unsigned short minutos; //Minutos
	unsigned short segundos; //Segundos

public:
	/**
	 * Construtor da Classe Hora
	 * Hora ser� a mesma do sistema
	 */
	Hora();
	/**
	 * Construtor da Classe Hora
	 * @param h Horas da hora
	 * @param m Minutos da hora
	 * @param s Segundos da hora
	 */
	Hora(unsigned short h, unsigned short m, unsigned short s);
	/**
	 * M�todo que permite obter as horas (n�mero da hora)
	 * @return Hora do dia
	 */
	unsigned short getHora() const;
	/**
	 * M�todo que permite obter os minutos
	 * @return Minutos
	 */
	unsigned short getMinutos() const;
	/**
	 * M�todo que permite obter os segundos
	 * @return Segundos
	 */
	unsigned short getSegundos() const;
	/**
	 * Operador menor que verifica se uma hora � menor que outra
	 * @param h Hora a ser comparada
	 * @return Retorna true se for menor que a hora do par�metro. Caso contr�rio, retorna false
	 */
	bool operator< (const Hora &h) const;
	/**
	 * M�todo que verifica se duas datas s�o iguais
	 * @param h Hora a ser comparada
	 * @return Retorna true se as horas forem iguais. Caso contr�rio, retorna false
	 */
	bool operator ==(const Hora &h) const;
	/**
	 * Overload de operador << para exportar a data
	 * @param output Variavel para onde se quer exportar(ecra, ficheiro, ...)
	 * @param d1 Data que se quer exportar
	 * @return Retorna referencia para a variavel para onde se quer exportar
	 */
	friend std::ostream& operator<<(std::ostream &output, const Hora &h1);
};

#endif
