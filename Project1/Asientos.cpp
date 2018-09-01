#include "Asientos.h"

Asientos::Asientos(int t,int fi,int co) {
	tam = t;
	f = fi;
	c = co;
	asiento = new Persona**[f];
	for (int i = 0; i < f;i++) {
		asiento[i] = new Persona*[c];
	}
	can = 0;
}
int Asientos::getFilas() { return f; }
int Asientos::getColumnas() { return c; }
int Asientos::getTam() { return tam; }
int Asientos::getCant() { return can; }
string Asientos::getTipo() { return tipo; }
int Asientos::letraXNumero(char l){
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
int Asientos::revisaValor(char l, int t) {
	int v;
	if (t == 180) {
		if (l == 'a' || l == 'A' || l == 'b' || l == 'B' || l == 'c' || l == 'C' || l == 'd' || l == 'D' || l == 'e' || l == 'E' || l == 'f' || l == 'F') {
			v = 1;
		}
		else {
			v = 0;
		}
	}
	else if(t == 100){
		if (l == 'a' || l == 'A' || l == 'b' || l == 'B' || l == 'c' || l == 'C' || l == 'd' || l == 'D') {
			v = 1;
		}
		else {
			v = 0;
		}
	}
	return v;
}
void Asientos::insertaPersona(Persona *p, char a,int b) {
	if (can<tam) {
		int fi;
		fi = letraXNumero(a);
		asiento[fi][b] = p;
		can++;
	}
	else {
		cerr << "No hay asientos disponibles!" << endl;
	}
}
void Asientos::imprimeAsientos() {
	int medio = ((f/2)-1); //hace un doble salto en la mitad de la matriz
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	for (int i = 0; i < c; i++) { i >= 9 ? cout << i + 1 << " " : cout << " " << i + 1 << " "; } //imprime los numeros de las columnas/filas
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl;
	for (int i = 0; i < (c*3)+1; i++) { cout << "-"; } //imprime linea blanca
	cout << endl;
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			cout << "[";
			if (asiento[i][j]->getEstado() == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //verde
				cout << "0";
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //rojo
				cout << "0";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "]";
		}
		if (i == medio) {
			cout << " | ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout<< char(65 + i) << endl << endl; //imprime los valores ascii de la A - f
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else {
			cout << " | ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout<< char(65 + i) << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int i = 0; i < (c * 3) + 1; i++) { cout << "-"; }
	cout << endl;
}
Persona Asientos::devuelvePersona(int fi,int co) {return *asiento[fi][co];}
Asientos::~Asientos(){}
