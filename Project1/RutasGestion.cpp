#include "RutasGestion.h"

RutasGestion::RutasGestion() {
	ruta = new Rutas*[100]; //se pueden hacer hasta 100 rutas, (el proyecto no especifica cuantas rutas se puedan hacer)
	cant = 0;
	tam = 100;
}
void RutasGestion::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void RutasGestion::col(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }
int RutasGestion::getCant(){
	return cant;
}
void RutasGestion::ingresarRuta(Rutas *r) {
	if (cant<tam) {
		ruta[cant] = r;
		cant++;
	}
	else {
		col(12);
		cout << "\nNo hay campo para ingresar rutas!";
	}
}
void RutasGestion::visualizar() {
	cout << "La empresa tiene: "<<cant<<" rutas!\n\n";
	for (int i = 0; i < 30; i++) { cout << "-"; }
	cout << endl;
	for (int i = 0; i < cant;i++) {
		col(11);
		cout << "Ruta "<<i+1<<endl;
		col(15);
		cout<<ruta[i]->toString()<<endl;
	}
}
void RutasGestion::modificar(){
	if (cant != 0) {
		cout << "\tDigite la ruta que quiera modificar:\n";
		for (int i = 0; i < cant; i++) {
			col(10);
			cout << "\t[" << i + 1 << "] ";
			col(15);
			cout << ruta[i]->sumaRuta() << endl;
		}
		col(10);
		cout << "\t[0] ";
		col(15);
		cout << "Cancelar\n";
		int opc;
		bool ciclo = true;
		while (ciclo) {
			cout << "\t> ";
			if (!(cin >> opc)) {
				col(12);
				cerr << "Error!\nDigite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opc >= 0 && opc <= cant) {
					ciclo = false;
				}
				else {
					ciclo = true;
				}
			}
		}
		if (opc != 0) {
			int opcR = opc - 1;
			
			cout << "\n\n";
			cout << "\tQue desea modificar?\n";
			col(10);
			cout << "\t[1]";
			col(15);
			cout << " Destino\n";
			col(10);
			cout << "\t[2]";
			col(15);
			cout << " Origen\n";
			col(10);
			cout << "\t[3]";
			col(15);
			cout << " Duracion\n";
			col(10);
			cout << "\t[4]";
			col(15);
			cout<< " Cantidad de Escalas\n";
			col(10);
			cout << "\t[0]";
			col(15);
			cout << " Cancelar\n";

			int opc2;
			bool ciclo2 = true;
			string cambio;
			int cambioN;
			bool d = true;
			bool d1 = true;
			while (ciclo2) {
				cout << "\t> ";
				if (!(cin >> opc2)) {
					col(12);
					cerr << "Error!\nDigite un numero!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else {
					if (opc2 >= 0 && opc2 < 5) {
						ciclo2 = false;
					}
					else {
						ciclo2 = true;
					}
				}
			}
			if (opc2 != 0) {
				switch (opc2) {
				case 1:
					col(11);
					cout << "(Destino)\n\n";
					col(15);
					cout << "[" << opc << "] " << ruta[opcR]->sumaRuta() << endl;
					cout << "Digite el nuevo destino:\n>";
					cin.ignore();
					getline(cin, cambio);
					ruta[opcR]->setDestino(cambio);
					col(10);
					cout << "\nCambio realizado correctamente!\n";
					col(15);
					break;
				case 2:
					col(11);
					cout << "(Origen)\n\n";
					col(15);
					cout << "[" << opc << "] " << ruta[opcR]->sumaRuta() << endl;
					cout << "Digite el nuevo origen:\n>";
					cin.ignore();
					getline(cin, cambio);

					ruta[opcR]->setOrigen(cambio);
					col(10);
					cout << "\nCambio realizado correctamente!\n";
					col(15);
					break;
				case 3:
					col(11);
					cout << "(Duracion)\n\n";
					col(15);
					cout << "[" << opc << "] " << ruta[opcR]->getDuracion() << endl;
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
					ruta[opcR]->setDuracion(cambioN);
					col(10);
					cout << "\nCambio realizado correctamente!\n";
					col(15);
					break;
				case 4:
					col(11);
					cout << "(Cantidad de escalas)\n\n";
					col(15);
					cout << "[" << opc << "] " << ruta[opcR]->getCantEscalas() << endl;
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
					ruta[opcR]->setCantEscalas(cambioN);
					col(10);
					cout << "\nCambio realizado correctamente!\n";
					col(15);
					break;
				default:
					break;
				}
			}
		}
	}
	else {
		col(12);
		cout << "No hay rutas que modificar!\n";
		col(15);
	}
}
void RutasGestion::eliminar() {
	if (cant != 0) {
		cout << "Cual ruta desea eliminar?\n";
		for (int i = 0; i < cant; i++) {
			col(10);
			cout << "\t[" << i + 1 << "] ";
			col(15);
			cout << ruta[i]->getOrigen() << "-" << ruta[i]->getDestino() << endl;
		}
		col(10);
		cout << "\t[0] ";
		col(15);
		cout << "Cancelar\n";
		int opc1;
		bool ciclo = true;
		while (ciclo) {
			cout << "\t> ";
			if (!(cin >> opc1)) {
				col(12);
				cerr << "Error!\nDigite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opc1 >= 0 && opc1 <= cant) {
					ciclo = false;
				}
				else {
					col(12);
					cerr << "Error!\nDigite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
		}
		if (opc1 != 0) {
			int opcR = opc1 - 1;
			if (opcR == cant - 1) {
				cant--;
			}
			else {
				ruta[opcR] = ruta[cant - 1];
				cant--;
			}
			col(10);
			cout << "\nSe ha eliminado la ruta correctamente!\n";
			col(15);
		}
	}
	else {
		col(12);
		cout << "No hay rutas para eliminar!\n";
		col(15);
	}
	
}
void RutasGestion::imprimirMenu(){
	system("cls");
	col(15);
	cout << endl << endl << endl;
	cout << "\t\t\t\t" << char(201);
	for (int i = 0; i < 30; i++) { cout << char(205); } //imprime una linea de =
	cout << char(187);
	cout << "\n\t\t\t\t" << char(186);
	col(11);
	cout << "      Gestion de Rutas        ";
	col(15);
	cout << char(186) << endl;
	col(15);
	cout << "\t\t\t\t" << char(200);
	for (int i = 0; i < 30; i++) { cout << char(205); }
	cout << char(188) << endl;

	cout << "\t\t\t" << char(201);
	for (int i = 0; i < 46; i++) { cout << char(205); } //imprime una linea de =
	cout << char(187);
	cout << endl;
	cout << "\t\t\t";
	cout << char(186) << endl;

	cout << "\t\t\t";
	cout << char(186);
	col(10);
	cout << "  [1]";
	col(15);
	cout << "   Ingresar        \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(10);
	cout << "  [2]";
	col(15);
	cout << "   Visualizar      \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(10);
	cout << "  [3]";
	col(15);
	cout << "   Modificar       \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(10);
	cout << "  [4]";
	col(15);
	cout << "   Eliminar        \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(10);
	cout << "  [0]";
	col(15);
	cout << "   Menu Principal    \n";
	cout << "\t\t\t";
	cout << char(186);

	cout << "\n\t\t\t" << char(204);
	for (int i = 0; i < 46; i++) { cout << char(205); } //imprime una linea de =
	cout << char(185) << endl;
	cout << "\t\t\t" << char(186) << endl;
	cout << "\t\t\t" << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "\n\t\t\t" << char(200);
	for (int i = 0; i < 46; i++) { cout << char(205); } //imprime una linea de =
	cout << char(188) << endl;
	for (int i = 0; i < 11; i++) {
		gotoxy(71, 7 + i); cout << char(186);
	}
	gotoxy(71, 19); cout << char(186);
	gotoxy(71, 20); cout << char(186);
	gotoxy(71, 21); cout << char(186);
}
void RutasGestion::interfaz(){
	bool c = true;
	while (c) {
		gotoxy(35, 20); cout << "Opcion > ";
		col(10);
		if (!(cin >> opci)) { //revisa si falla
			col(15);
			gotoxy(44, 20); cout << "                           " << char(186) << "            "; //limpia el buffer
			col(12);
			gotoxy(55, 20); cout << "Error!";
			col(15);
			Sleep(700);
			gotoxy(44, 20); cout << "                           "; //limpia el error
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (opci < 0 || opci >4) {
			col(15);
			gotoxy(44, 20); cout << "                           " << char(186) << "            ";//limpia el buffer
			col(12);
			gotoxy(55, 20); cout << "Error!";
			col(15);
			Sleep(700);
			gotoxy(44, 20); cout << "                           "; //limpia el error
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else { c = false; }
		col(15);
	}
}
int RutasGestion::opc() {return opci;}
void RutasGestion::mostrarRutas() {
	for (int i = 0; i < cant; i++) {
		col(11);
		cout << "Ruta: " << i + 1 << endl;
		col(15);
		cout << ruta[i]->toString() << endl;
	}
}
Rutas RutasGestion::devuele(int i){
	return *ruta[i];
}
RutasGestion::~RutasGestion(){
	for (int i = 0; i < cant; i++) {
		delete ruta[i];
	}
	delete[] ruta;
	cant = 0;
	tam = 0;
	col(10);
	cout << "Se ha destruido las rutas!" << endl;
	col(15);
}

