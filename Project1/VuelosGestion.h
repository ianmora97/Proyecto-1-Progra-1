#ifndef VUELOSGESTION_H
#define VUELOSGESTION_H
#include <string>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <time.h>
#include "Vuelos.h"
using namespace std;
class VuelosGestion {
private:
	Vuelos **vuelo;
	int cant, tam;
	int opc;
public:
	VuelosGestion();
	void col(int);
	void gotoxy(int x, int y);
	void insertarVuelo(Vuelos*);
	void visualizar();
	void modificar();
	void eliminar();
	void imprimeMenu();
	void interfaz();
	int getOpc();
	int getCant();
	Vuelos devuelveVuelo(int);
	void toString();
	int revisaValor(char l, int t);
	~VuelosGestion();
};
#endif // !VUELOSGESTION_H