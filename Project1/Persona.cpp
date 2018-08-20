#include "Persona.h"
Persona::Persona(){};
Persona::Persona(string n, string i) { name = n; id = i; }
string Persona::getName() {	return name; }
string Persona::getId() { return id; }
string Persona::toString(){
	stringstream p;
	p << "Nombre: "<<name<<endl;
	p << "Identificacion: " << id << endl;
	return p.str();
}
Persona::~Persona(){}
