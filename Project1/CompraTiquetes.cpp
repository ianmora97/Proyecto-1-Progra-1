#include "CompraTiquetes.h"
CompraTiquetes::CompraTiquetes() { 

	contTiquetesComprados = 0;
	
}
void CompraTiquetes::col(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }
void CompraTiquetes::imprimeMenu(){
	system("cls");
	col(11);
	cout << "\t\tMenu";
	col(11);
	cout << "\t\t\t\t\t[Compra de Tiquetes]\n";
	col(15);
	for (int i = 0; i < 40; i++) { cout << "-"; }
	cout << "\n\n";
	cout << "\t[1]";
	cout << " Compra de tiquetes\n";
	cout << "\t[0]";
	cout << " Salir del programa\n";
}
void CompraTiquetes::interfaz() {
	bool c = true;
	while (c) {
		cout << "> ";
		if (!(cin >> opc)) {
			col(12);
			cerr << "Error!\nDigite un NUMERO del menu!\n";
			col(15);
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {
			if (opc == 0 || opc == 1) {
				c = false;
			}
			else {
				c = true;
			}
		}
	}
}
int CompraTiquetes::getOpc() { return opc; }
void CompraTiquetes::contadorTiquetes() { contTiquetesComprados++; }
int CompraTiquetes::getCant() { return contTiquetesComprados; }
void CompraTiquetes::mostrarTiquetes(int t) {
	col(10);
	cout << "Tiquetes: "<<endl;
	col(11);
	cout << "_______________________________________________"<<endl;
	col(15);
	for (int i = 0; i < contTiquetesComprados; i++) {
	/*	
	col(11);
	cout << "------------------------------------------"<<endl;
	col(15);
	cout << "Persona #"<<i+1<<endl;
	cout<<vuelos.devuelveVuelo(t).devuelve().devuelve().devuelvePersona(i).toString()<<endl;
	cout << "Vuelo: "<<endl;
	cout << vuelos.devuelveVuelo(t).toString() << endl;
	cout << "Avion: "<<endl;
	cout << vuelos.devuelveVuelo(t).devuelve().toString()<<endl;
	*/
	}
}
CompraTiquetes::~CompraTiquetes(){}
