#ifndef VUELOSGESTION_H
#define VUELOSGESTION_H
#include "Vuelos.h"
using namespace std;
class VuelosGestion {
private:
	Vuelos **vuelo;
	int cant, tam;
public:
	VuelosGestion();
	void col(int);
	void gotoxy(int x, int y);
	void insertar(Vuelos*);
	void insertar(Avion*,Rutas*,int,int,string,int);
	void visualizar();
	void modificar();
	void eliminar();
	int menu();
	int getCant();
	Vuelos devuelveVuelo(int);
	void toString();
	int revisaValor(char l, int t);
	~VuelosGestion();
};
#endif // !VUELOSGESTION_H