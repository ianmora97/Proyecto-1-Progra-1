#include "Avion.h"
Avion::Avion(){
	asientos = new Asientos;
	annio = 0;
	id = 0;
	modelo = " ";
	marca = " ";
	cantPasajeros = 0;
	filas = 0;
	columnas = 0;
}
Avion::Avion(int i, int a, string mo, string ma) : id(i), annio(a), modelo(mo), marca(ma) {}
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

Avion::~Avion(){
}
