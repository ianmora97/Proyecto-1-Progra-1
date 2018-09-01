#include "Rutas.h"
Rutas::Rutas(){
	nameOrigen = " ";
	nameDestino = " ";
	duracion = 0;
	cantEscalas = 0;
}
void Rutas::col(int c){ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }
void Rutas::setOrigen(string o) { nameOrigen = o; }
void Rutas::setDestino(string d) { nameDestino = d; }
void Rutas::setDuracion(int d) { duracion = d; }
void Rutas::setCantEscalas(int e) { cantEscalas = e; }
string Rutas::sumaRuta(){
	string cadena = nameOrigen + "-" + nameDestino;
	for (int i = 0; cadena[i]; i++)
		cadena[i] = toupper(cadena[i]);
	return cadena;
}
string Rutas::getOrigen() { return nameOrigen; }
string Rutas::getDestino() { return nameDestino; }
int Rutas::getDuracion() { return duracion; }
int Rutas::getCantEscalas() { return cantEscalas; }
string Rutas::toString() {
	stringstream p1;
	p1 << "\nNombre de origen: \n";
	p1 << nameOrigen << "\n";
	p1 << "Nombre de destino:\n";
	p1 << nameDestino << "\n";
	p1 <<"Duracion del viaje:\n"
		<<duracion<<" horas\n"
		<<"Cantidad de escalas:\n"
		<<cantEscalas<<" escalas\n";
	return p1.str();
}
Rutas::~Rutas(){}
