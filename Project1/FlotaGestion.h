#ifndef FLOTAGESTION_H
#define FLOTAGESTION_H
#include "Avion.h"
using namespace std;
const string clave = "admin";
class FlotaGestion {
private:
	Avion **plane;
	int cant = 0, tam;
	int opc;
public:
	FlotaGestion();
	void revisarAdmin();
	void col(int);
	int getOpc();
	void ingresarAvion(Avion*);
	void visualizarAviones();
	void modificar();
	void eliminar();
	void menu();
	void imprimeMenu();
	Avion devuelve(int);
	~FlotaGestion();
};
#endif // !FLOTAGESTION_H