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
	int getCant();
	void ingresarRuta(Rutas&);
	void visualizar();
	void modificar();
	void eliminar();
	void imprimirMenu();
	int interfaz();
	void mostrarRutas();
	Rutas devuele(int);
	~RutasGestion();
};
#endif // !RUTASGESTION_H