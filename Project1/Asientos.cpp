#include "Asientos.h"

Asientos::Asientos(char t) {
	if (t == 'g') {
		tipo = "GRANDE";
		tam = 180;
		asiento = new Persona*[180];
		f = 6, c = 30;
	}
	else if(t == 'p') {
		tipo = "PEQUENIO";
		tam = 100;
		asiento = new Persona*[100];
		f = 4, c = 25;
	}
	can = 0;
	for (int i = 0; i < f;i++) {
		for (int j = 0; j < c; j++) {
			asiento[i] = NULL;
			vec[i][j] = 0;
		}
	}
}
int Asientos::getFilas() { return f; }
int Asientos::getColumnas() { return c; }
int Asientos::getTam() { return tam; }
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
void Asientos::insertaPersona(Persona *p, char a,int b) {
	if (can<tam) {
		int fi;
		int co;
		asiento[can] = p;
		can++;
		fi = letraXNumero(a);
		co = b;
		vec[fi][co-1] = 1;
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
	for (int i = 0; i < (c*3)+1; i++) { cout << "-"; }
	cout << endl;
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			cout << "[";
			if (vec[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << "0";
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
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
Asientos::~Asientos(){
	for (int i = 0; i < can; i++) {
		delete asiento[i];
	}
	delete[] asiento;
	can = 0;
	tam = 0;
	for (int i=0;i<f;i++)
		for (int j=0;j<c;j++)
			vec[i][j] = 0;
	f = 0;
	c = 0;
}
