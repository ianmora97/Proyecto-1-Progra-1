#ifndef VUELOS_H
#define VUELOS_H
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include "FlotaGestion.h"
using namespace std;
class Vuelos {
private:
	Avion *avion;
	string nomRuta;
	string fecha;
	int horaSalida;
	int horaLlegada;
	string aereoSalida;
	string aereoLlegada;
	string piloto;
public:
	Vuelos();
	void col(int);
	string muestraFecha();
	string getNomRuta();
	string getFecha();
	int getHoraSalida();
	int getHoraLlegada();
	string getAereoSalida();
	string getAereoLlegada();
	string getPiloto();
	void ingresarAvion(Avion*);
	void setNomRuta(string);
	void setFecha(string);
	void setHoraSalida(int);
	void setHoraLlegada(int);
	void setAereoSalida(string);
	void setAereoLlegada(string);
	void setPiloto(string);
	string toString();
	Avion devuelve();
	~Vuelos();
};
#endif // !VUELOS_H