#include "Vuelos.h"
Vuelos::Vuelos() : nomRuta(""), fecha(""), horaSalida(0), horaLlegada(0), aereoSalida(""), aereoLlegada(""), piloto("") {}
Vuelos::Vuelos(string n, string f , int s, int l, string as, string al, string p, Avion av, Rutas ru) : nomRuta(n), fecha(f), horaSalida(s), horaLlegada(l), aereoSalida(as), aereoLlegada(al), piloto(p), avion(av), ruta(ru) {}
Vuelos::Vuelos(const Vuelos *v) : nomRuta(v->nomRuta), fecha(v->fecha), horaSalida(v->horaSalida), horaLlegada(v->horaLlegada), aereoSalida(v->aereoSalida), aereoLlegada(v->aereoLlegada), piloto(v->piloto), avion(v->avion), ruta(v->ruta) {}
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
	cout << endl << "\tDigite el a"<<char(164)<<"o: > ";
	cin >> annio;
	cout << "\n\tSeleccione el numero del mes:\n";
	col(11);
	cout << "\t[1] ";
	col(15);
	cout << "Enero\t\t\t";
	col(11);
	cout << "[7]  ";
	col(15);
	cout << "Julio\n";
	col(11);
	cout << "\t[2] ";
	col(15);
	cout << "Febrero\t\t\t";
	col(11);
	cout << "[8]  ";
	col(15);
	cout << "Agosto\n";
	col(11);
	cout << "\t[3] ";
	col(15);
	cout << "Marzo\t\t\t";
	col(11);
	cout << "[9]  ";
	col(15);
	cout << "Septiembre\n";
	col(11);
	cout << "\t[4] ";
	col(15);
	cout << "Abril\t\t\t";
	col(11);
	cout << "[10] ";
	col(15);
	cout << "Octubre\n";
	col(11);
	cout << "\t[5] ";
	col(15);
	cout << "Mayo\t\t\t";
	col(11);
	cout << "[11] ";
	col(15);
	cout << "Noviembre\n";
	col(11);
	cout << "\t[6] ";
	col(15);
	cout << "Junio\t\t\t";
	col(11);
	cout << "[12] ";
	col(15);
	cout << "Diciembre\n\n";
	col(15);
	while (cicloMes) {
		cout << "\t> ";
		col(11);
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
		col(15);
	}
	cout << endl;
	switch (mes) {
	case 1:
		mesL = "ENERO";
		cantidadDias = 31;
		cout << "\t\t\t"<<mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i==21 || i==28) {
				cout << endl<<"\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
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
			col(15);
		}
		break;
	case 2:
		mesL = "FEBRERO";
		cantidadDias = 28;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21) {
				cout << endl<<"\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
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
			col(15);
		}
		break;
	case 3:
		mesL = "MARZO";
		cantidadDias = 31;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl<<"\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
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
			col(15);
		}
		break;
	case 4:
		mesL = "ABRIL";
		cantidadDias = 30;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl<<"\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
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
			col(15);
		}
		break;
	case 5:
		mesL = "MAYO";
		cantidadDias = 31;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
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
			col(15);
		}
		break;
	case 6:
		mesL = "JUNIO";
		cantidadDias = 30;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
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
			col(15);
		}
		break;
	case 7:
		mesL = "JULIO";
		cantidadDias = 31;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
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
			col(15);
		}
		break;
	case 8:
		mesL = "AGOSTO";
		cantidadDias = 31;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
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
			col(15);
		}
		break;
	case 9:
		mesL = "SEPTIEMBRE";
		cantidadDias = 30;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
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
			col(15);
		}
		break;
	case 10:
		mesL = "OCTUBRE";
		cantidadDias = 31;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
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
			col(15);
		}
		break;
	case 11:
		mesL = "NOVIEMBRE";
		cantidadDias = 30;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
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
			col(15);
		}
		break;
	case 12:
		mesL = "DICIEMBRE";
		cantidadDias = 31;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
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
			col(15);
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
void Vuelos::setNomRuta(string n) { nomRuta = n; }
void Vuelos::setFecha(string f) { fecha = f; }
void Vuelos::setHoraSalida(int hs) { horaSalida = hs; }
void Vuelos::setHoraLlegada(int hl) { horaLlegada = hl; }
void Vuelos::setAereoSalida(string as) { aereoSalida = as; }
void Vuelos::setAereoLlegada(string al) { aereoLlegada = al; }
void Vuelos::setPiloto(string p) { piloto = p; }
string Vuelos::toString() {
	stringstream p;
	p << "Nombre de la ruta       : " << nomRuta << endl;
	p << "Fecha                   : " << fecha << endl;
	p << "Hora de Salida          : " << horaSalida <<":00"<<endl;
	p << "Hora de llegada         : " << horaLlegada << ":00"<<endl;
	p << "Aereopuerto de Salida   : "<<aereoSalida<<endl;
	p << "Aereopuerto de Llegada  : "<<aereoLlegada<<endl;
	p << "Nombre del Piloto       : "<<piloto<<endl;
	return p.str();
}
void Vuelos::insertaAvion(Avion a) {avion = a;}
Avion Vuelos::devuelveAvion() { return avion; }
Rutas Vuelos::devuelveRuta() { return ruta; }
Vuelos::~Vuelos(){
	nomRuta = "";
	fecha = "";
	horaSalida = 0;
	horaLlegada = 0;
	aereoSalida = "";
	aereoLlegada = "";
	piloto = "";
}
