#include "RutasGestion.h"

RutasGestion::RutasGestion(){
	ruta = new Rutas[100]; //se pueden hacer hasta 100 rutas, (el proyecto no especifica cuantas rutas se puedan hacer)
	cant = 0;
	tam = 100;
}
void RutasGestion::col(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }
void RutasGestion::ingresarRuta(Rutas &r) {
	if (cant<tam) {
		ruta[cant] = r;
		cant++;
		col(10);
		cout << "\nSe ha ingresado una ruta correctamente!\n";
		col(15);
	}
	else {
		col(12);
		cout << "\nNo hay campo para ingresar rutas!";
	}
}
void RutasGestion::visualizar() {
	system("cls");
	col(10);
	cout << "\t\t(Visualizar Rutas)\n\n";
	col(15);
	cout << "La empresa tiene: "<<cant<<" rutas!\n\n";
	for (int i = 0; i < cant;i++) {
		cout<<ruta[i].toString()<<endl;
	}
}
void RutasGestion::modificar(){
	system("cls");
	col(10);
	cout << "\t\t(Modificar Ruta)\n\n";
	col(15);
	if (cant != 0) {
		cout << "Digite la ruta que quiera modificar:\n";
		for (int i = 0; i < cant; i++) {
			cout << "[" << i << "] " << ruta[i].getOrigen() << "-" << ruta[i].getDestino() << endl;
		}
		int opc;
		bool ciclo = true;
		while (ciclo) {
			cout << "> ";
			if (!(cin >> opc)) {
				col(12);
				cerr << "Error!\nDigite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opc >= 0 && opc < cant) {
					ciclo = false;
				}
				else {
					ciclo = true;
				}
			}
		}

		system("cls");
		cout << "\n";
		cout << "Que desea modificar?\n";
		cout << "[1] Destino\n[2] Origen\n[3] Duracion\n[4] Cantidad de Escalas\n";
		int opc2;
		bool ciclo2 = true;
		string cambio;
		int cambioN;
		bool d = true;
		bool d1 = true;
		while (ciclo2) {
			cout << "> ";
			if (!(cin >> opc2)) {
				col(12);
				cerr << "Error!\nDigite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opc2 >= 0 && opc2 < cant) {
					ciclo2 = false;
				}
				else {
					ciclo2 = true;
				}
			}
		}
		switch (opc2) {
		case 1:
			col(11);
			cout << "(Destino)\n\n";
			col(15);
			cout << "[" << opc << "] " << ruta[opc].getOrigen() << "-" << ruta[opc].getDestino() << endl;
			cout << "Digite el nuevo destino:\n>";
			cin.ignore();
			getline(cin, cambio);
			ruta[opc].setDestino(cambio);
			col(10);
			cout << "\nCambio realizado correctamente!";
			col(15);
			break;
		case 2:
			col(11);
			cout << "(Origen)\n\n";
			col(15);
			cout << "[" << opc << "] " << ruta[opc].getOrigen() << "-" << ruta[opc].getDestino() << endl;
			cout << "Digite el nuevo origen:\n>";
			cin.ignore();
			getline(cin, cambio);

			ruta[opc].setOrigen(cambio);
			col(10);
			cout << "\nCambio realizado correctamente!";
			col(15);
			break;
		case 3:
			col(11);
			cout << "(Duracion)\n\n";
			col(15);
			cout << "[" << opc << "] " << ruta[opc].getDuracion() << endl;
			cout << "Digite la nueva duracion:\n";
			while (d1) {
				cout << "> ";
				if (!(cin >> cambioN)) {
					col(12);
					cerr << "Error!\nDigite un numero!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else {
					d1 = false;
				}
			}
			ruta[opc].setDuracion(cambioN);
			col(10);
			cout << "\nCambio realizado correctamente!";
			col(15);
			break;
		case 4:
			col(11);
			cout << "(Cantidad de escalas)\n\n";
			col(15);
			cout << "[" << opc << "] " << ruta[opc].getCantEscalas() << endl;
			cout << "Digite la nueva cantidad de escalas:\n";
			while (d) {
				cout << "> ";
				if (!(cin >> cambioN)) {
					col(12);
					cerr << "Error!\nDigite un numero!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else {
					d = false;
				}
			}
			ruta[opc].setCantEscalas(cambioN);
			col(10);
			cout << "\nCambio realizado correctamente!\n";
			col(15);
			break;
		default:
			break;
		}
	}
	else {
		col(12);
		cout << "No hay rutas que modificar!\n";
		col(15);
	}
}
void RutasGestion::eliminar() {
	system("cls");
	col(10);
	cout << "\t\t(Eliminar Rutas)\n\n";
	col(15);
	if (cant != 0) {
		cout << "Cual ruta desea eliminar?\n";
		for (int i = 0; i < cant; i++) {
			cout << "[" << i << "] " << ruta[i].getOrigen() << "-" << ruta[i].getDestino() << endl;
		}
		int opc;
		bool ciclo = true;
		while (ciclo) {
			cout << ">";
			if (!(cin >> opc)) {
				col(12);
				cerr << "Error!\nDigite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opc >= 0 && opc < cant) {
					ciclo = false;
				}
				else {
					col(12);
					cerr << "Error!\nDigite un numero!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
		}
		if (opc == cant) {
			cant--;
		}
		else {
			ruta[opc] = ruta[cant - 1];
			cant--;
		}
		col(10);
		cout << "\nSe ha eliminado la ruta correctamente!\n";
		col(15);
	}
	else {
		col(12);
		cout << "No hay rutas para eliminar!\n";
		col(15);
	}
	
}
void RutasGestion::imprimirMenu(){
	system("cls");
	col(11);
	cout << "\t\tMenu";
	col(10);
	cout << "\t\t\t\t\t[Gestion de Rutas]\n";
	col(15);
	for (int i = 0; i<40; i++) { cout << "-"; }
	cout << "\n\n";
	cout << "\t[1] Insertar\n";
	cout << "\t[2] Visualizar\n";
	cout << "\t[3] Modificar\n";
	cout << "\t[4] Eliminar\n";
	cout << "\t[0] Volver al menu principal\n";
}
int RutasGestion::interfaz(){
	int opc;
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
			if (opc >= 0 && opc <= 4) {
				c = false;
			}
			else {
				c = true;
			}
		}
	}
	return opc;
}
RutasGestion::~RutasGestion(){}
