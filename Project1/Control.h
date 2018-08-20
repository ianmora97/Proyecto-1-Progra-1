#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
#include <time.h>
#include "Asientos.h"
#include "Avion.h"
#include "Interfaz.h"
#include "Persona.h"
#include "FlotaGestion.h"
#include "RutasGestion.h"
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