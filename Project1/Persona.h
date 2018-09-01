#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <stdlib.h>
using namespace std;
/*


                   TERMINAR+
				INSERTA PERSONA INSERTA UN NUMERO MAS ADELANTE COLUMNAS / FILAS


*/
class Persona{
private:
	string name;
	string id;
	int estado; //se le asigna el estado, si tiene comprado un asiento
public:
	Persona();
	Persona(string,string,int);
	string getName();
	string getId();
	int getEstado();
	void setName(string);
	void setId(string);
	void setEstado(int);
	string toString();
	~Persona();
};
#endif // !PERSONA_H