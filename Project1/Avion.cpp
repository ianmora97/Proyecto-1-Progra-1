#include "Avion.h"
Avion::Avion(){}
Avion::Avion(int i, int a, string mo, string ma,int t,int f,int c) : id(i), annio(a), modelo(mo), marca(ma), cantidad(0),filas(f),columnas(c),cantPasajeros(t) {
	persona = new Persona**[filas];
	for (int i = 0; i < filas; i++) {
		persona[i] = new Persona*[columnas];
	}
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			persona[i][j] = NULL;
		}
	}
	cantPasajeros == 180 ? tam = "GRANDE" : tam = "PEQUENIO";
}
Avion::Avion(const Avion *a) : id(a->id), annio(a->annio), modelo(a->modelo), marca(a->marca), cantidad(a->cantidad), filas(a->filas), columnas(a->columnas), cantPasajeros(a->cantPasajeros) {
	persona = new Persona**[filas];
	for (int i = 0; i < filas; i++) {
		persona[i] = new Persona*[columnas];
	}
	for (int i = 0; i < a->filas; i++) {
		for (int j = 0; j < a->columnas; j++) {
			persona[i][j] = NULL;
		}
	}
	a->cantPasajeros == 180 ? tam = "GRANDE" : tam = "PEQUENIO";
}
void Avion::col(int c){	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);}
void Avion::setAnnio(int a){ annio=a; }
void Avion::setId(int i) { id = i; }
void Avion::setModelo(string m) { modelo = m; }
void Avion::setMarca(string m) { marca = m; }
void Avion::setCantPasajetos(int p) { cantPasajeros = p; }
void Avion::setFilasColumnas(int f, int c) { filas = f; columnas = c; }
int Avion::getCan() {
	int cont = 0;
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++)
			if (persona[i][j] != NULL)
				cont++;
	return cont;
}
int Avion::getAnnio() { return annio; }
int Avion::getId() { return id; }
int Avion::getCantPasajeros() { return cantPasajeros; }
int Avion::getFilas() { return filas; }
int Avion::getColumnas() { return columnas; }
string Avion::getModelo() { return modelo; }
string Avion::getMarca() { return marca; }
string Avion::toString() {
	int ca = suma();
	stringstream p;
	p << "Identificacion          : " << id << endl;
	p << "A" << char(164) << "o                     : "<<annio<<endl;
	p << "Modelo                  : " << modelo << endl;
	p << "Marca                   : " << marca << endl;
	p << "Capacidad de Pasajeros  : " << cantPasajeros << endl;
	p << "Asientos ocupados       : " << ca << endl;
	p << "Asientos disponibles    : " << (cantPasajeros - ca) << endl;
	p << "Cantidad de filas       : " << filas<<endl; 
	p << "Cantidad de columnas    : " << columnas << endl;
	p << "Tipo de Avion           : " << tam << endl;
	return p.str();
}
string Avion::toString2() {
	int ca = suma();
	stringstream p;
	p << id <<"  ";
	p << annio << "  ";
	p << modelo << "  ";
	p << marca << "  ";
	p << cantPasajeros << "  ";
	p << ca << "  ";
	p << (cantPasajeros - ca) << "  ";
	p << filas << "  ";
	p << columnas << "  ";
	return p.str();
}
int Avion::suma() { 
	int ca=0;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (persona[i][j] != NULL) {
				ca++;
			}
		}
	}
	return ca;
}
int Avion::letraXNumero(char l) {
	int i;
	if (l == 'a' || l == 'A') {
		i = 0;
	}
	if (l == 'b' || l == 'B') {
		i = 1;
	}
	if (l == 'c' || l == 'C') {
		i = 2;
	}
	if (l == 'd' || l == 'D') {
		i = 3;
	}
	if (l == 'e' || l == 'E') {
		i = 4;
	}
	if (l == 'f' || l == 'F') {
		i = 5;
	}
	return i;
}
int Avion::revisaValor(char l, int t) {
	int v;
	if (t == 180) {
		if (l == 'a' || l == 'A' || l == 'b' || l == 'B' || l == 'c' || l == 'C' || l == 'd' || l == 'D' || l == 'e' || l == 'E' || l == 'f' || l == 'F') {
			v = 1;
		}
		else {
			v = 0;
		}
	}
	else if (t == 100) {
		if (l == 'a' || l == 'A' || l == 'b' || l == 'B' || l == 'c' || l == 'C' || l == 'd' || l == 'D') {
			v = 1;
		}
		else {
			v = 0;
		}
	}
	return v;
}
void Avion::imprimeAsientos() {
	int medio = ((filas / 2) - 1); //hace un doble salto en la mitad de la matriz
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	for (int i = 0; i < columnas; i++) { i >= 9 ? cout << i + 1 << " " : cout << " " << i + 1 << " "; } //imprime los numeros de las columnas/filas
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl;
	for (int i = 0; i < (columnas * 3) + 1; i++) { cout << "-"; } //imprime linea blanca
	cout << endl;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			cout << "[";
			if ((persona[i][j]) != NULL) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //rojo
				cout << "0";
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //verde
				cout << "0";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "]";
		}
		if (i == medio) {
			cout << " | ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << char(65 + i) << endl << endl; //imprime los valores ascii de la A - f
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else {
			cout << " | ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << char(65 + i) << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int i = 0; i < (columnas * 3) + 1; i++) { cout << "-"; }
	cout << endl;
}
bool Avion::verifica(char f, int c) {
	if (persona[letraXNumero(f)][c - 1] == NULL) {
		return true;
	}
	return false;
}
bool Avion::insertarPersona(Persona *p,char f,int c){
	if (suma() < cantPasajeros) {
		if (persona[letraXNumero(f)][c - 1] == NULL) {
			persona[letraXNumero(f)][c - 1] = p;
			col(10);
			cout << "Se ha insertado una persona correctamente!\n";
			col(15);
			return true;
		}
		else { return false; }
	}
	else {
		col(12);
		cout << "No hay espacio!\n";
		col(15);
		return false;
	}
	cantidad = suma();
}
void Avion::eliminarPersonas() {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			
			persona[i][j] = NULL;
		}
	}
}
Persona Avion::devuelvePersona(int f,int c){return *persona[f][c];}
string Avion::toStringPasajeros() {
	stringstream p;
	for (int i = 0; i < filas;i++) {
		for (int j = 0; j < columnas; j++) {
			if (persona[i][j] != NULL) {
				p << persona[i][j]->toString();
			}
		}
	}
	return p.str();
}
Avion::~Avion(){
	id = 0;
	annio = 0;
	modelo = " ";
	marca = " ";
	cantPasajeros = 0;
	cantidad = 0;
	filas = 0;
	columnas = 0;
}
