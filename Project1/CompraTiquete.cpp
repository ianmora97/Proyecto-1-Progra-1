#include "CompraTiquete.h"
CompraTiquete::CompraTiquete(): cant(0), tam(5500){
	tiquete = new Tiquete*[tam];
}
void CompraTiquete::col(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }
void CompraTiquete::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void CompraTiquete::ingresar(Vuelos *v) {
	system("cls");
	int tamAvion = v->devuelveAvion().getCantPasajeros();
	int colum = v->devuelveAvion().getColumnas();
	int cantAvion = v->devuelveAvion().getCan();
	cout << "Cuantos boletos desea comprar?";
	bool cicloCantBoletos = true;
	int cantBoletos;
	while (cicloCantBoletos == true) {
		col(13); cout << " > ";
		if (!(cin >> cantBoletos)) {
			col(12);
			cerr << "Error!\n";
			col(15);
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (cantBoletos > 0 && cantBoletos <= tamAvion) {
			cin.clear();
			cin.ignore(1024, '\n');
			cicloCantBoletos = false;
		}
		else {
			col(12);
			cerr << "Error!\n";
			col(15);
			cin.clear();
			cin.ignore(1024, '\n');
		}
		col(15);
	}
	for (int i = 0; i < cantBoletos; i++) {
		system("cls");
		string nombre, id;
		col(10);
		cout << "\t[Digitar los datos de la persona]\n";
		col(11);
		cout << "\n" << endl;
		cout << "\t--------------------------\n";
		col(15);
		cout << "\tDigite su nombre         > ";
		getline(cin, nombre);
		cout << "\tDigite su identificacion > ";
		getline(cin, id);
		bool verifica = true; //ciclo para la verificacion del asiento, si tiene campo
		while (verifica == true) {
			system("cls");
			col(10);
			cout << "\t[Digitar el asiento]\n" << endl;
			col(15);
			v->devuelveAvion().imprimeAsientos();
			char fila;
			int columna;
			cout << "\n\nDigite la fila del asiento (Letra / ";
			col(14);
			cout << "A B C D...";
			col(15);
			cout << ") ";
			gotoxy(((v->devuelveAvion().getColumnas()) * 3) + 3, (v->devuelveAvion().getFilas() + 6));
			col(224);
			cout << char(186);
			col(15);
			bool cicloSelecFila = true;
			while (cicloSelecFila == true) {
				gotoxy(47, (v->devuelveAvion().getFilas() + 8)); cout << "> ";
				if (!(cin >> fila)) {
					col(12);
					gotoxy(47, (v->devuelveAvion().getFilas() + 8)); cerr << "Digite una letra!";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					gotoxy(47, (v->devuelveAvion().getFilas() + 8)); cout << "                                      ";
				}
				else {
					if (v->devuelveAvion().revisaValor(fila, tamAvion) == 1) {
						cicloSelecFila = false;
					}
					else {
						col(12);
						gotoxy(47, (v->devuelveAvion().getFilas() + 8)); cerr << "Digite una letra!";
						col(15);
						cin.clear();
						cin.ignore(1024, '\n');
						gotoxy(47, (v->devuelveAvion().getFilas() + 8)); cout << "                                      ";
					}
				}
			}
			cout << "\n\nDigite la columna del asiento(Numero /";
			col(11);
			cout << " 1 2 3 4...";
			col(15);
			cout << ") ";
			gotoxy(((v->devuelveAvion().getColumnas()) * 3) + 3, (v->devuelveAvion().getFilas() + 6));
			col(15);
			cout << " ";
			gotoxy(((v->devuelveAvion().getColumnas()) * 3) + 3, 2);
			col(176);
			cout << "<";
			col(15);
			bool cicloSelecNum = true;
			while (cicloSelecNum == true) {
				gotoxy(51, (v->devuelveAvion().getFilas() + 11)); cout << "> ";
				if (!(cin >> columna)) {
					col(12);
					gotoxy(51, (v->devuelveAvion().getFilas() + 11)); cerr << "Digite una numero!";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					gotoxy(51, (v->devuelveAvion().getFilas() + 11)); cout << "                                ";
				}
				else {
					if (columna > 0 && columna <= colum) {
						cicloSelecNum = false;
					}
					else {
						col(12);
						gotoxy(51, (v->devuelveAvion().getFilas() + 11)); cerr << "Digite una numero!";
						col(15);
						cin.clear();
						cin.ignore(1024, '\n');
						gotoxy(51, (v->devuelveAvion().getFilas() + 11)); cout << "                                ";
					}
				}
			}
			gotoxy(((v->devuelveAvion().getColumnas()) * 3) + 3, 2);
			col(15);
			cout << " ";
			stringstream f1;
			f1 << fila;
			string f2 = f1.str();
			f2 = toupper(f2[0]);
			stringstream s1;
			s1 << f2 << columna;
			string as = s1.str();
			Persona *persona = new Persona(nombre, id, as);
			gotoxy(0, (v->devuelveAvion().getFilas() + 12));
			if (v->devuelveAvion().verifica(fila, columna) == true) {
				v->devuelveAvion().insertarPersona(persona, fila, columna);
				system("cls");
				tiquete[cant] = new Tiquete(v,persona,as);
				tiquete[cant]->toString();
				cant++;

				verifica = false;
			}
			else {
				col(12);
				cout << "El campo esta lleno, seleccione otro asiento!";
				Sleep(1000);
				col(15);
				verifica = true;
			}

		}
	}
}
int CompraTiquete::menu() {
	system("cls");
	col(15);
	cout << endl << endl << endl;
	cout << "\t\t\t\t" << char(201);
	for (int i = 0; i < 30; i++) { cout << char(205); } //imprime una linea de =
	cout << char(187);
	cout << "\n\t\t\t\t" << char(186);
	col(11);
	cout << "     Gestion de Flotas        ";
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
	int opc;
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
void CompraTiquete::visualizar() {
	for (int i = 0; i < cant; i++) {
		tiquete[i]->toString();
		cout << endl;
	}
}
CompraTiquete::~CompraTiquete()
{
}
