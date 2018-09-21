#include "Tiquete.h"
Tiquete::Tiquete(){}

Tiquete::Tiquete(Vuelos *v, Persona *p,string asiento){
	vuelo = v;
	persona = p;
	this->asiento = asiento;
}
void Tiquete::col(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }
void Tiquete::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
Vuelos Tiquete::getVuelo() { return *vuelo; }
Persona Tiquete::getPersona() { return *persona; }
void Tiquete::setVuelo(Vuelos * v) {  vuelo = v; }
void Tiquete::setPersona(Persona *p) { persona = p; }
void Tiquete::toString() {
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
	cout << "  Asiento        : " << asiento << endl;
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
	cout << "  Vuelo               : " << vuelo->getNomRuta() << endl;
	cout << char(186);
	cout << "  Fecha               : " << vuelo->getFecha() << endl;
	cout << char(186);
	cout << "  Aereopuerto salida  : " << vuelo->getAereoSalida() << endl;
	cout << char(186);
	cout << "  Aereopuerto llegada : " << vuelo->getAereoLlegada() << endl;
	cout << char(186);
	cout << "  Hora salida         : " << vuelo->getHoraSalida() << ":00" << endl;
	cout << char(186);
	cout << "  Hora llegada        : " << vuelo->getHoraLlegada() << ":00" << endl;
	cout << char(186);
	cout << "  Piloto              : " << vuelo->getPiloto() << endl;
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
	cout << "  Identificacion      : " << vuelo->devuelveAvion().getId() << endl;
	cout << char(186);
	cout << "  A" << char(164) << "o                 : " << vuelo->devuelveAvion().getAnnio() << endl;
	cout << char(186);
	cout << "  Marca               : " << vuelo->devuelveAvion().getMarca() << endl;
	cout << char(186);
	cout << "  Modelo              : " << vuelo->devuelveAvion().getModelo() << endl;
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
	cout << "  Precio del tiquete  :    $" << vuelo->devuelveRuta().getPrecio() << endl;
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
	vuelo->devuelveAvion().imprimeAsientos();
	cout << endl << endl;

	gotoxy(65, 2);
	cin.ignore();
	cin.get();
}
Tiquete::~Tiquete()
{
}
