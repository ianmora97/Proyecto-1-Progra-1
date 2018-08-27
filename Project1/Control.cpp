#include "Control.h"
Control::Control(){}
void Control::col(int c){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);}
void Control::opciones() {
	Interfaz *i = new Interfaz;
	FlotaGestion *flotaGe = new FlotaGestion;
	RutasGestion *rutaGes = new RutasGestion;
	Rutas *ruta = new Rutas;
	Persona *per = new Persona;
	Vuelos *vuelo = new Vuelos;
	VuelosGestion *vg = new VuelosGestion;

	//ciclos
	bool cicloPrincipal=true;
	//----!ciclos

	//bienvenido();
	while (cicloPrincipal) {
		i->imprime();
		int opc = i->menu();
		if (opc == 1) {
			int id;
			int annio;
			string modelo, marca;
			flotaGe->revisarAdmin();
			char tamanoAvion;
			bool cicloOpcion1 = true;
			while (cicloOpcion1) {
				system("cls");
				flotaGe->imprimeMenu();
				flotaGe->menu();
				int m = flotaGe->getOpc();
				if (m == 1) {
					system("cls");
					col(10);
					cout << "\t\t(Ingresar Avion)\n\n";
					col(15);
					bool tamA = true;
					while (tamA) {
						cout << "Cual sera el tamanio del avion?:\n";
						cout << "[ p ] Pequeño\n[ g ] Grande\n>";
						if (!(cin >> tamanoAvion)) {
							col(12);
							cerr << "Digite una letra!\n";
							col(15);
							cin.clear();
							cin.ignore(1024, '\n');
							tamA = true;
						}
						else {
							if ((tamanoAvion == 'p') || (tamanoAvion == 'g')) {
								tamA = false;
							}
							else {
								cout << "Digite 'p' o 'g'\n";
								tamA = false; 
							}
						}
					}
					Avion *avion = new Avion(tamanoAvion);
					cout << "Digite Id del avion:\n>";
					if (!(cin >> id)) { break; }
					avion->setId(id);
					cout << "Digite el Annio del avion:\n>";
					if (!(cin >> annio)) { break; }
					avion->setAnnio(annio);
					cout << "Digite el Modelo del avion:\n>";
					cin >> modelo;
					avion->setModelo(modelo);
					cout << "Digite la Marca del avion:\n>";
					cin >> marca;
					avion->setMarca(marca);
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
					cout << "Saliendo de la Gestion de Flota!\n";
					for (int i = 0; i < 2; i++) {
						Sleep(700);
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
				Sleep(1000);
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
				switch (rutaGes->interfaz()){
				case 1:
					system("cls");
					col(10);
					cout << "\t\t(Ingresar Rutas)\n\n";
					col(15);
					
					cout << "Ingrese el origen: ";
					cin.ignore();
					getline(cin,origen);
					cout << "Ingrese el destino : ";
					
					getline(cin,destino);
					cout << "Ingrese la duracion del vuelo (Horas): ";
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
					cout << "Ingrese la cantidad de escalas: ";
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
					cout << "Saliendo de la gestion de Rutas!\n";
					for (int i = 0; i < 2; i++) {
						Sleep(1000);
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
				Sleep(1000);
			}
			system("cls");
			col(15);
			bool cicloOpcion = true;
			Avion *avion;
			string nomRuta;
			string fecha;
			int horaSalida;
			int horaLlegada;
			string aereoSalida;
			string aereoLlegada;
			string piloto;
			while (cicloOpcion) {
				system("cls");
				vg->imprimeMenu();
				switch (vg->interfaz()){
				case 1:
					system("cls");
					col(10);
					cout << "\t\t(Ingresar Vuelos)\n\n";
					col(15);
					//comenzar con la suma de origenes en rutas
					//ingresar los valores de las variables ya declaradas
					//guardar en los set de vuelo->...
					//vg->ingresar(vuelo)
					break;
				case 2:
					system("cls");
					col(10);
					cout << "\t\t(Visualizar Vuelos)\n\n";
					col(15);
					vg->visualizar();
					system("PAUSE");
					break;
					break;
				case 3:
					system("cls");
					col(10);
					cout << "\t\t(Modificar Vuelos)\n\n";
					col(15);
					vg->modificar();
					system("PAUSE");
					break;
					break;
				case 4:
					system("cls");
					col(10);
					cout << "\t\t(Eliminar Vuelos)\n\n";
					col(15);
					vg->eliminar();
					system("PAUSE");
					break;
					break;
				default:
					system("cls");
					col(13);
					cout << "\n\n\n\t\t\t";
					cout << "Saliendo de la gestion de Vuelos!\n";
					for (int i = 0; i < 2; i++) {
						Sleep(1000);
					}
					col(15);
					cicloOpcion = false;
					break;
				}
			}
			system("PAUSE");
		}
		if (opc == 0) { 
			cicloPrincipal = false; 
		}
	}
	//hastaLuego();
}
void Control::bienvenido(){
	for (int i = 0; i < 6; i++) { cout << "\n"; }
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
	system("PAUSE");
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
}
Control::~Control(){}
