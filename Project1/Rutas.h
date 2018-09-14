#ifndef RUTAS_H
#define RUTAS_H
#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>
#include <time.h>
using namespace std;
class Rutas{
private:
	string origen;
	string destino;
	int duracion;
	int cantEscalas;
public:
	Rutas();
	Rutas(string,string,int,int);
	Rutas(const Rutas *r);
	void col(int);
	void setOrigen(string);
	void setDestino(string);
	void setDuracion(int);
	void setCantEscalas(int);
	string sumaRuta();
	string getOrigen();
	string getDestino();
	int getDuracion();
	int getCantEscalas();
	string toString();
	~Rutas();
};
#endif // !RUTAS_H