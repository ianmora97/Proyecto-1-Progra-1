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
	void insertarVuelo(Vuelos*);
	void visualizar();
	void modificar();
	void eliminar();
	void imprimeMenu();
	void interfaz();
	int getOpc();
	void flotaVisualizar();
	//un Vuelos devuelve() para encadenamiento
	~VuelosGestion();
};
#endif // !VUELOSGESTION_H