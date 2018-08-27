#ifndef ASIENTOS_H
#define ASIENTOS_H
#include "Persona.h"
using namespace std;
class Asientos{
private:
	Persona **asiento; //hacer esto dinamico ** objetos dinamicos vector dinamicos
	int can,tam;
	int f, c;
	int vec[6][30];
	string tipo;
public:
	Asientos(char);
	int getFilas();
	int getColumnas();
	int getTam();
	string getTipo();
	int letraXNumero(char);
	void insertaPersona(Persona*,char,int);
	void imprimeAsientos();
	~Asientos();
};
#endif // !ASIENTOS_H