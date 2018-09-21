#ifndef TIQUETE_H
#define TIQUETE_H
#include "VuelosGestion.h"
using namespace std;
class Tiquete{
	Vuelos *vuelo;
	Persona *persona;
	string asiento;
public:
	Tiquete();
	Tiquete(Vuelos *v, Persona *p, string asiento);
	void col(int c);
	void gotoxy(int x, int y);
	Vuelos getVuelo();
	Persona getPersona();
	void setVuelo(Vuelos *v);
	void setPersona(Persona *p);
	void toString();
	~Tiquete();
};
#endif // !TIQUETE_H