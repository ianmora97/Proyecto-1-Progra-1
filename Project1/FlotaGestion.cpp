#include "FlotaGestion.h"
FlotaGestion::FlotaGestion() {
	cant = 0;
	tam = 30;
	plane = new Avion*[30];
}
void FlotaGestion::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void FlotaGestion::revisarAdmin() {
	system("cls");
	col(15);
	string pass;
	bool ciclo = true;
	while (ciclo) {
		cout << "\n\n\n";
		cout << "\t\t\t" << char(201);
		for (int i = 0; i < 30; i++) { cout << char(205); } //imprime una linea de =
		cout << char(187)<<endl;
		cout << "\t\t\t" << char(186) << "Usuario: Administrador        " << char(186) << endl;
		cout << "\t\t\t" << char(186) << "Clave  :                      " << char(186) << endl;
		cout << "\t\t\t" << char(200);
		for (int i = 0; i < 30; i++) { cout << char(205); }
		cout << char(188) << endl;
		col(17);
		gotoxy(34,5);
		cin>>pass;
		col(15);
		if (pass != clave) {
			col(12);
			cerr << "\n\n\t\t\t  Clave Incorrecta!";
			col(15);
			cin.clear();
			cin.ignore(1024, '\n');
			Sleep(1000);
			system("cls");
			ciclo = true;
		}
		else {
			col(10);
			cout << "\n\n\t\t\t  Clave Correcta!";
			col(15);
			Sleep(1000);
			system("cls");
			ciclo = false;
		}
	}
}
void FlotaGestion::col(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }
int FlotaGestion::getOpc(){return opc;}
int FlotaGestion::getCant() {return cant;}
void FlotaGestion::ingresarAvion(Avion *a) {
	if (cant < tam) {
		plane[cant] = a;
		cant++;
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
	col(14);
	cout << "\t\t/\\___________" <<endl;
	cout << "\t\t|_____/ /____)" << endl;
	cout << "\t\t      |/" << endl<<endl;
	col(15);
	cout << "La empresa tiene: " << cant;
	cant > 1 ? cout << " aviones " << endl : cout << " avion " << endl;

	for (int i = 0; i < cant; i++) {
		cout << "-------------------------" << endl;
		col(11);
		cout << "Avion: " << i+1 << endl << endl;
		col(15);
		cout<<plane[i]->toString()<<endl;
	}
	cout << endl;
	system("PAUSE");
}
void FlotaGestion::toString() {
	cout << "----------------------\n";
	for (int i = 0; i < cant; i++) {

			col(11);
			cout << "Avion: " << i + 1 << endl << endl;
			col(15);
			cout << plane[i]->toString() << endl;
		
	}
}
void FlotaGestion::eliminar() {
	system("cls");
	col(10);
	cout << "\t\t(Eliminar Aviones)\n\n";
	col(15);
	if (cant != 0) { //si hay aviones 
		cout << "Cual avion desea eliminar?\n";
		for (int i = 0; i < cant; i++) { 
			col(10);
			cout << "[" << i + 1 << "]";
			col(15);
			cout << plane[i]->getMarca() << " " << plane[i]->getModelo() << endl;
		}
		int eliAv;
		bool cic = true;
		//Verificacion
		while (cic) {
			cout << "> ";
			if (!(cin >> eliAv)) {
				col(12);
				cerr << "Error! Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
				cic = true;
			}
			else {
				if (eliAv > 0 && eliAv <= cant ) {
					cic = false;
				}
				else {
					col(12);
					cerr << "Error! Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					cic = true;
				}
			}
		}
		int opcA = eliAv - 1;
		if (opcA == (cant-1)) {
			cant--;
			col(10);
			cout << "Se ha eliminado un avion Correctamente!\n";
			col(15);
		}
		else {
			plane[opcA] = plane[cant - 1];
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
void FlotaGestion::imprimeMenu() {
	system("cls");
	col(11);
	cout << "\t\tMenu";
	col(10);
	cout << "\t\t\t\t\t[Gestion de Flota]\n";
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
void FlotaGestion::modificar() {
	system("cls");
	col(10);
	cout << "\t\t(Modificar Aviones)\n\n";
	col(15);
	if (cant != 0) {
		cout << "Que avion desea modificar?\n";
		for (int i = 0; i < cant; i++) {
			col(10);
			cout << "\t[" << i + 1 << "] ";
			col(15);
			cout << plane[i]->getMarca() << " " << plane[i]->getModelo() << endl;
		}
		int opcAvion;
		bool opcAvionCiclo = true;
		while (opcAvionCiclo) { //valida que haya ingresado bien los datos y que este en el rango de numeros
			cout << " \n\t> ";
			col(10);
			if (!(cin >> opcAvion)) {
				col(12);
				cerr << "Error! Digite numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opcAvion > 0 && opcAvion <= (cant)) {
					opcAvionCiclo = false;
				}
				else {
					col(12);
					cerr << "Error! Digite numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					opcAvionCiclo = true;
				}
			}
			col(15);
		}
		int opcA = opcAvion - 1;
		cout << "Que desea modificar?\n";
		col(10);
		cout << "\t[1]";
		col(15);
		cout<< " A" << char(164) << "o\n";
		col(10);
		cout << "\t[2]";
		col(15);
		cout<< " Modelo\n";
		col(10);
		cout << "\t[3]";
		col(15);
		cout<< " Marca\n";
		int opc;
		bool c = true;
		while (c) {
			cout << "\t> ";
			col(10);
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
					cerr << "Error! Digite numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					c = true;
				}
			}
			col(15);
		}
		int an = 0;
		string mode = " ";
		string mar = " ";
		bool ciAn = true;
		system("cls");
		switch (opc) {
		case 1:
			col(10);
			cout << "\t\t(A" << char(164) << "o)\n\n";
			col(15);
			cout << "El a"<<char(164)<<"o del avion "<<plane[opcA]->getMarca()<<" "<<plane[opcA]->getModelo()<<" es: " << plane[opcA]->getAnnio() << endl;
			cout << "Digite un nuevo a" << char(164) << "o\n ";
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
			plane[opcA]->setAnnio(an);
			col(10);
			cout << "Cambio relizado correctamente!\n";
			col(15);
			break;
		case 2:
			col(10);
			cout << "\t\t(Modelo)\n\n";
			col(15);
			cout << "El modelo del avion " << plane[opcA]->getMarca() << " " << plane[opcA]->getModelo() << " es: " << plane[opcA]->getModelo() << endl;
			cout << "Digite un nuevo modelo\n> ";
			cin.ignore();
			getline(cin,mode);
			plane[opcA]->setModelo(mode);
			col(10);
			cout << "Cambio relizado correctamente!\n";
			col(15);
			break;
		case 3:
			col(10);
			cout << "\t\t(Marca)\n\n";
			col(15);
			cout << "La marca del avion " << plane[opcA]->getMarca() << " " << plane[opcA]->getModelo() << " es: " << plane[opcA]->getMarca() << endl;
			cout << "Digite la nueva marca\n>";
			cin.ignore();
			getline(cin,mar);
			plane[opcA]->setMarca(mar);
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
	col(10);
	cout << "Se ha destruido los aviones!"<<endl;
	col(15);
}
