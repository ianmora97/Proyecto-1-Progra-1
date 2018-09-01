#ifndef ASIENTOS_H
#define ASIENTOS_H
#include "Persona.h"
using namespace std;
class Asientos{
private:
	Persona ***asiento; //hacer esto dinamico ** objetos dinamicos vector dinamicos
	int can;
	int tam;
	int f, c;
	string tipo;
public:
	Asientos(int,int,int);
	int getFilas();
	int getColumnas();
	int getTam();
	int getCant();
	string getTipo();
	int letraXNumero(char);
	int revisaValor(char, int);
	void insertaPersona(Persona*,char,int);
	void imprimeAsientos();
	Persona devuelvePersona(int,int);
	~Asientos();
};
#endif // !ASIENTOS_H