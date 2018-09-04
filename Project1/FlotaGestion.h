#ifndef FLOTAGESTION_H
#define FLOTAGESTION_H
#include "Avion.h"
#include <conio.h>
#include <stdio.h>
using namespace std;
const string clave = "admin";
class FlotaGestion {
private:
	Avion **plane;
	int cant = 0, tam;
	int opc;
public:
	FlotaGestion();
	void gotoxy(int x, int y);
	void revisarAdmin();
	void col(int);
	int getOpc();
	int getCant();
	void ingresarAvion(Avion*);
	void visualizarAviones();
	void toString();
	void modificar();
	void eliminar();
	void menu();
	void imprimeMenu();
	Avion devuelve(int);
	~FlotaGestion();
};
#endif // !FLOTAGESTION_H