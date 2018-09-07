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

	flotaGe->ingresarAvion(a1);
	flotaGe->ingresarAvion(a2);
	flotaGe->ingresarAvion(a3);
	Rutas *r1 = new Rutas("Costa Rica", "Panama", 1, 1);
	Rutas *r2 = new Rutas("Costa Rica", "España", 17, 1);
	Rutas *r3 = new Rutas("Costa Rica", "Estados Unidos", 3, 1);
	rutaGes->ingresarRuta(r1);
	rutaGes->ingresarRuta(r2);
	rutaGes->ingresarRuta(r3);
	Vuelos *v1 = new Vuelos("COSTA RICA-PANAMA","14,NOVIEMBRE,2018",5,6,"Juan Santamaria","Albrook","Juan Gonzales", *a1);
	Vuelos *v2 = new Vuelos("COSTA RICA-ESPAÑA", "25,DICIEMBRE,2018", 8, 1, "Juan Santamaria", "Madrid", "Luis Garita", *a2);
	Vuelos *v3 = new Vuelos("COSTA RICA-ESTADOS UNIDOS", "8,ENERO,2019", 12, 3, "Juan Santamaria", "Orlando, Florida", "Ivannia Flores", *a3);
	vg->insertarVuelo(v1);
	vg->insertarVuelo(v2);
	vg->insertarVuelo(v3);
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
			col(13);
			cout << "\n\n\n\t\t\t";
			cout << "Bienvenido a la Gestion de Flota!\n";
			for (int i = 0; i < 2; i++) {
				Sleep(500);
			}
			system("cls");
			char tamanoAvion;
			bool cicloOpcion1 = true;
			while (cicloOpcion1) {
				system("cls");
				flotaGe->imprimeMenu();
				flotaGe->menu();
				int m = flotaGe->getOpc();
				if (m == 1) {
					int id;
					int annio;
					string modelo, marca;
					system("cls");
					col(10);
					cout << "\t\t(Ingresar Avion)\n\n";
					col(15);
					bool tamA = true;
					cout << "Cual sera el tama"<<char(164)<<"io del avion?:\n";
					col(10);
					cout << "[ P ]";
					col(15);
					cout<<" Peque" << char(164);
					cout << "o - ";
					col(10);
					cout << "[ G ]";
					col(15);
					cout<< " Grande";
					int fil, colu,t;
					while (tamA == true) {
						cout << "\n> ";
						if (!(cin >> tamanoAvion)) {
							col(12);
							cerr << "Digite una letra!\n";
							col(15);
							cin.clear();
							cin.ignore(1024, '\n');
							tamA = true;
						}
						else {
							if ((tamanoAvion == 'p') || (tamanoAvion == 'g' || tamanoAvion == 'P' || tamanoAvion == 'G')) {
								if (tamanoAvion == 'P' || tamanoAvion == 'p') {
									t = 100;
									fil = 4;
									colu = 25;
								}
								else if(tamanoAvion == 'g' || tamanoAvion == 'G'){
									t = 180;
									fil = 6;
									colu = 30;
								}
								tamA = false;
							}
							else {
								col(12);
								cerr << "Digite \"P\" o \"G\" \n";
								col(15);
								cin.clear();
								cin.ignore(1024, '\n');
								tamA = true;
							}
						}
					}
					cout << "Digite Id del avion (NUMERO) ";
					bool cicloId = true;
					while (cicloId == true) {
						cout << "> ";
						if (!(cin>>id)) {
							col(12);
							cerr << "Digite un numero!\n";
							col(15);
							cin.clear();
							cin.ignore(1024, '\n');
						}
						else {
							cicloId = false;
						}
					}
					cout << " \nDigite el a"<<char(164)<<"o del avion ";
					bool cicloAn = true;
					while (cicloAn == true) {
						cout << "> ";
						if (!(cin >> annio)) {
							col(12);
							cerr << "Digite un numero!\n";
							col(15);
							cin.clear();
							cin.ignore(1024, '\n');
						}
						else {
							cicloAn = false;
						}
					}
					cout << "\nDigite el Modelo del avion > ";
					cin.ignore();
					getline(cin,modelo);
					cout << "\nDigite la Marca del avion > ";
					getline(cin,marca);
					Avion *avion = new Avion(id,annio,modelo,marca,t,fil,colu);
					flotaGe->ingresarAvion(avion);
					col(10);
					cout << "Avion ingresado Correctamente!\n";
					col(15);
					system("PAUSE");
				}
				else if (m == 2) {
					flotaGe->visualizarAviones();
				}
				else if (m == 3) {
					flotaGe->modificar();
					system("PAUSE");
				}
				else if (m==4) {
					flotaGe->eliminar();
					system("PAUSE");
				}
				else {
					system("cls");
					col(13);
					cout << "\n\n\n\t\t\t";
					cout << "Saliendo de [Gestion de Flota]\n";
					cout << "\n\t\t";
					for (int i = 0; i < 60; i++) {
						col(255);
						cout << " ";
						Sleep(15);
					}
					system("cls");
					col(15);
					cicloOpcion1 = false;
				}
			}

		}
		else if (opc == 2) {
			system("cls");
			col(13);
			cout << "\n\n\n\t\t\t";
			cout << "Bienvenido a la gestion de Rutas!\n";
			for (int i = 0; i < 2; i++) {
				Sleep(500);
			}
			system("cls");
			col(15);
			bool cicloOpcion = true;
			string origen;
			string destino;
			int duracion;
			int escalas;
			bool d1 = true;
			bool d2 = true;
			while (cicloOpcion) {
				system("cls");
				rutaGes->imprimirMenu();
				rutaGes->interfaz();
				int opcR = rutaGes->opc();
				if (opcR == 1) {
					system("cls");
					col(10);
					cout << "\t\t(Ingresar Rutas)\n\n";
					col(15);
					cout << "Ingrese el origen (";
					col(10);
					cout << "Despegue";
					col(15);
					cout << ") > ";
					cin.ignore();
					col(10);
					getline(cin, origen);
					col(15);
					cout << "\nIngrese el destino (";
					col(10);
					cout << "Aterrizaje";
					col(15);
					cout << ") > ";
					col(10);
					getline(cin, destino);
					col(15);
					cout << "\nIngrese la duracion del vuelo (";
					col(14);
					cout << "Cantidad de Horas";
					col(15);
					cout << ")";
					d1 = true;
					while (d1) {
						cout << " > ";
						col(14);
						if (!(cin >> duracion)) {
							col(12);
							cerr << "Error! Digite un numero!\n";
							col(15);
							cin.clear();
							cin.ignore(1024, '\n');
						}
						else {
							d1 = false;
						}
						col(15);
					}
					cout << "\nIngrese la cantidad de escalas";
					d2 = true;
					while (d2) {
						cout << " > ";
						col(11);
						if (!(cin >> escalas)) {
							col(12);
							cerr << "Error! Digite un numero!\n";
							col(15);
							cin.clear();
							cin.ignore(1024, '\n');
						}
						else {
							d2 = false;
						}
						col(15);
					}
					Rutas *ruta = new Rutas(origen,destino,duracion,escalas);
					rutaGes->ingresarRuta(ruta);
					col(10);
					cout << "\nSe ha ingresado una ruta correctamente!\n";
					col(15);
					system("PAUSE");
				}
				else if (opcR == 2) {
					system("cls");
					col(10);
					cout << "\t\t(Visualizar Rutas)\n\n";
					col(15);
					rutaGes->visualizar();
					system("PAUSE");
				}
				else if (opcR == 3) {
					system("cls");
					col(10);
					cout << "\t\t(Modificar Rutas)\n\n";
					col(15);
					rutaGes->modificar();
					system("PAUSE");
				}
				else if (opcR == 4) {
					system("cls");
					col(10);
					cout << "\t\t(Eliminar Rutas)\n\n";
					col(15);
					rutaGes->eliminar();
					system("PAUSE");
				}
				else if (opcR == 0) {
					system("cls");
					col(13);
					cout << "\n\n\n\t\t\t";
					cout << "Saliendo de [Gestion de Rutas]\n";
					cout << "\n\t\t";
					for (int i = 0; i < 60; i++) {
						col(255);
						cout << " ";
						Sleep(15);
					}
					col(15);
					cicloOpcion = false;
					break;
				}
			}
			
		}
		else if (opc == 3) {
			system("cls");
			col(13);
			cout << "\n\n\n\t\t\t";
			cout << "Bienvenido a la gestion de Vuelos!\n";
			for (int i = 0; i < 2; i++) {
				Sleep(500);
			}
			system("cls");
			col(15);
			bool cicloOpcion = true;
			while (cicloOpcion == true) {
				system("cls");
				vg->imprimeMenu();
				int opcRuta;
				vg->interfaz();
				if (vg->getOpc() == 1) {
					system("cls");
					col(10);
					cout << "\t\t(Ingresar Vuelos)\n\n";
					col(15);
					if (rutaGes->getCant() != 0 && flotaGe->getCant() != 0) {
						string nomRuta="";
						string fecha="";
						int horaSalida=0;
						int horaLlegada=0, suma=0;
						string aereoSalida="";
						string aereoLlegada="";
						string piloto="";
						bool cicloSelecRuta = true;
						bool cicloSelecHora = true;
						bool cicloSelecAvion = true;
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
								if (opcRuta >= 0 && opcRuta <= rutaGes->getCant()) {
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
						int numRuta = opcRuta - 1; // se le resta uno por la posicion del vector
						Vuelos *vuelo = new Vuelos;
						system("cls");
						nomRuta = rutaGes->devuele(numRuta).sumaRuta(); //suma la ruta de salida mas la de llegada
						cout << "\nLos aviones disponibles para asignar una ruta a "<<nomRuta<<endl;
						int cont = 0;
						flotaGe->toString();
						cout << "\nSeleccione un Avion";
						int opcAvion; //el numero del avion
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
								if (opcAvion >= 0 && opcAvion <= rutaGes->getCant()) {
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
						Avion *av;
						av = new Avion(flotaGe->devuelve(opcAvion-1)); //hace una copia del avion
						vuelo->insertaAvion(av);
						fecha = vuelo->muestraFecha();
						cout << endl;
						cout << "\tSeleccione la hora de salida (Solo la hora en ";
						col(14);
						cout << " AMARILLO";
						col(15);
						cout<<")\n" << endl;
						cout << "\tAM\t\t\t\tPM\n";
						for (int i = 0; i < 12; i++) {
							for (int j = 0; j < 2; j++) {
								if (j==1) {
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
						suma = horaSalida + (rutaGes->devuele(numRuta).getDuracion()); //pide por la duracion del avion y la suma a la hora de salida para la hora de llegada
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
						int can = vg->getCant();
						vuelo->setNomRuta(nomRuta);
						vuelo->setFecha(fecha);
						vuelo->setHoraSalida(horaSalida);
						vuelo->setHoraLlegada(horaLlegada);
						vuelo->setAereoSalida(aereoSalida);
						vuelo->setAereoLlegada(aereoLlegada);
						vuelo->setPiloto(piloto);
						vg->insertarVuelo(vuelo);
						col(10);
						cout << "Un vuelo ha sido creado!\n";
						col(15);
						cont++;
						col(11);
						cout << " Avion:\n";
						col(15);
						cout << vg->devuelveVuelo(can).devuelveAvion().toString()<<endl;
						col(11);
						cout << " Ruta:\n";
						col(15);
						cout << rutaGes->devuele(numRuta).toString()<<endl;
						col(11);
						cout << " Vuelo:\n";
						col(15);
						cout << vg->devuelveVuelo(can).toString() << endl;
	
					}
					else {
						col(12);
						cerr << "No hay rutas ingresadas!\nIngrese una ruta primero en [Modulo Gestion de Ruta]\n";
						col(15);
					}
					system("PAUSE");
					cicloOpcion = true;
				}
				else if (vg->getOpc() == 2) {
					system("cls");
					col(10);
					cout << "\t\t(Visualizar Vuelos)\n\n";
					col(15);
					vg->visualizar();
					system("PAUSE");
					cicloOpcion = true;
				}
				else if (vg->getOpc() == 3) {
					system("cls");
					col(10);
					cout << "\t\t(Modificar Vuelos)\n\n";
					col(15);
					if (rutaGes->getCant() != 0) {
						vg->modificar();
					}
					else {
						col(12);
						cerr << "No hay rutas ingresadas!\nIngrese una ruta primero en [Modulo Gestion de Ruta]\n";
						col(15);
					}
					system("PAUSE");
					cicloOpcion = true;
				}
				else if (vg->getOpc() == 4) {
					system("cls");
					col(10);
					cout << "\t\t(Eliminar Vuelos)\n\n";
					col(15);
					if (rutaGes->getCant() != 0) {
						vg->eliminar();
					}
					else {
						col(12);
						cerr << "No hay rutas ingresadas!\nIngrese una ruta primero en [Modulo Gestion de Ruta]\n";
						col(15);
					}
					system("PAUSE");
					cicloOpcion = true;
				}
				else if (vg->getOpc() == 0){
					system("cls");
					col(13);
					cout << "\n\n\n\t\t\t";
					cout << "Saliendo de la gestion de Vuelos!\n";
					cout << "\n\t\t";
					for (int i = 0; i < 60; i++) {
						col(255);
						cout << " ";
						Sleep(15);
					}
					col(15);
					cicloOpcion = false;
				}
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
						string nombre;
						string id;
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
						bool verifica = true;
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
							gotoxy(47, (vg->devuelveVuelo(vuelo).devuelveAvion().getFilas() + 8));
							bool cicloSelecFila = true;
							while (cicloSelecFila == true) {
								cout << "> ";
								if (!(cin >> fila)) {
									col(12);
									cerr << "Digite una letra!\n";
									col(15);
									cin.clear();
									cin.ignore(1024, '\n');
								}
								else {
									if (vg->revisaValor(fila, tamAvion) == 1) {
										cicloSelecFila = false;
									}
									else {
										col(12);
										cerr << "Digite una letra de la fila!\n";
										col(15);
										cin.clear();
										cin.ignore(1024, '\n');
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
							gotoxy(51, (vg->devuelveVuelo(vuelo).devuelveAvion().getFilas() + 11));
							bool cicloSelecNum = true;
							while (cicloSelecNum == true) {
								cout << "> ";
								if (!(cin >> columna)) {
									col(12);
									cerr << "Digite una numero!\n";
									col(15);
									cin.clear();
									cin.ignore(1024, '\n');
								}
								else {
									if (columna > 0 && columna <= colum) {
										cicloSelecNum = false;
									}
									else {
										col(12);
										cerr << "Digite una numero de las columnas!\n";
										col(15);
										cin.clear();
										cin.ignore(1024, '\n');
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
								Sleep(2000);
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
				SOLO PARA VERIFICAR EL METODO DE LOS AVIONES
			*/
			system("cls");
			Persona *p = new Persona("Aqui ","hay","una persona");
			char c;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 25; j++) {
					if (i == 0) {
						c = 'A';
					}
					if (i == 1) {
						c = 'B';
					}
					if (i == 2) {
						c = 'C';
					}
					if (i==3) {
						c = 'D';
					}
					vg->devuelveVuelo(2).devuelveAvion().insertarPersona(p, c, j);
					vg->devuelveVuelo(2).devuelveAvion().imprimeAsientos();
					system("cls");
				}
			}
			vg->devuelveVuelo(2).devuelveAvion().imprimeAsientos();
			cout << endl;
			system("PAUSE");
		}
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
