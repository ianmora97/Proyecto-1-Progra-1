#include "FlotaGestion.h"
FlotaGestion::FlotaGestion() {
	cant = 0;
	tam = 30;
	plane = new Avion*[30];
	for (int i = 0; i < tam; i++)
		plane[i] = NULL;
}
void FlotaGestion::revisarAdmin() {
	system("cls");
	col(15);
	string pass;
	bool ciclo = true;
	while (ciclo) {
		cout << "\n\n\n\t\t\tDigite su clave > ";
		col(17);
		cin >> pass;
		col(15);
		if (pass != clave) {
			col(12);
			cerr << "Error!\nClave Incorrecta! Digite nuevamente!\n";
			col(15);
			cin.clear();
			cin.ignore(1024, '\n');
			ciclo = true;
		}
		else {
			system("cls");
			col(10);
			cout << "\n\t\t\t\t";
			cout << "Clave Correcta!";
			col(13);
			cout << "\n\n\n\t\t\t";
			cout << "Bienvenido a la Gestion de Flota!\n";
			for (int i = 0; i < 2; i++) {
				Sleep(1000);
			}
			system("cls");
			col(15);
			ciclo = false;
		}
	}
}
void FlotaGestion::col(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }
int FlotaGestion::getOpc(){return opc;}
void FlotaGestion::ingresarAvion(Avion *a) {
	if (cant < tam) {
		plane[cant] = a;
		cant++;
		col(10);
		cout << "Avion ingresado Correctamente!\n";
		col(15);
	}
	else {
		col(12);
		cerr << "\nNo hay espacio para mas aviones!\n";
		col(15);
	}
}
void FlotaGestion::visualizarAviones() {
	system("cls");
	col(10);
	cout << "\t\t(Visualizar Aviones)\n\n";
	col(15);
	cout << "/\\___________" << endl;
	cout << "|_____/ /____)" << endl;
	cout << "      |/" << endl << endl;

	cout << "La empresa tiene: " << cant;
	cant > 1 ? cout << " aviones " : cout << " avion ";
	cout << "en su empresa." << endl << endl;

	for (int i = 0; i < cant; i++) {
		cout << "-------------------------" << endl;
		col(11);
		cout << "Avion: " << i+1 << endl << endl;
		col(15);
		cout<<plane[i]->toString()<<endl;
	}
	cout << endl;
}
void FlotaGestion::eliminar() {
	system("cls");
	col(10);
	cout << "\t\t(Eliminar Aviones)\n\n";
	col(15);
	if (cant != 0) { //si hay aviones 
		cout << "Cual avion desea eliminar?\n";
		for (int i = 0; i < cant; i++) { cout << "[" << i << "]" << plane[i]->getId() << endl; }
		int eliAv;
		bool cic = true;
		//Verificacion
		while (cic) {
			cout << ">";
			if (!(cin >> eliAv)) {
				col(12);
				cerr << "Error! Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
				cic = true;
			}
			else {
				if (eliAv <= cant && eliAv >= 0) {
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
		if (eliAv == cant) {
			cant--;
		}
		else {
			//cout << "Eli: " << eliAv << " cant: " << cant << endl;
			plane[eliAv] = plane[cant - 1];
			cant--;
			col(10);
			cout << "Se ha eliminado un avion Correctamente!\n";
			col(15);
		}
	}
	else {
		col(12);
		cout << "No hay aviones para eliminar!\n";
		col(15);
	}
}
void FlotaGestion::menu() {
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
}
void FlotaGestion::imprimeMenu() {
	system("cls");
	col(11);
	cout << "\t\tMenu";
	col(10);
	cout << "\t\t\t\t\t[Gestion de Flota]\n";
	col(15);
	for (int i = 0; i < 40; i++) { cout << "-"; }
	cout << "\n\n";
	cout << "\t[1] Insertar\n";
	cout << "\t[2] Visualizar\n";
	cout << "\t[3] Modificar\n";
	cout << "\t[4] Eliminar\n";
	cout << "\t[0] Volver al menu principal\n";
}
void FlotaGestion::modificar() {
	system("cls");
	col(10);
	cout << "\t\t(Modificar Aviones)\n\n";
	col(15);
	if (cant != 0) {
		cout << "Que avion desea modificar?\n";
		for (int i = 0; i < cant; i++) {
			cout << "[" << i << "] " << plane[i]->getId() << endl;
		}
		int opcAvion;
		bool opcAvionCiclo = true;
		while (opcAvionCiclo) { //valida que haya ingresado bien los datos y que este en el rango de numeros
			cout << ">";
			if (!(cin >> opcAvion)) {
				col(12);
				cerr << "Error! Digite numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opcAvion < cant && opcAvion >= 0) {
					opcAvionCiclo = false;
				}
				else {
					col(12);
					cerr << "Error! Digite numero!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					opcAvionCiclo = true;
				}
			}
		}
		cout << "Que desea modificar?\n";
		cout << "[1] Annio\n";
		cout << "[2] Modelo\n";
		cout << "[3] Marca\n";
		int opc;
		bool c = true;
		while (c) {
			cout << ">";
			if (!(cin >> opc)) {
				col(12);
				cerr << "Error! Digite numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opc >= 0 && opc <= 3) {
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
		int an = 0;
		string mode = " ";
		string mar = " ";
		bool ciAn = true;
		system("cls");
		switch (opc) {
		case 1:
			col(10);
			cout << "\t\t(Annio)\n\n";
			col(15);
			cout << "El annio del avion es: " << plane[opcAvion]->getAnnio() << endl;
			cout << "Digite un nuevo annio\n ";
			while (ciAn) {
				cout << ">";
				if (!(cin >> an)) {
					col(12);
					cerr << "Error! Digite un numero!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					ciAn = true;
				}
				else { ciAn = false; }
			}
			plane[opcAvion]->setAnnio(an);
			col(10);
			cout << "Cambio relizado correctamente!\n";
			col(15);
			break;
		case 2:
			col(10);
			cout << "\t\t(Modelo)\n\n";
			col(15);
			cout << "El modelo del avion es: " << plane[opcAvion]->getModelo() << endl;
			cout << "Digite un nuevo modelo\n> ";
			cin >> mode;
			plane[opcAvion]->setModelo(mode);
			col(10);
			cout << "Cambio relizado correctamente!\n";
			col(15);
			break;
		case 3:
			col(10);
			cout << "\t\t(Marca)\n\n";
			col(15);
			cout << "La marca del avion es: " << plane[opcAvion]->getMarca() << endl;
			cout << "Digite la nueva marca\n>";
			cin >> mar;
			plane[opcAvion]->setMarca(mar);
			col(10);
			cout << "Cambio relizado correctamente!\n";
			col(15);
			break;
		default:
			col(10);
			cout << "Ha digitado mal un numero!\nComience de nuevo!\n";
			col(15);
			break;
		}
	}
	else {
		col(12);
		cout << "No hay aviones para modificar!\n";
		col(15);
	}
}
Avion FlotaGestion::devuelve(int i) {return *plane[i];}
FlotaGestion::~FlotaGestion() { 
	for (int i = 0; i < cant; i++)
		delete plane[i];
	delete[] plane;
	tam = 0;
	cant = 0; 
}
