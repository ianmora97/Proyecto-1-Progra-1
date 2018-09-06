#include "Vuelos.h"
Vuelos::Vuelos() {
	numAvionAsignado = 0;
	nomRuta = "";
	fecha = "";
	horaSalida = 0;
	horaLlegada = 0;
	aereoSalida = "";
	aereoLlegada = "";
	piloto = "";
}
Vuelos::Vuelos(string n, string f , int s, int l, string as, string al, string p, Avion av) : nomRuta(n), fecha(f), horaSalida(s), horaLlegada(l), aereoSalida(as), aereoLlegada(al), piloto(p), avion(av){}
void Vuelos::col(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }
string Vuelos::muestraFecha(){
	int mes;
	int cantidadDias = 0;
	int dia;
	string mesL;
	bool cicloMes = true;
	bool cicloDia = true;
	system("cls");
	col(10);
	cout << "\t(Fecha del viaje)\n";
	col(15);
	int annio;
	cout << endl << "Digite el a"<<char(164)<<"o: > ";
	cin >> annio;
	cout << "Seleccione el numero del mes:\n";
	col(11);
	cout << "[1] Enero [2] Febrero [3] Marzo [4] Abril [5] Mayo [6] Junio [7] Julio\n[8] Agosto [9] Septiembre [10] Octubre [11] Noviembre [12] Diciembre\n";
	col(15);
	while (cicloMes) {
		cout << "> ";
		if (!(cin >> mes)) {
			col(12);
			cerr << "Digite un numero!\n";
			col(15);
			cin.clear();
			cin.ignore(1024,'\n');
		}
		else {
			if (1 <= mes && mes <= 12) {
				cicloMes = false;
			}
			else {
				col(12);
				cerr << "Digite un numero de la lista!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
		}
	}
	cout << endl;
	switch (mes) {
	case 1:
		mesL = "ENERO";
		cantidadDias = 31;
		cout << mesL << endl;
		cout << "---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 14 || i == 7 || i==21 || i==28) {
				cout << endl;
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\nDigite un dia:";
		while (cicloDia) {
			cout << "\n> ";
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
				}
				else {
					col(12);
					cerr << "Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
		}
		break;
	case 2:
		mesL = "FEBRERO";
		cantidadDias = 28;
		cout << mesL << endl;
		cout << "---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 14 || i == 7 || i == 21) {
				cout << endl;
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\nDigite un dia:";
		while (cicloDia) {
			cout << "\n> ";
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
				}
				else {
					col(12);
					cerr << "Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
		}
		break;
	case 3:
		mesL = "MARZO";
		cantidadDias = 31;
		cout << mesL << endl;
		cout << "---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl;
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\nDigite un dia:";
		while (cicloDia) {
			cout << "\n> ";
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
				}
				else {
					col(12);
					cerr << "Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
		}
		break;
	case 4:
		mesL = "ABRIL";
		cantidadDias = 30;
		cout << mesL << endl;
		cout << "---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl;
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\nDigite un dia:";
		while (cicloDia) {
			cout << "\n> ";
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
				}
				else {
					col(12);
					cerr << "Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
		}
		break;
	case 5:
		mesL = "MAYO";
		cantidadDias = 31;
		cout << mesL << endl;
		cout << "---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl;
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\nDigite un dia:";
		while (cicloDia) {
			cout << "\n> ";
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
				}
				else {
					col(12);
					cerr << "Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
		}
		break;
	case 6:
		mesL = "JUNIO";
		cantidadDias = 30;
		cout << mesL << endl;
		cout << "---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl;
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\nDigite un dia:";
		while (cicloDia) {
			cout << "\n> ";
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
				}
				else {
					col(12);
					cerr << "Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
		}
		break;
	case 7:
		mesL = "JULIO";
		cantidadDias = 31;
		cout << mesL << endl;
		cout << "---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl;
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\nDigite un dia:";
		while (cicloDia) {
			cout << "\n> ";
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
				}
				else {
					col(12);
					cerr << "Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
		}
		break;
	case 8:
		mesL = "AGOSTO";
		cantidadDias = 31;
		cout << mesL << endl;
		cout << "---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl;
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\nDigite un dia:";
		while (cicloDia) {
			cout << "\n> ";
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
				}
				else {
					col(12);
					cerr << "Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
		}
		break;
	case 9:
		mesL = "SEPTIEMBRE";
		cantidadDias = 30;
		cout << mesL << endl;
		cout << "---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl;
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\nDigite un dia:";
		while (cicloDia) {
			cout << "\n> ";
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
				}
				else {
					col(12);
					cerr << "Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
		}
		break;
	case 10:
		mesL = "OCTUBRE";
		cantidadDias = 31;
		cout << mesL << endl;
		cout << "---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl;
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\nDigite un dia:";
		while (cicloDia) {
			cout << "\n> ";
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
				}
				else {
					col(12);
					cerr << "Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
		}
		break;
	case 11:
		mesL = "NOVIEMBRE";
		cantidadDias = 30;
		cout << mesL << endl;
		cout << "---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl;
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\nDigite un dia:";
		while (cicloDia) {
			cout << "\n> ";
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
				}
				else {
					col(12);
					cerr << "Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
		}
		break;
	case 12:
		mesL = "DICIEMBRE";
		cantidadDias = 31;
		cout << mesL << endl;
		cout << "---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl;
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\nDigite un dia:";
		while (cicloDia) {
			cout << "\n> ";
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
				}
				else {
					col(12);
					cerr << "Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
		}
		break;
	default:
		break;
	}
	
	stringstream p;
	p << dia<<","<<mesL<<","<<annio;
	return p.str();
}
string Vuelos::getNomRuta() { return nomRuta; }
string Vuelos::getFecha() { return fecha; }
int Vuelos::getHoraSalida() { return horaSalida; }
int Vuelos::getHoraLlegada() { return horaLlegada; }
string Vuelos::getAereoSalida() { return aereoSalida; }
string Vuelos::getAereoLlegada() { return aereoLlegada; }
string Vuelos::getPiloto() { return piloto; }
int Vuelos::getNumAvion() { return numAvionAsignado; }
void Vuelos::setNomRuta(string n) { nomRuta = n; }
void Vuelos::setFecha(string f) { fecha = f; }
void Vuelos::setHoraSalida(int hs) { horaSalida = hs; }
void Vuelos::setHoraLlegada(int hl) { horaLlegada = hl; }
void Vuelos::setAereoSalida(string as) { aereoSalida = as; }
void Vuelos::setAereoLlegada(string al) { aereoLlegada = al; }
void Vuelos::setPiloto(string p) { piloto = p; }
void Vuelos::setNumAvion(int n) { numAvionAsignado = n; }
string Vuelos::toString() {
	stringstream p;
	p << "Nombre de la ruta: ";
	p << nomRuta << endl;
	p << "Fecha: ";
	p << fecha << endl;
	p << "Hora de Salida: ";
	p << horaSalida;
	p <<":00"<<endl;
	p << "Hora de llegada: ";
	p << horaLlegada;
	p << ":00"<<endl;
	p << "Aereopuerto de Salida: "<<aereoSalida<<endl;
	p << "Aereopuerto de Llegada: "<<aereoLlegada<<endl;
	p << "Nombre del Piloto: "<<piloto<<endl;
	return p.str();
}
void Vuelos::insertaAvion(Avion a) {avion = a;}
Avion Vuelos::devuelveAvion() { return avion; }
Vuelos::~Vuelos(){
	nomRuta = "";
	fecha = "";
	horaSalida = 0;
	horaLlegada = 0;
	aereoSalida = "";
	aereoLlegada = "";
	piloto = "";
}
