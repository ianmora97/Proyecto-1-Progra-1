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
	cout << "\t" << char(201);;
	for (int i = 0; i < 30; i++) { cout<< char(205); } //imprime una linea de =
	cout << char(187);
	cout << "\n\t" << char(186);
	col(11);
	cout << "        MENU PRINCIPAL        ";
	col(15);
	cout << char(186) << endl;
	col(15);
	cout << "\t"<<char(200);
	for (int i = 0; i < 30; i++) { cout << char(205); }
	cout<<char(188)<<endl;
	cout << "-------------------------------------------------";
	cout << "\n\n";
	col(10);
	cout << "\t[1]";
	col(15);
	cout<< " Gestion de Flotas\n";
	col(10);
	cout << "\t[2]";
	col(15);
	cout<<" Gestion de Rutas\n";
	col(10);
	cout << "\t[3]";
	col(15);
	cout<<" Gestion de Vuelos\n";
	col(10);
	cout << "\t[4]";
	col(15);
	cout << " Compra de tiquetes\n";
	col(10);
	cout << "\t[0]";
	col(15);
	cout << " Salir del programa\n\n";

}
int Interfaz::validar() {
	int opc;
	bool c = true;
	while (c) {
		col(15);
		cout << "\tOpcion > ";
		col(10);
		if (!(cin>>opc)) { //revisa si falla
			col(12);
			cout << "\tError! Digite un NUMERO del menu!\n";
			col(15);
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {c = false;}
		col(15);
	}
	return opc;
}
Interfaz::~Interfaz(){}
