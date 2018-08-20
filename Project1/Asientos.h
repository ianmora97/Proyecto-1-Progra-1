#ifndef ASIENTOS_H
#define ASIENTOS_H
#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>
#include "Persona.h"
using namespace std;
class Asientos{
private:
	Persona *asiento;
	int can;
	int f, c;
	int vec[6][30];
public:
	Asientos();
	int letraXNumero(char);
	void insertaPersona(Persona&,char,int);
	void imprimeAsientos();
	~Asientos();
};
#endif // !ASIENTOS_H