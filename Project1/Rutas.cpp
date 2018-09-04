#include "Rutas.h"
Rutas::Rutas(string o, string d, int du, int e) : origen(o), destino(d), duracion(du), cantEscalas(e) {}
void Rutas::col(int c){ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }
void Rutas::setOrigen(string o) { origen = o; }
void Rutas::setDestino(string d) { destino = d; }
void Rutas::setDuracion(int d) { duracion = d; }
void Rutas::setCantEscalas(int e) { cantEscalas = e; }
string Rutas::sumaRuta(){
	string cadena = origen + "-" + destino;
	for (int i = 0; cadena[i]; i++)
		cadena[i] = toupper(cadena[i]);
	return cadena;
}
string Rutas::getOrigen() { return origen; }
string Rutas::getDestino() { return destino; }
int Rutas::getDuracion() { return duracion; }
int Rutas::getCantEscalas() { return cantEscalas; }
string Rutas::toString() {
	stringstream p1;
	p1 << "\nNombre de origen: \n";
	p1 << origen << "\n";
	p1 << "Nombre de destino:\n";
	p1 << destino << "\n";
	p1 <<"Duracion del viaje:\n"
		<<duracion<<" horas\n"
		<<"Cantidad de escalas:\n"
		<<cantEscalas<<" escalas\n";
	return p1.str();
}
Rutas::~Rutas(){
	origen = " ";
	destino = " ";
	duracion = 0;
	cantEscalas = 0;
}
