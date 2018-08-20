#include "Asientos.h"

Asientos::Asientos() {
	asiento = new Persona[180];
	can = 0;
	f = 0, c = 0;
	for (int i = 0; i < 6;i++) {
		for (int j = 0; j < 30;j++) {
			vec[i][j] = 0;
		}
	}
}
int Asientos::letraXNumero(char l){
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
void Asientos::insertaPersona(Persona &p, char a,int b) {
	if (can<=180) {
		asiento[can] = p;
		can++;
		f = letraXNumero(a)-1;
		c = b;
		vec[f+1][c-1] = 1;
	}
	else {
		cerr << "No hay asientos disponibles!" << endl;
	}
}

void Asientos::imprimeAsientos() {
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	for (int i = 0; i < 30; i++) { i >= 9 ? cout << i + 1 << " " : cout << " " << i + 1 << " "; } //imprime los numeros de las columnas/filas
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "\n-------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 30; j++) {
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
		if (i == 2) {
			cout << " | ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout<< char(65 + i) << endl << endl; //imprime los valores ascii de la A - F
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else {
			cout << " | ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout<< char(65 + i) << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "-------------------------------------------------------------------------------------------" << endl;

}

Asientos::~Asientos()
{
}
