#ifndef RUTASGESTION_H
#define RUTASGESTION_H
#include "Rutas.h"
using namespace std;
class RutasGestion{
private:
	Rutas **ruta;
	int cant, tam;
public:
	RutasGestion();
	void gotoxy(int x, int y);
	void col(int);
	int getCant();
	void ingresar(Rutas*);
	void ingresar();
	void visualizar();
	void modificar();
	void eliminar();
	int menu();
	void mostrarRutas();
	Rutas devuele(int);
	~RutasGestion();
};
#endif // !RUTASGESTION_H