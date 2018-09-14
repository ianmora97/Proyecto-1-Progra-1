#include "VuelosGestion.h"
VuelosGestion::VuelosGestion() {
	vuelo = new  Vuelos*[100]; //Declara hasta 100 vuelos (el proyecto no especifica cuantos vuelos se pueden hacer)
	cant = 0;
	tam = 100;
}
void VuelosGestion::col(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }
void VuelosGestion::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void VuelosGestion::insertar(Vuelos *v) {
	if (cant < tam) {
		vuelo[cant] = v;
		cant++;
	}
	else {
		col(12);
		cout << "No hay campo para insertar vuelos!\n";
		col(15);
	}
}
void VuelosGestion::insertar(Avion *av, Rutas *ruta,int canR, int canF, string nomRut,int dur){
	system("cls");
	col(10);
	cout << "\t\t(Ingresar Vuelos)\n\n";
	col(15);
	if (cant < tam) {
		if (canR != 0 && canF != 0) {
			string nomRuta = nomRut, fecha = "";
			int horaSalida = 0,horaLlegada = 0, suma = 0;
			string aereoSalida = "", aereoLlegada = "", piloto = "";
			bool cicloSelecHora = true;
			fecha = vuelo[0]->muestraFecha();
			cout << endl;
			cout << "\tSeleccione la hora de salida (Solo la hora en ";
			col(14);
			cout << " AMARILLO";
			col(15);
			cout << ")\n" << endl;
			cout << "\tAM\t\t\t\tPM\n";
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 2; j++) {
					if (j == 1) {
						col(14);
						cout << "\t" << i + 13;
						col(15);
						cout << ":" << "00\t\t\t";
					}
					else {
						col(14);
						cout << "\t" << i + 1;
						col(15);
						cout << ":" << "00\t\t\t";
					}
				}
				cout << endl;
			}
			cout << endl;
			while (cicloSelecHora) {
				cout << "\t> ";
				col(14);
				if (!(cin >> horaSalida)) {
					col(12);
					cerr << "Digite un numero!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else {
					if (horaSalida >= 1 && horaSalida <= 24) {
						cicloSelecHora = false;
					}
					else {
						col(12);
						cerr << "Digite un numero de la lista!\n";
						col(15);
						cin.clear();
						cin.ignore(1024, '\n');
					}
				}
				col(15);
			}
			suma = horaSalida + (dur); //pide por la duracion del avion y la suma a la hora de salida para la hora de llegada
			if (suma > 24) { horaLlegada = suma - 24; } //verificacion de la hora de llegada si se pasa de 24
			else { horaLlegada = suma; }
			system("cls");
			cout << "\nNombre de la ruta: " << nomRuta << endl;
			cout << "\nDigite el aereopuerto de salida > ";
			cin.ignore();
			getline(cin, aereoSalida);
			cout << "\nDigite el aereopuerto de llegada > ";
			getline(cin, aereoLlegada);
			cout << "\nDigite el nombre del piloto > ";
			getline(cin, piloto);
			system("cls");
			vuelo[cant] = new Vuelos(nomRuta,fecha,horaSalida,horaLlegada,aereoSalida,aereoLlegada,piloto,av,ruta);
			cant++;

			col(10);
			cout << "Un vuelo ha sido creado!\n";
			col(15);
			col(11);
			cout << " Avion:\n";
			col(15);
			cout << devuelveVuelo(cant-1).devuelveAvion().toString() << endl;
			col(11);
			cout << " Vuelo:\n";
			col(15);
			cout << devuelveVuelo(cant-1).toString() << endl;
		}
		else if (canR == 0) {
			col(12);
			cerr << "No hay rutas ingresadas!\nIngrese una ruta primero en [Modulo Gestion de Ruta]\n";
			col(15);
		}
		else if (canF == 0) {
			col(12);
			cerr << "No hay aviones registrados!\nRegistre un avion primero en [Modulo Gestion de Flota]\n";
			col(15);
		}
	}
	else {
		col(12);
		cout << "No hay campo para insertar vuelos!\n";
		col(15);
	}
	system("PAUSE");
}
void VuelosGestion::visualizar() {
	system("cls");
	col(10);
	cout << "\t\t(Visualizar Vuelos)\n\n";
	col(15);
	cout << "La empresa tiene: " << cant;
	cant > 1 ? cout << " vuelos "<<endl : cout << " vuelo " << endl;
	cout << "Cual vuelo desea visualizar?\n";
	for (int i = 0; i < cant;i++) {
		col(10);
		cout << "\t[" << i + 1 << "]  ";
		col(15);
	}
	cout << endl;
	int opcV;
	bool ve = true;
	while (ve) {
		cout << "\t> ";
		col(10);
		if (!(cin>>opcV)) {
			col(12);
			cout << "ERROR!\n";
			col(15);
			cin.clear();
			cin.ignore(1024,'\n');
		}
		else {
			if (opcV > 0 && opcV <= cant) {
				ve = false;
			}
			else {
				col(12);
				cout << "ERROR!\n";
				col(15);
				cin.clear();
				cin.ignore(1024,'\n');
			}
		}
		col(15);
	}

	cout << "\n-------------------------------------------\n";
	col(11);
	cout << " - Vuelo: " << opcV << endl << endl;
	col(15);
	cout << vuelo[opcV-1]->toString() << endl;
	col(11);
	cout << " - Avion: "<<endl;
	col(15);
	cout <<vuelo[opcV-1]->devuelveAvion().toString()<<endl;
	vuelo[opcV-1]->devuelveAvion().imprimeAsientos();
	col(11);
	cout << "\n - Tiquetes"<<endl<<endl;
	col(15);
	cout << vuelo[opcV-1]->devuelveAvion().toStringPasajeros();
	cout << endl;
	system("PAUSE");
}
void VuelosGestion::modificar(){
	system("cls");
	col(10);
	cout << "\t\t(Modificar Vuelos)\n\n";
	col(15);
	if (cant != 0) {
		cout << "\tQue vuelo desea modificar?\n";
		for (int i = 0; i < cant; i++) {
			col(10);
			cout << "\t[" << i + 1 << "] ";
			col(15);
			cout << vuelo[i]->getNomRuta() << endl;
		}
		col(10);
		cout << "\t[0]";
		col(15);
		cout << " Cancelar\n";
		int opcVueloRuta;
		bool opcVueloCiclo = true;
		while (opcVueloCiclo) { //valida que haya ingresado bien los datos y que este en el rango de numeros
			cout << "\t> ";
			col(10);
			if (!(cin >> opcVueloRuta)) {
				col(12);
				cerr << "Error! Digite numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opcVueloRuta >= 0 && opcVueloRuta <= cant) {
					opcVueloCiclo = false;
				}
				else {
					col(12);
					cerr << "Error! Digite numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					opcVueloCiclo = true;
				}
			}
			col(15);
		}
		if (opcVueloRuta != 0) {
			
			int opcVuelo = opcVueloRuta - 1;
			cout << "\tQue desea modificar?\n\n";
			col(10);
			cout << "\t[1]";
			col(15);
			cout << " Fecha\n";
			col(10);
			cout << "\t[2]";
			col(15);
			cout << " Hora de Salida\n";
			col(10);
			cout << "\t[3]";
			col(15);
			cout << " Aereopuerto de Salida\n";
			col(10);
			cout << "\t[4]";
			col(15);
			cout << " Aereopuerto de Llegada\n";
			col(10);
			cout << "\t[5]";
			col(15);
			cout << " Nombre del piloto\n";
			col(10);
			cout << "\t[6]";
			col(15);
			cout << " Nombre de la ruta\n";
			col(10);
			cout << "\t[0] ";
			col(15);
			cout << "Cancelar\n";
			int opcModifica;
			bool c = true;
			while (c) {
				cout << "\t> ";
				col(10);
				if (!(cin >> opcModifica)) {
					col(12);
					cerr << "Error! Digite numero!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else {
					if (opcModifica >= 0 && opcModifica <= 6) {
						c = false;
					}
					else {
						col(12);
						cerr << "Error! Digite numero!\n";
						col(15);
						cin.clear();
						cin.ignore(1024, '\n');
						c = true;
					}
				}
				col(15);
			}
			string vueloNombre_temp;
			string cadena;
			string fecha_temp;
			int horaSalida_temp;
			int horaLlegada_temp;
			string aereoSalida_temp;
			string aereoLlegada_temp;
			string piloto_temp;
			bool ciclo_validaciones = true;
			system("cls");
			int dura;
			int suma;
			switch (opcModifica) {
			case 1:
				col(10);
				cout << "\t\t(Fecha)\n\n";
				col(15);
				cout << "La fecha del Vuelo es: " << vuelo[opcVuelo]->getFecha() << endl;
				vuelo[opcVuelo]->setFecha(vuelo[opcVuelo]->muestraFecha());
				cout << endl;
				col(10);
				cout << "Cambio relizado correctamente!\n";
				col(15);
				break;
			case 2:
				col(10);
				cout << "\t\t(Hora de Salida)\n\n";
				col(15);
				cout << "La hora de salida del Vuelo es: " << vuelo[opcVuelo]->getHoraSalida() << endl;
				cout << "\tAM\t\t\t\tPM\n";
				for (int i = 0; i < 12; i++) {
					for (int j = 0; j < 2; j++) {
						if (j == 1) {
							col(14);
							cout << "\t" << i + 13;
							col(15);
							cout << ":" << "00\t\t\t";
						}
						else {
							col(14);
							cout << "\t" << i + 1;
							col(15);
							cout << ":" << "00\t\t\t";
						}
					}
					cout << endl;
				}
				cout << endl;
				cout << "\nDigite la nueva hora de salida: >";
				while (ciclo_validaciones) {
					cout << ">";
					if (!(cin >> horaSalida_temp)) {
						col(12);
						cerr << "Error! Digite un numero!\n";
						col(15);
						cin.clear();
						cin.ignore(1024, '\n');
						ciclo_validaciones = true;
					}
					else { ciclo_validaciones = false; }
				}
				//--una verificacion para saber la hora de llegada del vuelo
				dura = (vuelo[opcVuelo]->getHoraLlegada()) - (24) - (vuelo[opcVuelo]->getHoraSalida()) + 24; 
				vuelo[opcVuelo]->setHoraSalida(horaSalida_temp);
				suma = vuelo[opcVuelo]->getHoraSalida() + dura;
				if (suma > 24) { horaLlegada_temp = suma - 24; }
				else { horaLlegada_temp = suma; }
				//--!una verificacion para saber la hora de llegada del vuelo
				vuelo[opcVuelo]->setHoraLlegada(horaLlegada_temp);
				col(10);
				cout << "Cambio relizado correctamente!\n";
				col(15);
				break;
			case 3:
				col(10);
				cout << "\t\t(Aereopuerto de Salida)\n\n";
				col(15);
				cout << "El aereopuerto de salida del Vuelo es: " << vuelo[opcVuelo]->getAereoSalida() << endl;
				cout << endl;
				cout << "Digite el nuevo aereopuerto de salida: >";
				cin.ignore();
				getline(cin, aereoSalida_temp);
				vuelo[opcVuelo]->setAereoSalida(aereoSalida_temp);
				col(10);
				cout << "Cambio relizado correctamente!\n";
				col(15);
				break;
			case 4:
				col(10);
				cout << "\t\t(Aereopuerto de Llegada)\n\n";
				col(15);
				cout << "El aereopuerto de llegada del Vuelo es: " << vuelo[opcVuelo]->getAereoLlegada() << endl;
				cout << endl;
				cout << "Digite el nuevo aereopuerto de llegada: >";
				cin.ignore();
				getline(cin, aereoLlegada_temp);
				vuelo[opcVuelo]->setAereoLlegada(aereoLlegada_temp);
				col(10);
				cout << "Cambio relizado correctamente!\n";
				col(15);
				break;
			case 5:
				col(10);
				cout << "\t\t(Nombre del piloto)\n\n";
				col(15);
				cout << "El nombre del piloto del Vuelo es: " << vuelo[opcVuelo]->getPiloto() << endl;
				cout << endl;
				cout << "Digite el nuevo nombre del piloto: >";
				cin.ignore();
				getline(cin, piloto_temp);
				vuelo[opcVuelo]->setPiloto(piloto_temp);
				col(10);
				cout << "Cambio relizado correctamente!\n";
				col(15);
				break;
			case 6:
				col(10);
				cout << "\t\t(Nombre del vuelo)\n\n";
				col(192);
				cout << "[El nombre del vuelo esta relacionado directamente con el nombre de la ruta]\n\n";
				col(15);
				Sleep(700);
				cout << "El nombre del Vuelo es: " << vuelo[opcVuelo]->getNomRuta() << endl;
				cout << endl;
				cout << "Digite el nuevo nombre del vuelo: >";
				cin.ignore();
				getline(cin, vueloNombre_temp);
				for (int i = 0; vueloNombre_temp[i]; i++) {
					vueloNombre_temp[i] = toupper(vueloNombre_temp[i]);
				}
				vuelo[opcVuelo]->setNomRuta(vueloNombre_temp);
				col(10);
				cout << "Cambio relizado correctamente!\n";
				col(15);
				break;
			default:
				break;
			}
		}
	}
	else {
		col(12);
		cout << "No hay vuelos para modificar!\n";
		col(15);
	}
	system("PAUSE");
}
void VuelosGestion::eliminar(){
	system("cls");
	col(10);
	cout << "\t\t(Eliminar Vuelos)\n\n";
	col(15);
	if (cant != 0) { //si hay vuelos 
		cout << "\tCual vuelo desea eliminar?\n";
		for (int i = 0; i < cant; i++) { 
			col(10);
			cout << "\t[" << i+1 << "]";
			col(15);
			cout << vuelo[i]->getNomRuta() << endl;
		}
		col(10);
		cout << "\t[0]";
		col(15);
		cout << " Cancelar\n";
		int opcEligeVuelo;
		bool cic = true;
		while (cic) {
			cout << "\t> ";
			if (!(cin >> opcEligeVuelo)) {
				col(12);
				cerr << "\tError! Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
				cic = true;
			}
			else {
				if (opcEligeVuelo >= 0 && opcEligeVuelo <= cant) {
					cic = false;
				}
				else {
					col(12);
					cerr << "\tError! Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					cic = true;
				}
			}
		}
		if (opcEligeVuelo != 0) {
			int eligeVuelo = opcEligeVuelo - 1;
			if (eligeVuelo == cant - 1) {
				cant--;
				col(10);
				cout << "Se ha eliminado un vuelo Correctamente!\n";
				col(15);
			}
			else {
				vuelo[eligeVuelo] = vuelo[cant - 1];
				cant--;
				col(10);
				cout << "Se ha eliminado un vuelo Correctamente!\n";
				col(15);
			}
		}
	}
	else {
		col(12);
		cout << "No hay vuelos para eliminar!\n";
		col(15);
	}
	system("PAUSE");
}
int VuelosGestion::menu(){
	int opc;
	system("cls");
	col(15);
	cout << endl << endl << endl;
	cout << "\t\t\t\t" << char(201);
	for (int i = 0; i < 30; i++) { cout << char(205); } //imprime una linea de =
	cout << char(187);
	cout << "\n\t\t\t\t" << char(186);
	col(11);
	cout << "     Gestion de Vuelos        ";
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
	bool c = true;
	while (c) {
		gotoxy(35, 20); cout << "Opcion > ";
		col(10);
		if (!(cin >> opc)) { //revisa si falla
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
		else if (opc < 0 || opc >4) {
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
	return opc;
}
int VuelosGestion::getCant(){return cant;}
Vuelos VuelosGestion::devuelveVuelo(int i) {return *vuelo[i];}
void VuelosGestion::toString() {
	for (int i = 0; i < cant; i++) {
		cout << "---------------------------------------------------------------------------------------------" << endl;
		col(11);
		cout << "Vuelo: " << i + 1 << endl << endl;
		col(15);
		cout << vuelo[i]->toString() << endl;
		cout << "Avion asignado: " << endl<<endl;
		cout << vuelo[i]->devuelveAvion().toString() << endl;
		vuelo[i]->devuelveAvion().imprimeAsientos();
		cout << endl;
	}
}
int VuelosGestion::revisaValor(char l, int t) {
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
VuelosGestion::~VuelosGestion() {
	for (int i = 0; i < cant; i++) {
		delete vuelo[i];
	}
	delete[] vuelo;
	cant = 0;
	tam = 0;
	col(10);
	cout << "Se ha destruido los vuelos!" << endl;
	col(15);
}
