#ifndef DATA_H
#define DATA_H

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
	 * M�todo que permite obter a hora do dia
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
};

#endif
