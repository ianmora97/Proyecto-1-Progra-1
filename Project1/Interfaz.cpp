#include "Interfaz.h"
Interfaz::Interfaz(){}
void Interfaz::col(int c){ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }
int Interfaz::menu() { //cuantas opciones hay en el menu
	int opc;
	opc = validar();
	return opc;
}
void Interfaz::imprime(){
	system("cls");
	col(11);
	cout << "\t\tMenu";
	col(10);
	cout << "\t\t\t\t\t[Modulos]\n";
	col(15);
	for (int i = 0; i<40; i++) { cout << "-"; }
	cout << "\n\n";
	cout << "\t[1] Gestion de Flotas\n";
	cout << "\t[2] Gestion de Rutas\n";
	cout << "\t[3] Gestion de Vuelos\n";
	cout << "\t[4] Compra de tiquetes\n";
	cout << "\t[0] Salir del programa\n";
}
int Interfaz::validar() {
	int opc;
	bool c = true;
	while (c) {
		cout << "> ";
		if (!(cin>>opc)) { //revisa si falla
			col(12);
			cerr << "Error!\nDigite un NUMERO del menu!\n";
			col(15);
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {c = false;}
	}
	return opc;
}
Interfaz::~Interfaz(){}
