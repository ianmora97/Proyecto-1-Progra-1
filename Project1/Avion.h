#ifndef AVION_H
#define AVION_H
#include "Asientos.h"
using namespace std;
class Avion{
private:
	Asientos *asiento;
	int can;
	int annio,id;
	string modelo,marca;
	int cantPasajeros;
	int filas, columnas;
public:
	Avion(char);
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
	string toString();
	void insertaAsientos(Asientos&);
	~Avion();
};
#endif // !AVION_H