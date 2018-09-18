#include "Rutas.h"
Rutas::Rutas(string o, string d, int du, int e) : origen(o), destino(d), duracion(du), cantEscalas(e) {}
Rutas::Rutas(const Rutas *r) : origen(r->origen), destino(r->destino), duracion(r->duracion), cantEscalas(r->cantEscalas) {}
Rutas::Rutas(){}
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
	p1 << "Nombre de origen        : " << origen << "\n";
	p1 << "Nombre de destino       : " << destino << "\n";
	p1 << "Duracion del viaje      : " << duracion << " horas\n";
	p1 << "Cantidad de escalas     : " << cantEscalas << " escalas\n";
	return p1.str();
}
Rutas::~Rutas(){
	origen = " ";
	destino = " ";
	duracion = 0;
	cantEscalas = 0;
}
