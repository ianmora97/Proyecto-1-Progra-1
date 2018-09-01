#include "Persona.h"
Persona::Persona(){};
Persona::Persona(string n, string i, int e) { name = n; id = i; estado = e; }
string Persona::getName() {	return name; }
string Persona::getId() { return id; }
int Persona::getEstado() { return estado; }
string Persona::toString(){
	stringstream p;
	p << "Nombre: "<<name<<endl;
	p << "Identificacion: " << id << endl;
	return p.str();
}
void Persona::setName(string n) { name = n; }
void Persona::setId(string i) { id = i; }
void Persona::setEstado(int e) { estado = e; }
Persona::~Persona(){}
