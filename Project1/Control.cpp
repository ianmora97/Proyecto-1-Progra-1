#include "Control.h"
Control::Control(){}
void Control::col(int c){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);}
void Control::opciones() {
	Interfaz *i = new Interfaz;
	FlotaGestion *flotaGe = new FlotaGestion;
	RutasGestion *rutaGes = new RutasGestion;
	VuelosGestion *vg = new VuelosGestion;
	CompraTiquetes *tiquetes = new CompraTiquetes;
	//ciclos
	bool cicloPrincipal=true;
	//----!ciclos

	bienvenido();
	while (cicloPrincipal) {
		i->imprime();
		int opc = i->menu();
		if (opc == 1) { // Gestion de Flotas
			flotaGe->revisarAdmin();
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
					cout << "[ P ] Peque" << char(164);
					cout << "o - [ G ] Grande";
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
					cout << "Digite el a"<<char(164)<<"o del avion ";
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
					cout << "Digite el Modelo del avion > ";
					cin.ignore();
					getline(cin,modelo);
					cout << "Digite la Marca del avion > ";
					getline(cin,marca);
					Avion *avion = new Avion(id,annio,modelo,marca,t,fil,colu);
					flotaGe->ingresarAvion(avion);
					system("PAUSE");
				}
				else if (m == 2) {
					flotaGe->visualizarAviones();
					system("PAUSE");
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
					cout << "\t\t\t";
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
		if (opc == 2) {
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
				Rutas *ruta = new Rutas;
				switch (rutaGes->interfaz()){
				case 1:
					system("cls");
					col(10);
					cout << "\t\t(Ingresar Rutas)\n\n";
					col(15);
					cout << "Ingrese el origen (Lugar de despegue) > ";
					cin.ignore();
					getline(cin,origen);
					cout << "Ingrese el destino (Lugar de aterrisaje) > ";
					getline(cin,destino);
					cout << "Ingrese la duracion del vuelo (Cantidad de Horas) > ";
					d1 = true;
					while (d1) {
						if (!(cin>>duracion)) {
							col(12);
							cerr << "Error! Digite un numero!\n";
							col(15);
							cin.clear();
							cin.ignore(1024,'\n');
						}
						else {
							d1 = false;
						}
					}
					cout << "Ingrese la cantidad de escalas > ";
					d2 = true;
					while (d2) {
						if (!(cin>>escalas)) {
							col(12);
							cerr << "Error! Digite un numero!\n";
							col(15);
							cin.clear();
							cin.ignore(1024, '\n');
						}
						else {
							d2 = false;
						}
					}
					ruta->setDestino(destino);
					ruta->setOrigen(origen);
					ruta->setCantEscalas(escalas);
					ruta->setDuracion(duracion);
					rutaGes->ingresarRuta(*ruta);
					system("PAUSE");
					break;
				case 2:
					system("cls");
					col(10);
					cout << "\t\t(Visualizar Rutas)\n\n";
					col(15);
					rutaGes->visualizar();
					system("PAUSE");
					break;
				case 3:
					system("cls");
					col(10);
					cout << "\t\t(Modificar Rutas)\n\n";
					col(15);
					rutaGes->modificar();
					system("PAUSE");
					break;
				case 4:
					system("cls");
					col(10);
					cout << "\t\t(Eliminar Rutas)\n\n";
					col(15);
					rutaGes->eliminar();
					system("PAUSE");
					break;
				default:
					system("cls");
					col(13);
					cout << "\n\n\n\t\t\t";
					cout << "Saliendo de [Gestion de Rutas]\n";
					cout << "\t\t\t";
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
		if (opc == 3) {
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
						flotaGe->toString();
						cout << "\nSeleccione un Avion";
						int opcAvion; //el numero del avion
						Avion *avion = new Avion;
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
						*avion = flotaGe->devuelve(opcAvion-1);
						//vuelo->setNumAvion(opcAvion-1); //asigna un avion da el numero del avion asignado en  la clase FlotaGestion
						fecha = vuelo->muestraFecha();
						system("cls");
						cout << "Seleccione la hora de salida (Solo la hora en ";
						col(14);
						cout << " AMARILLO";
						col(15);
						cout<<") " << endl;
						for (int i = 1; i <= 24; i++) {
							if (i == 13) {
								cout << endl;
							}
							col(14);
							cout << i;
							col(15);
							cout << ":" << "00 ";
						}
						cout << endl;
						while (cicloSelecHora) {
							cout << "> ";
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
						}
						suma = horaSalida + (rutaGes->devuele(numRuta).getDuracion()); //pide por la duracion del avion y la suma a la hora de salida para la hora de llegada
						if (suma > 24) { horaLlegada = suma - 24; } //verificacion de la hora de llegada si se pasa de 24
						else { horaLlegada = suma; }
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
						vuelo->insertaAvion(avion);
						vg->insertarVuelo(vuelo);
						col(11);
						cout << " Avion:\n";
						col(15);
						cout <<vg->devuelveVuelo(can).devuelveAvion().toString()<<endl;
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
					cout << "\t\t\t";
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
		if (opc == 4) {
			system("cls");
			col(13);
			cout << "\n\n\n\t\t\t";
			cout << "Bienvenido a la Compra de tiquetes!\n";
			for (int i = 0; i < 2; i++) {Sleep(500);}
			system("cls");
			col(15);
			bool cicloCompra = true;
			while (cicloCompra == true) {
				tiquetes->imprimeMenu();
				tiquetes->interfaz();
				if (tiquetes->getOpc() == 1) {
					system("cls");
					col(10);
					cout << "\t\t(Compra de Tiquetes)\n\n";
					col(15);
					if (vg->getCant() != 0) { //si no hay vuelos registrados no puede comprar asientos
						vg->toString();
						cout << "Seleccione el vuelo deseado";
						int opcVvuelo;
						bool cicloSelecVuelo=true;
						while (cicloSelecVuelo == true) {
							cout << "> ";
							if (!(cin>> opcVvuelo)) {
								col(12);
								cerr << "Digite un numero!\n";
								col(15);
								cin.clear();
								cin.ignore(1024, '\n');
							}
							else {
								if (opcVvuelo > 0 && opcVvuelo <= vg->getCant() ) {
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
						int vuelo = opcVvuelo-1;
						cout << vuelo;
						int numeroAvionSeleccionado = vg->devuelveVuelo(vuelo).getNumAvion();
						int tamAvion = flotaGe->devuelve(numeroAvionSeleccionado).getCantPasajeros(); //tamaño del avion seleccionado
						int colum = flotaGe->devuelve((vg->devuelveVuelo(vuelo).getNumAvion())).getColumnas(); //tamaño de las columnas del avion seleccionado;						
						system("cls");
						string nombre;
						string id;
						col(10);
						cout << "[Digitar los datos de la persona]\n";
						col(11);
						cout << "Asiento"<<endl;
						cout << "------------------\n";
						col(15);
						cout << "Digite su nombre > ";
						cin.ignore();
						getline(cin,nombre);
						cout << "Digite su identificacion >";
						getline(cin,id);
						Persona *persona = new Persona(nombre,id,1);
						cout << endl<<"Datos:\n";
						cout << persona->getName()<<endl;
						cout << persona->getId()<<endl;
						for (int j = 0; j < 2; j++) {Sleep(500);}
						system("cls");
						cout << "[Digitar el asiento de "<<persona->getName()<<" ]"<<endl;
						flotaGe->devuelve(numeroAvionSeleccionado).imprimeAsientos();
						char fila;
						int columna;
						cout << "Digite la fila del asiento (Letra / A B C D...) ";
						bool cicloSelecFila = true;
						while (cicloSelecFila == true) {
							cout << "> ";
							if (!(cin>>fila)) {
								col(12);
								cerr << "Digite una letra!\n";
								col(15);
								cin.clear();
								cin.ignore(1024, '\n');
							}
							else {
								if (vg->revisaValor(fila,tamAvion) == 1) {
									cicloSelecFila = false;
								}
								else {
									col(12);
									cerr << "Digite una letra de la columna!\n";
									col(15);
									cin.clear();
									cin.ignore(1024, '\n');
								}
							}
						}
						cout << "\nDigite la columna del asiento(Numero / 1 2 3 4...) ";
						bool cicloSelecNum = true;
						while (cicloSelecNum == true) {
							cout << "> ";
							if (!(cin>>columna)) {
								col(12);
								cerr << "Digite una numero!\n";
								col(15);
								cin.clear();
								cin.ignore(1024, '\n');
							}
							else {
								if (columna > 0 && columna <= colum){
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
						int ca = flotaGe->devuelve(numeroAvionSeleccionado).getCan();
						flotaGe->devuelve(numeroAvionSeleccionado).insertarPersona(persona,fila,columna);
						cout << endl;
						flotaGe->devuelve(numeroAvionSeleccionado).imprimeAsientos();
						system("PAUSE");
						system("cls");
						col(10);
						cout << "Boletos comprados Correctamente!";
						col(15);
						cout << endl;
						col(11);
						cout << "------------------------------------------" << endl;
						col(15);
						col(11);
						cout << " Datos de la persona:"<< endl;
						col(15);
						cout << "Nombre: "<< persona->getName() << endl;
						cout << "Identificacion: "<<persona->getId() << endl;
						cout << "Asiento de la persona: ";
						col(14);
						cout << (fila);
						col(11);
						cout << columna << endl;
						col(11);
						cout << " Vuelo: " << endl;
						col(15);
						cout << vg->devuelveVuelo(vuelo).toString();
						col(11);
						cout << " Avion: " << endl;
						col(15);
						cout << flotaGe->devuelve(vuelo).toString() << endl;
						system("PAUSE");
					}
					cicloCompra = true;
				}
				if (tiquetes->getOpc() == 0) {
					system("cls");
					col(13);
					cout << "\n\n\n\t\t\t";
					cout << "Saliendo de la compra de tiquetes!\n";
					for (int i = 0; i < 2; i++) {
						Sleep(500);
					}
					col(15);
					cicloCompra = false;
				}
			}
		}
		if (opc == 0) { 
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
	cout << "\t\t\t\t    [Pulse cualquier tecla para ";
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
