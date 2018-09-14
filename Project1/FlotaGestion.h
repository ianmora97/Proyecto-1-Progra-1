#ifndef FLOTAGESTION_H
#define FLOTAGESTION_H
#include "Avion.h"
using namespace std;
const string clave = "admin";
class FlotaGestion {
private:
	Avion **plane;
	int cant = 0, tam;
public:
	FlotaGestion();
	void gotoxy(int x, int y);
	void revisarAdmin();
	void col(int);
	int getCant();
	void ingresar();
	void ingresar(Avion *a);
	void visualizar();
	void modificar();
	void eliminar();
	void toString();
	int menu();
	Avion devuelve(int);
	~FlotaGestion();
};
#endif // !FLOTAGESTION_H