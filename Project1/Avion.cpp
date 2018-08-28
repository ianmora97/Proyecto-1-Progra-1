#include "Avion.h"
Avion::Avion(){}
Avion::Avion(char t) {
	can = 0;
	asiento = new Asientos(t);
	filas = asiento->getFilas();
	columnas = asiento->getColumnas();
	cantPasajeros = asiento->getTam();
	annio = 0;
	id = 0;
	modelo = " ";
	marca = " ";	
}
Avion::Avion(int i, int a, string mo, string ma) : id(i), annio(a), modelo(mo), marca(ma) {}
void Avion::col(int c){	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);}
void Avion::setAnnio(int a){ annio=a; }
void Avion::setId(int i) { id = i; }
void Avion::setModelo(string m) { modelo = m; }
void Avion::setMarca(string m) { marca = m; }
void Avion::setCantPasajetos(int p) { cantPasajeros = p; }
void Avion::setFilasColumnas(int f, int c) { filas = f; columnas = c; }
int Avion::getAnnio() { return annio; }
int Avion::getId() { return id; }
int Avion::getCantPasajeros() { return cantPasajeros; }
int Avion::getFilas() { return filas; }
int Avion::getColumnas() { return columnas; }
string Avion::getModelo() { return modelo; }
string Avion::getMarca() { return marca; }
string Avion::toString() {
	stringstream p;
	col(11);
	p << "------------------------------------\n";
	col(15);
	p << "Id: " << id << endl;
	p << "Annio: "<<annio<<endl;
	p << "Modelo: " << modelo << endl;
	p << "Marca: " << marca << endl;
	p << "Cantidad de Pasajeros: " << cantPasajeros << endl;
	p << "Cantidad de filas: " << filas << " Columnas: " << columnas << endl;
	return p.str();
}
void Avion::insertaAsientos(Asientos *a){
	if (can < cantPasajeros) {
		asiento[can] = *a;
		can++;
	}
	else {
		cerr << "No hay asientos disponibles!" << endl;
	}
}
Asientos Avion::devuelve(){
	return *asiento;
}
Avion::~Avion(){}
