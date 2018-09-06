#include "VuelosGestion.h"
VuelosGestion::VuelosGestion() {
	vuelo = new  Vuelos*[100]; //Declara hasta 100 vuelos (no especifica cuantos vuelos se pueden hacer)
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
void VuelosGestion::insertarVuelo(Vuelos *v) {
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
void VuelosGestion::visualizar() {
	cout << "La empresa tiene: " << cant;
	cant > 1 ? cout << " vuelos "<<endl : cout << " vuelo " << endl;
	cout << "Cual vuelo desea visualizar?\n";
	for (int i = 0; i < cant;i++) {
		col(10);
		cout << "\t[" << i + 1 << "] - ";
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
				for (int i = 1; i <= 24; i++) {
					if (i == 13) {
						cout << endl;
					}
					col(14);
					cout << i;
					col(15);
					cout << ":" << "00 ";
				}
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
}
void VuelosGestion::imprimeMenu(){
	system("cls");
	col(11);
	cout << "\t\tMenu";
	col(10);
	cout << "\t\t\t\t\t[Gestion de Vuelos]\n";
	col(15);
	for (int i = 0; i < 40; i++) { cout << "-"; }
	cout << "\n\n";
	col(10);
	cout << "\t[1]";
	col(15);
	cout << " Insertar\n";
	col(10);
	cout << "\t[2]";
	col(15);
	cout << " Visualizar\n";
	col(10);
	cout << "\t[3]";
	col(15);
	cout << " Modificar\n";
	col(10);
	cout << "\t[4]";
	col(15);
	cout << " Eliminar\n";
	col(10);
	cout << "\t[0]";
	col(15);
	cout << " Volver al menu principal\n\n";
}
void VuelosGestion::interfaz(){
	bool c = true;
	while (c) {
		cout << "\t> ";
		col(10);
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
		col(15);
	}
}
int VuelosGestion::getOpc(){
	return opc;
}
int VuelosGestion::getCant(){return cant;}
void VuelosGestion::flotaVisualizar(){
	FlotaGestion *f=new FlotaGestion;
	f->visualizarAviones();
}
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
