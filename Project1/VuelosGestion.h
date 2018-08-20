#ifndef VUELOSGESTION_H
#define VUELOSGESTION_H
#include "Avion.h"
#include <time.h>
using namespace std;
class VuelosGestion{
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
	VuelosGestion();
	void col();
	~VuelosGestion();
};
#endif // !VUELOSGESTION_H