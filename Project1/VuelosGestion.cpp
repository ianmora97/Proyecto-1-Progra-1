#include "VuelosGestion.h"
VuelosGestion::VuelosGestion() {
	vuelo = new  Vuelos[100]; //Declara hasta 100 vuelos (no especifica cuantos vuelos se pueden hacer)
	cant = 0;
	tam = 100;
}
void VuelosGestion::col(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }
void VuelosGestion::insertarVuelo(Vuelos &v) {
	if (cant < tam) {
		vuelo[cant] = v;
		col(10);
		cout << "Un vuelo ha sido creado!\n";
		col(15);
	}
	else {
		col(12);
		cout << "No hay campo para insertar vuelos!\n";
		col(15);
	}
}
void VuelosGestion::visualizar() {
	system("cls");
	col(10);
	cout << "\t\t(Visualizar Vuelos)\n\n";
	col(15);

	cout << "La empresa tiene: " << cant;
	cant > 1 ? cout << " vuelos " : cout << " vuelo ";
	cout << "en su empresa." << endl << endl;

	for (int i = 0; i < cant; i++) {
		cout << "-------------------------" << endl;
		col(11);
		cout << "Vuelo: " << i + 1 << endl << endl;
		col(15);
		cout << vuelo[i].toString() << endl;
	}
	cout << endl;
}
void VuelosGestion::modificar(){
	system("cls");
	col(10);
	cout << "\t\t(Modificar Vuelos)\n\n";
	col(15);
	if (cant != 0) {
		cout << "Que vuelo desea modificar?\n";
		for (int i = 0; i < cant; i++) {
			cout << "[" << i << "] " << vuelo[i].getNomRuta() << endl;
		}
		int opcVuelo;
		bool opcVueloCiclo = true;
		while (opcVueloCiclo) { //valida que haya ingresado bien los datos y que este en el rango de numeros
			cout << ">";
			if (!(cin >> opcVuelo)) {
				col(12);
				cerr << "Error! Digite numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opcVuelo < cant && opcVuelo >= 0) {
					opcVueloCiclo = false;
				}
				else {
					col(12);
					cerr << "Error! Digite numero!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					opcVueloCiclo = true;
				}
			}
		}
		cout << "Que desea modificar?\n\n";
		cout << "[1] Fecha\n";
		cout << "[2] Hora de Salida\n";
		cout << "[3] Hora de Llegada\n";
		cout << "[4] Aereopuerto de Salida\n";
		cout << "[5] Aereopuerto de Llegada\n";
		cout << "[6] Nombre del piloto\n";
		cout << "[7] Cambiar de avion\n";
		cout << "(Si desea modificar el nombre del vuelo debe de hacerlo desde el [Modulo Gestion de Ruta])\n";
		cout << "(Digite 0 para salir!)\n";
		int opcModifica;
		bool c = true;
		while (c) {
			cout << ">";
			if (!(cin >> opcModifica)) {
				col(12);
				cerr << "Error! Digite numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opcModifica >= 0 && opcModifica < 8) {
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
		}
		int opcavion;
		string fecha_temp;
		int horaSalida_temp;
		int horaLlegada_temp;
		string aereoSalida_temp;
		string aereoLlegada_temp;
		string piloto_temp;
		bool ciclo_validaciones = true;
		system("cls");
		switch (opcModifica){
		case 1:
			col(10);
			cout << "\t\t(Fecha)\n\n";
			col(15);
			cout << "La fecha del Vuelo es: "<<vuelo[opcVuelo].getFecha()<<endl;
			vuelo[opcVuelo].muestraFecha();
			cout << endl;
			cout << "Digite la nueva Fecha: >";
			cin >> fecha_temp;
			vuelo[opcVuelo].setFecha(fecha_temp);
			col(10);
			cout << "Cambio relizado correctamente!\n";
			col(15);
			break;
		case 2:
			col(10);
			cout << "\t\t(Hora de Salida)\n\n";
			col(15);
			cout << "La hora de salida del Vuelo es: " << vuelo[opcVuelo].getHoraSalida() << endl;
			cout << "Digite la nueva hora de salida: >";
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
			vuelo[opcVuelo].setHoraSalida(horaSalida_temp);
			col(10);
			cout << "Cambio relizado correctamente!\n";
			col(15);
			break;
		case 3:
			col(10);
			cout << "\t\t(Hora de Llegada)\n\n";
			col(15);
			cout << "La hora de Llegada del Vuelo es: " << vuelo[opcVuelo].getHoraLlegada() << endl;
			cout << "Digite la nueva hora de llegada: >";
			while (ciclo_validaciones) {
				cout << ">";
				if (!(cin >> horaLlegada_temp)) {
					col(12);
					cerr << "Error! Digite un numero!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					ciclo_validaciones = true;
				}
				else { ciclo_validaciones = false; }
			}
			vuelo[opcVuelo].setHoraLlegada(horaLlegada_temp);
			col(10);
			cout << "Cambio relizado correctamente!\n";
			col(15);
			break;
		case 4:
			col(10);
			cout << "\t\t(Aereopuerto de Salida)\n\n";
			col(15);
			cout << "El aereopuerto de salida del Vuelo es: " << vuelo[opcVuelo].getAereoSalida() << endl;
			cout << endl;
			cout << "Digite el nuevo aereopuerto de salida: >";
			cin.ignore();
			getline(cin,aereoSalida_temp);
			vuelo[opcVuelo].setAereoSalida(aereoSalida_temp);
			col(10);
			cout << "Cambio relizado correctamente!\n";
			col(15);
			break;
		case 5:
			col(10);
			cout << "\t\t(Aereopuerto de Llegada)\n\n";
			col(15);
			cout << "El aereopuerto de llegada del Vuelo es: " << vuelo[opcVuelo].getAereoLlegada() << endl;
			cout << endl;
			cout << "Digite el nuevo aereopuerto de llegada: >";
			cin.ignore();
			getline(cin, aereoLlegada_temp);
			vuelo[opcVuelo].setAereoLlegada(aereoLlegada_temp);
			col(10);
			cout << "Cambio relizado correctamente!\n";
			col(15);
			break;
		case 6:
			col(10);
			cout << "\t\t(Nombre del piloto)\n\n";
			col(15);
			cout << "El nombre del piloto del Vuelo es: " << vuelo[opcVuelo].getPiloto() << endl;
			cout << endl;
			cout << "Digite el nuevo nombre del piloto: >";
			cin.ignore();
			getline(cin, piloto_temp);
			vuelo[opcVuelo].setPiloto(piloto_temp);
			col(10);
			cout << "Cambio relizado correctamente!\n";
			col(15);
			break;
		case 7:
			col(10);
			cout << "\t\t(Cambiar el avion)\n\n";
			col(15);
			FlotaGestion *f;
			f->visualizarAviones();
			cout << "Cual avion desea cambiar el vuelo? >";
			cin >> opcavion;
			vuelo[opcVuelo].setAvion(opcavion); //verificar si cambia el avion, si se le da el avion al vuelo
			col(10);
			cout << "Cambio relizado correctamente!\n";
			col(15);
			break;
		default:
			break;
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
		cout << "Cual vuelo desea eliminar?\n";
		for (int i = 0; i < cant; i++) { cout << "[" << i << "]" << vuelo[i].getNomRuta() << endl; }
		int eligeVuelo;
		bool cic = true;
		while (cic) {
			cout << ">";
			if (!(cin >> eligeVuelo)) {
				col(12);
				cerr << "Error! Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
				cic = true;
			}
			else {
				if (eligeVuelo <= cant && eligeVuelo >= 0) {
					cic = false;
				}
				else {
					col(12);
					cerr << "Error! Digite un numero!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					cic = true;
				}
			}
		}
		if (eligeVuelo == cant) {
			cant--;
		}
		else {
			vuelo[eligeVuelo] = vuelo[cant - 1];
			cant--;
			col(10);
			cout << "Se ha eliminado un vuelo Correctamente!\n";
			col(15);
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
	cout << "\t[1] Insertar\n";
	cout << "\t[2] Visualizar\n";
	cout << "\t[3] Modificar\n";
	cout << "\t[4] Eliminar\n";
	cout << "\t[0] Volver al menu principal\n";
}
int VuelosGestion::interfaz(){
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
VuelosGestion::~VuelosGestion() {}
