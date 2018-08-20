#include "Avion.h"
Avion::Avion() {
	asiento = new Persona[180];
	can = 0;
	filas = 0, columnas = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 30; j++) {
			ma[i][j] = 0;
		}
	}
	annio = 0;
	id = 0;
	modelo = " ";
	marca = " ";
	cantPasajeros = 0;
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
int Avion::letraXNumero(char l){
	if (l == 'a' || l == 'A') {
		return 1;
	}
	if (l == 'b' || l == 'B') {
		return 2;
	}
	if (l == 'c' || l == 'C') {
		return 3;
	}
	if (l == 'd' || l == 'D') {
		return 4;
	}
	if (l == 'e' || l == 'E') {
		return 5;
	}
	if (l == 'f' || l == 'F') {
		return 6;
	}
}
void Avion::insertaPersona(Persona &p, char a, int b){
	if (can <= 180) {
		asiento[can] = p;
		can++;
		filas = letraXNumero(a) - 1;
		columnas = b;
		ma[filas + 1][columnas - 1] = 1;
	}
	else {
		cerr << "No hay asientos disponibles!" << endl;
	}
}
void Avion::imprimeAsientos(){
	col(10);
	for (int i = 0; i < 30; i++) { i >= 9 ? cout << i + 1 << " " : cout << " " << i + 1 << " "; } //imprime los numeros de las columnas/filas
	col(15);
	cout << "\n-------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 30; j++) {
			cout << "[";
			if (ma[i][j] == 1) {
				col(10);
				cout << "0";
			}
			else {
				col(12);
				cout << "0";
			}
			col(15);
			cout << "]";
		}
		if (i == 2) {
			cout << " | ";
			col(10);
			cout << char(65 + i) << endl << endl; //imprime los valores ascii de la A - F
			col(15);
		}
		else {
			cout << " | ";
			col(10);
			cout << char(65 + i) << endl;
			col(15);
		}
	}
	col(15);
	cout << "-------------------------------------------------------------------------------------------" << endl;

}
Avion::~Avion(){}
