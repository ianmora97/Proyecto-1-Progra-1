#ifndef AVION_H
#define AVION_H
#include "Persona.h"
using namespace std;
class Avion{
private:
	int cantidad=0;
	Persona ***persona;
	int annio,id;
	string modelo,marca;
	int cantPasajeros;
	int filas, columnas;
public:
	Avion();
	Avion(int,int,string,string,int,int,int);
	Avion(const Avion *a);
	void col(int);
	void setAnnio(int);
	void setId(int);
	void setModelo(string);
	void setMarca(string);
	void setCantPasajetos(int);
	void setFilasColumnas(int,int);
	int getCan();
	int getAnnio();
	int getId();
	int getCantPasajeros();
	int getFilas();
	int getColumnas();
	string getModelo();
	string getMarca();
	string toString();
	string toString2();
	int letraXNumero(char);
	int revisaValor(char,int);
	void imprimeAsientos();
	bool verifica(char f, int c);
	int suma();
	bool insertarPersona(Persona*,char ,int);
	void eliminarPersonas();
	Persona devuelvePersona(int,int);
	string toStringPasajeros();
	~Avion();
};
#endif // !AVION_H