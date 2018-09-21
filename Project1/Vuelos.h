#ifndef VUELOS_H
#define VUELOS_H
#include "FlotaGestion.h"
#include "RutasGestion.h"
using namespace std;
class Vuelos {
private:
	Avion avion;
	Rutas ruta;
	string nomRuta;
	string fecha;
	int horaSalida;
	int horaLlegada;
	string aereoSalida;
	string aereoLlegada;
	string piloto;
public:
	Vuelos();
	Vuelos(string,string,int,int,string,string,string,Avion,Rutas);
	Vuelos(const Vuelos * v);
	void col(int);
	string muestraFecha();
	string getNomRuta();
	string getFecha();
	int getHoraSalida();
	int getHoraLlegada();
	string getAereoSalida();
	string getAereoLlegada();
	string getPiloto();
	void setNomRuta(string);
	void setFecha(string);
	void setHoraSalida(int);
	void setHoraLlegada(int);
	void setAereoSalida(string);
	void setAereoLlegada(string);
	void setPiloto(string);
	void insertaAvion(Avion);
	Avion devuelveAvion();
	Rutas devuelveRuta();
	string toString();
	~Vuelos();
};
#endif // !VUELOS_H