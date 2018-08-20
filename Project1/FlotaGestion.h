#ifndef FLOTAGESTION_H
#define FLOTAGESTION_H
#include <iostream>
#include "Avion.h"
using namespace std;
const string clave = "admin";
class FlotaGestion{
private:
	Avion *plane;
	int cant=0, tam;
public:
	FlotaGestion();
	bool revisarAdmin();
	void col(int);
	void ingresarAvion(Avion&);
	void visualizarAviones();
	void modificar();
	void eliminar();
	int menu();
	void imprimeMenu();
	~FlotaGestion();
};
#endif // !FLOTAGESTION_H