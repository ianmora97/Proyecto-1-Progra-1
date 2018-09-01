#ifndef COMPRATIQUETES_H
#define COMPRATIQUETES_H
#include "VuelosGestion.h"
using namespace std;
class CompraTiquetes{
private:
	int contTiquetesComprados;
	int opc;
public:
	CompraTiquetes();
	void col(int);
	void imprimeMenu();
	void interfaz();
	int getOpc();
	void contadorTiquetes();
	int getCant();
	void mostrarTiquetes(int);
	~CompraTiquetes();
};
#endif // !COMPRATIQUETES_H