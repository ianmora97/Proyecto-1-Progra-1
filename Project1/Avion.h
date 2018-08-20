#ifndef AVION_H
#define AVION_H
#include <iostream>
#include "Asientos.h"
using namespace std;
class Avion{
private:
	Asientos *asientos;
	int annio,id;
	string modelo,marca;
	int cantPasajeros;
	int filas, columnas;
public:
	Avion();
	Avion(int,int,string,string);
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

	~Avion();
};
#endif // !AVION_H