#ifndef AVION_H
#define AVION_H
#include <iostream>
#include "Persona.h"
using namespace std;
class Avion{
private:
	Persona *asiento;
	int can;
	int ma[6][30];
	int annio,id;
	string modelo,marca;
	int cantPasajeros;
	int filas, columnas;
public:
	Avion();
	Avion(int,int,string,string);
	void col(int);
	void setAnnio(int);
	void setId(int);
	void setModelo(string);
	void setMarca(string);
	void setCantPasajetos(int);
	void setFilasColumnas(int,int);
	int getAnnio();
	int getId();
	int getCantPasajeros();
	int getFilas();
	int getColumnas();
	string getModelo();
	string getMarca();
	int letraXNumero(char);
	void insertaPersona(Persona&, char, int);
	void imprimeAsientos();
	~Avion();
};
#endif // !AVION_H