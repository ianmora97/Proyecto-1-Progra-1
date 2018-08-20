#ifndef RUTASGESTION_H
#define RUTASGESTION_H
#include "Rutas.h"
using namespace std;
class RutasGestion{
private:
	Rutas *ruta;
	int cant, tam;
public:
	RutasGestion();
	void col(int);
	void ingresarRuta(Rutas&);
	void visualizar();
	void modificar();
	void eliminar();
	void imprimirMenu();
	int interfaz();
	~RutasGestion();
};
#endif // !RUTASGESTION_H