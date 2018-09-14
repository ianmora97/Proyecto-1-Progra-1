#include "Control.h"
Control::Control(){}
void Control::col(int c){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);}
void Control::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void Control::opciones() {
	Interfaz *i = new Interfaz;
	FlotaGestion *flotaGe = new FlotaGestion;
	RutasGestion *rutaGes = new RutasGestion;
	VuelosGestion *vg = new VuelosGestion;
	Avion *a1 = new Avion(1, 2005, "747", "Boeing", 180, 6, 30);
	Avion *a2 = new Avion(2, 2000, "A340", "Airbus", 100, 4, 25);
	Avion *a3 = new Avion(3, 2015, "182N", "Cessna", 100, 4, 25);
	flotaGe->ingresar(a1);
	flotaGe->ingresar(a2);
	flotaGe->ingresar(a3);
	Rutas *r1 = new Rutas("Costa Rica", "Panama", 1, 1);
	Rutas *r2 = new Rutas("Costa Rica", "España", 17, 1);
	Rutas *r3 = new Rutas("Costa Rica", "Estados Unidos", 3, 1);
	rutaGes->ingresar(r1);
	rutaGes->ingresar(r2);
	rutaGes->ingresar(r3);
	Vuelos *v1 = new Vuelos("COSTA RICA-PANAMA","14,NOVIEMBRE,2018",5,6,"Juan Santamaria","Albrook","Juan Gonzales", *a1,*r1);
	Vuelos *v2 = new Vuelos("COSTA RICA-ESPAÑA", "25,DICIEMBRE,2018", 8, 1, "Juan Santamaria", "Madrid", "Luis Garita", *a2,*r2);
	Vuelos *v3 = new Vuelos("COSTA RICA-ESTADOS UNIDOS", "8,ENERO,2019", 12, 3, "Juan Santamaria", "Orlando, Florida", "Ivannia Flores", *a3,*r3);
	vg->insertar(v1);
	vg->insertar(v2);
	vg->insertar(v3);
	//ciclos
	bool cicloPrincipal=true;
	//----!ciclos
	srand(time(NULL));

	bienvenido();
	while (cicloPrincipal) {
		i->imprime();
		int opc = i->menu();
		if (opc == 1) { // Gestion de Flotas
			flotaGe->revisarAdmin();
			bool cicloOpcion1 = true;
			while (cicloOpcion1) {
				system("cls");
				switch (flotaGe->menu()){
				case 0:
					system("cls");
					col(13);
					cout << "\n\n\n\t\t\t";
					cout << "Saliendo de [Gestion de Flota]\n";
					cout << "\n\t\t";
					for (int i = 0; i < 60; i++) {col(255);cout << " ";Sleep(15);}
					system("cls");
					col(15);
					cicloOpcion1 = false;
					break;
				case 1: flotaGe->ingresar(); break;
				case 2: flotaGe->visualizar(); break;
				case 3: flotaGe->modificar(); break;
				case 4: flotaGe->eliminar(); break;
				default: break;}
				
			}

		}
		else if (opc == 2) {
			system("cls");
			col(13);
			cout << "\n\n\n\t\t\t";
			cout << "Bienvenido a la gestion de Rutas!\n";
			for (int i = 0; i < 2; i++) {Sleep(500);}
			system("cls");
			col(15);
			bool cicloOpcion = true;
			while (cicloOpcion) {
				switch (rutaGes->menu()){
				case 0:
					system("cls");
					col(13);
					cout << "\n\n\n\t\t\t";
					cout << "Saliendo de [Gestion de Rutas]\n";
					cout << "\n\t\t";
					for (int i = 0; i < 60; i++) {col(255);	cout << " ";Sleep(15);}
					col(15);
					cicloOpcion = false;
					break;
				case 1: rutaGes->ingresar(); break;
				case 2: rutaGes->visualizar(); break;
				case 3: rutaGes->modificar(); break;
				case 4: rutaGes->eliminar(); break;
				default: break; }
			}
			
		}
		else if (opc == 3) {
			system("cls");
			col(13);
			cout << "\n\n\n\t\t\t";
			cout << "Bienvenido a la gestion de Vuelos!\n";
			for (int i = 0; i < 2; i++) { Sleep(500);}
			system("cls");
			col(15);
			bool cicloOpcion = true; //ciclo del menu
			while (cicloOpcion == true) {
				system("cls");
				Avion *av; //hace una copia del avion
				Rutas *ruta; //hace una copia de la ruta
				bool cicloSelecRuta = true, cicloSelecAvion = true;
				int canR = rutaGes->getCant();
				int canF = flotaGe->getCant();
				int opcRuta;
				int numRuta;
				int opcAvion;
				int opcAvionm;
				switch (vg->menu()){
				case 0:
					system("cls");
					col(13);
					cout << "\n\n\n\t\t\t";
					cout << "Saliendo de la gestion de Vuelos!\n";
					cout << "\n\t\t";
					for (int i = 0; i < 60; i++) {col(255);cout << " ";Sleep(15);}
					col(15);
					cicloOpcion = false;
					break;
				case 1:
					system("cls");
					cout << "Las rutas disponibles son:\n";
					rutaGes->mostrarRutas(); // visualizar rutas
					cout << "Seleccione una Ruta ";
					while (cicloSelecRuta) {
						cout << "> ";
						if (!(cin >> opcRuta)) {
							col(12);
							cerr << "Digite un numero!\n";
							col(15);
							cin.clear();
							cin.ignore(1024, '\n');
						}
						else {
							if (opcRuta > 0 && opcRuta <= rutaGes->getCant()) {
								cicloSelecRuta = false;
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
					numRuta = opcRuta - 1; // se le resta uno por la posicion del vector
					system("cls");
					cout << "\nLos aviones disponibles para asignar una ruta"<< endl;
					flotaGe->toString();
					cout << "\nSeleccione un Avion";
					while (cicloSelecAvion) {
						cout << "> ";
						if (!(cin >> opcAvion)) {
							col(12);
							cerr << "Digite un numero!\n";
							col(15);
							cin.clear();
							cin.ignore(1024, '\n');
						}
						else {
							if (opcAvion > 0 && opcAvion <= rutaGes->getCant()) {
								cicloSelecAvion = false;
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
					opcAvionm = opcAvion - 1;
					av = new Avion(flotaGe->devuelve(opcAvionm));
					ruta = new Rutas(rutaGes->devuele(numRuta));
					vg->insertar(av,ruta,rutaGes->getCant(),flotaGe->getCant(), rutaGes->devuele(numRuta).sumaRuta(), rutaGes->devuele(numRuta).getDuracion());
					break;
				case 2: vg->visualizar(); break;
				case 3: vg->modificar(); break;
				case 4: vg->eliminar(); break;
				default: break;	}
				
			}
		}
		else if (opc == 4) {
			system("cls");
			col(13);
			cout << "\n\n\n\t\t\t";
			cout << "Bienvenido a la Compra de tiquetes!\n";
			for (int i = 0; i < 2; i++) {Sleep(500);}
			if (vg->getCant() != 0) { //si no hay vuelos registrados no puede comprar asientos
				bool espacio = true;
				while (espacio == true) {
					system("cls");
					col(10);
					cout << "\t\t(Compra de Tiquetes)\n\n";
					col(15);
					vg->toString();
					cout << "Seleccione el vuelo deseado";
					int opcVvuelo;
					bool cicloSelecVuelo = true;
					while (cicloSelecVuelo == true) {
						cout << "> ";
						if (!(cin >> opcVvuelo)) {
							col(12);
							cerr << "Digite un numero!\n";
							col(15);
							cin.clear();
							cin.ignore(1024, '\n');
						}
						else {
							if (opcVvuelo > 0 && opcVvuelo <= vg->getCant()) {
								cicloSelecVuelo = false;
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
					int vuelo = opcVvuelo - 1;
					if (vg->devuelveVuelo(vuelo).devuelveAvion().getCan() < vg->devuelveVuelo(vuelo).devuelveAvion().getCantPasajeros()) {
						int precio = rand() % (800 + 150);//metodo para un precio random
						int tamAvion = vg->devuelveVuelo(vuelo).devuelveAvion().getCantPasajeros(); //tamaño del avion seleccionado
						int colum = vg->devuelveVuelo(vuelo).devuelveAvion().getColumnas(); //tamaño de las columnas del avion seleccionado;		
						system("cls");
						//variables locales para el nombre y el id del usuario
						string nombre,id;
						col(10);
						cout << "\t[Digitar los datos de la persona]\n";
						col(11);
						cout << "\n\tAsiento" << endl;
						cout << "\t--------------------------\n";
						col(15);
						cout << "\tDigite su nombre > ";
						cin.ignore();
						getline(cin, nombre);
						cout << "\tDigite su identificacion >";
						getline(cin, id);
						bool verifica = true; //ciclo para la verificacion del asiento, si tiene campo
						while (verifica == true) {
							system("cls");
							col(10);
							cout << "\t[Digitar el asiento]\n" << endl;
							col(15);
							vg->devuelveVuelo(vuelo).devuelveAvion().imprimeAsientos();
							char fila;
							int columna;
							cout << "\n\nDigite la fila del asiento (Letra / ";
							col(14);
							cout << "A B C D...";
							col(15);
							cout << ") ";
							gotoxy(((vg->devuelveVuelo(vuelo).devuelveAvion().getColumnas()) * 3) + 3, (vg->devuelveVuelo(vuelo).devuelveAvion().getFilas() + 6));
							col(224);
							cout << char(186);
							col(15);
							bool cicloSelecFila = true;
							while (cicloSelecFila == true) {
								gotoxy(47, (vg->devuelveVuelo(vuelo).devuelveAvion().getFilas() + 8));cout << "> ";
								if (!(cin >> fila)) {
									col(12);
									gotoxy(47, (vg->devuelveVuelo(vuelo).devuelveAvion().getFilas() + 8)); cerr << "Digite una letra!";
									col(15);
									cin.clear();
									cin.ignore(1024, '\n');
									gotoxy(47, (vg->devuelveVuelo(vuelo).devuelveAvion().getFilas() + 8)); cout << "                                      ";
								}
								else {
									if (vg->revisaValor(fila, tamAvion) == 1) {
										cicloSelecFila = false;
									}
									else {
										col(12);
										gotoxy(47, (vg->devuelveVuelo(vuelo).devuelveAvion().getFilas() + 8)); cerr << "Digite una letra!";
										col(15);
										cin.clear();
										cin.ignore(1024, '\n');
										gotoxy(47, (vg->devuelveVuelo(vuelo).devuelveAvion().getFilas() + 8)); cout << "                                      ";
									}
								}
							}
							cout << "\n\nDigite la columna del asiento(Numero /";
							col(11);
							cout << " 1 2 3 4...";
							col(15);
							cout << ") ";
							gotoxy(((vg->devuelveVuelo(vuelo).devuelveAvion().getColumnas()) * 3) + 3, (vg->devuelveVuelo(vuelo).devuelveAvion().getFilas() + 6));
							col(15);
							cout << " ";
							gotoxy(((vg->devuelveVuelo(vuelo).devuelveAvion().getColumnas()) * 3) + 3, 2);
							col(176);
							cout << "<";
							col(15);
							bool cicloSelecNum = true;
							while (cicloSelecNum == true) {
								gotoxy(51, (vg->devuelveVuelo(vuelo).devuelveAvion().getFilas() + 11)); cout << "> ";
								if (!(cin >> columna)) {
									col(12);
									gotoxy(51, (vg->devuelveVuelo(vuelo).devuelveAvion().getFilas() + 11)); cerr << "Digite una numero!";
									col(15);
									cin.clear();
									cin.ignore(1024, '\n');
									gotoxy(51, (vg->devuelveVuelo(vuelo).devuelveAvion().getFilas() + 11)); cout << "                                ";
								}
								else {
									if (columna > 0 && columna <= colum) {
										cicloSelecNum = false;
									}
									else {
										col(12);
										gotoxy(51, (vg->devuelveVuelo(vuelo).devuelveAvion().getFilas() + 11)); cerr << "Digite una numero!";
										col(15);
										cin.clear();
										cin.ignore(1024, '\n');
										gotoxy(51, (vg->devuelveVuelo(vuelo).devuelveAvion().getFilas() + 11)); cout << "                                ";
									}
								}
							}
							gotoxy(((vg->devuelveVuelo(vuelo).devuelveAvion().getColumnas()) * 3) + 3, 2);
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
							gotoxy(0, (vg->devuelveVuelo(vuelo).devuelveAvion().getFilas() + 12));
							if (vg->devuelveVuelo(vuelo).devuelveAvion().verifica(fila, columna) == true) {
								vg->devuelveVuelo(vuelo).devuelveAvion().insertarPersona(persona, fila, columna);
								cout << "\n\n\tAsiento: ";
								col(14);
								cout << f2.c_str();
								col(11);
								cout << columna << endl;
								col(15);
								Sleep(800);
								//---------IMPRIME EL TIQUETE--------
								system("cls");
								cout << endl;
								cout << char(201);
								for (int i = 0; i < 60; i++) { cout << char(205); }
								cout << char(187) << endl;
								cout << char(186);
								col(11);
								cout << "\t\t\t   Tiquete:\t\t\t     ";
								col(15);
								cout << char(186) << endl;
								cout << char(186);
								for (int i = 0; i < 60; i++) { cout << "-"; }
								cout << char(186) << endl;
								cout << char(186);
								col(11);
								cout << "\t\t     Datos de la persona:\t\t     ";
								col(15);
								cout << char(186) << endl;
								cout << char(186);
								for (int i = 0; i < 60; i++) { cout << " "; }
								cout << char(186) << endl;
								cout << char(186);
								cout << "  Nombre         : " << persona->getName() << endl;
								cout << char(186);
								cout << "  Identificacion : " << persona->getId() << endl;
								cout << char(186);
								cout << "  Asiento        : " << persona->getAsiento() << endl;
								cout << char(186);
								for (int i = 0; i < 60; i++) { cout << "-"; }
								cout << char(186) << endl;
								cout << char(186);
								col(11);
								cout << "\t\t            Vuelo:\t\t             ";
								col(15);
								cout << char(186) << endl;
								cout << char(186);
								for (int i = 0; i < 60; i++) { cout << " "; }
								cout << char(186) << endl;
								cout << char(186);
								cout << "  Vuelo               : " << vg->devuelveVuelo(vuelo).getNomRuta() << endl;
								cout << char(186);
								cout << "  Fecha               : " << vg->devuelveVuelo(vuelo).getFecha() << endl;
								cout << char(186);
								cout << "  Aereopuerto salida  : " << vg->devuelveVuelo(vuelo).getAereoSalida() << endl;
								cout << char(186);
								cout << "  Aereopuerto llegada : " << vg->devuelveVuelo(vuelo).getAereoLlegada() << endl;
								cout << char(186);
								cout << "  Hora salida         : " << vg->devuelveVuelo(vuelo).getHoraSalida() << ":00" << endl;
								cout << char(186);
								cout << "  Hora llegada        : " << vg->devuelveVuelo(vuelo).getHoraLlegada() << ":00" << endl;
								cout << char(186);
								cout << "  Piloto              : " << vg->devuelveVuelo(vuelo).getPiloto() << endl;
								cout << char(186);
								for (int i = 0; i < 60; i++) { cout << "-"; }
								cout << char(186) << endl;
								cout << char(186);
								col(11);
								cout << "\t\t            Avion:\t\t             ";
								col(15);
								cout << char(186) << endl;
								cout << char(186);
								for (int i = 0; i < 60; i++) { cout << " "; }
								cout << char(186) << endl;
								cout << char(186);
								cout << "  Identificacion      : " << vg->devuelveVuelo(vuelo).devuelveAvion().getId() << endl;
								cout << char(186);
								cout << "  A" << char(164) << "o                 : " << vg->devuelveVuelo(vuelo).devuelveAvion().getAnnio() << endl;
								cout << char(186);
								cout << "  Marca               : " << vg->devuelveVuelo(vuelo).devuelveAvion().getMarca() << endl;
								cout << char(186);
								cout << "  Modelo              : " << vg->devuelveVuelo(vuelo).devuelveAvion().getModelo() << endl;
								cout << char(186);
								for (int i = 0; i < 60; i++) { cout << "-"; }
								cout << char(186) << endl;
								cout << char(186);
								col(11);
								cout << "\t\t            Precio:\t\t             ";
								col(15);
								cout << char(186) << endl;
								cout << char(186);
								for (int i = 0; i < 60; i++) { cout << " "; }
								cout << char(186) << endl;
								cout << char(186);
								cout << "  Precio del tiquete  :    $" << precio << endl;
								col(15);
								cout << char(200);
								for (int i = 0; i < 60; i++) { cout << char(205); }
								cout << char(188) << endl;
								//laterales derecha
								gotoxy(61, 2); cout << char(186);
								gotoxy(61, 4); cout << char(186);
								gotoxy(61, 5); cout << char(186);
								gotoxy(61, 6); cout << char(186);
								gotoxy(61, 7); cout << char(186);
								gotoxy(61, 8); cout << char(186);
								gotoxy(61, 11); cout << char(186);
								gotoxy(61, 12); cout << char(186);
								gotoxy(61, 13); cout << char(186);
								gotoxy(61, 14); cout << char(186);
								gotoxy(61, 15); cout << char(186);
								gotoxy(61, 16); cout << char(186);
								gotoxy(61, 17); cout << char(186);
								gotoxy(61, 18); cout << char(186);
								gotoxy(61, 21); cout << char(186);
								gotoxy(61, 22); cout << char(186);
								gotoxy(61, 23); cout << char(186);
								gotoxy(61, 24); cout << char(186);
								gotoxy(61, 25); cout << char(186);
								gotoxy(61, 28); cout << char(186);
								gotoxy(61, 29); cout << char(186);

								//---------!IMPRIME EL TIQUETE--------
								gotoxy(61, 32);
								cout << endl;
								vg->devuelveVuelo(vuelo).devuelveAvion().imprimeAsientos();
								cout << endl << endl;

								gotoxy(65, 2);
								cin.ignore();
								cin.get();
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
						espacio = false;
					}
					else {
						col(12);
						cout << "No hay asientos disponibles en el vuelo seleccionado!\n";
						cout << "Digite otro vuelo!\n";
						col(15);
						system("PAUSE");
					}
				}
			}
			else {
				col(12);
				cout << "No hay Vuelos registrados todavia!\n";
				col(15);
				system("PAUSE");
			}
		}
		else if (opc == 5) {
			/*
				NO REVISAR!!
				SOLO PARA VERIFICAR METODOS
			*/
			system("cls");
			Persona *p = new Persona("Aqui ","hay","una persona");
			char c;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 25; j++) {
					switch (i){
					case 0:
						c = 'A'; break;
					case 1:
						c = 'B'; break;
					case 2:
						c = 'C'; break;
					case 3:
						c = 'D'; break;
					default:
						break;
					}
					vg->devuelveVuelo(2).devuelveAvion().insertarPersona(p, c, j);
					vg->devuelveVuelo(2).devuelveAvion().imprimeAsientos();
					system("cls");
				}
			}
			vg->devuelveVuelo(2).devuelveAvion().imprimeAsientos();
			cout << endl;
			system("PAUSE");
		} //para revisar metodos nada mas (NO REVISAR)
		else {
			delete flotaGe;
			delete rutaGes;
			delete vg;
			cicloPrincipal = false; 
		}
	}
	hastaLuego();
}
void Control::bienvenido(){
	for (int i = 0; i < 5; i++) { cout << "\n"; }
	for (int i = 0; i < 6; i++) { cout << "\t"; }
	col(11);
	cout << "Bienvenido/a!\n\n";
	for (int i = 0; i < 6; i++) { cout << "\t"; }
	col(15);
	cout << "Co-Airlines\n";
	col(13);
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << " __________     __________  \n";
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << "|    ______|   |   ____   | \n";
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << "|   |          |  |____|  |  \n";
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << "|   |______    |   ____   | \n";
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << "|__________|   |__|    |__|\n";
	col(15);
	cout << "\n\n\n";
	cout << "\t\t\t\t\t[Pulse ENTER para ";
	col(10);
	cout << "ENTRAR";
	col(15);
	cout << "] ";
	cin.clear();
	cin.get();
	cout << "\n\n\t\t\t\t\t\tCargando...\n" << endl;
	cout << "\t\t\t";
	for (int i = 0; i<60; i++) {
		col(255);
		cout << " ";
		Sleep(7);
	}
	col(15);
}
void Control::hastaLuego(){
	system("cls");
	for (int i = 0; i < 6; i++) { cout << "\n"; }
	col(15);
	cout << "\n\n\t\t\t\t\t\tCerrando...\n" << endl;
	cout << "\t\t\t";
	for (int i = 0; i<60; i++) {
		col(255);
		cout << " ";
		Sleep(15);
	}
	cin.clear();
	cin.ignore();
}
Control::~Control(){}
