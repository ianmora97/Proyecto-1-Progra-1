#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
#include <time.h>
#include "Avion.h"
#include "Interfaz.h"
#include "Persona.h"
#include "RutasGestion.h"
#include "FlotaGestion.h"
#include "Vuelos.h"
#include "VuelosGestion.h"
using namespace std;
class Control{
public:
	Control();
	void col(int);
	void opciones();
	void bienvenido();
	void hastaLuego();
	~Control();
};
#endif // !CONTROL_H