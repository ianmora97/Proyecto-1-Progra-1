/*Universidad Nacional de Costa Rica
PROGRAMACION I
PRIMER PROYECTO DE PROGRAMACION
ESTUDIANTE: IAN MORA RODRIGUEZ
AGOSTO - SEPTIEMBRE 2018*/

#include "Control.h"
int main() {
	SetConsoleTitleA("Co Airlines - Compra de Tiquetes");
	Control *control = new Control;
	control->opciones();
	return 0;
};