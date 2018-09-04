#include "Persona.h"
Persona::Persona(){};
Persona::Persona(string n, string i,string a) : name(n), id(i), asiento(a){}
string Persona::getName() {	return name; }
string Persona::getId() { return id; }
string Persona::getAsiento() { return asiento; }
string Persona::toString(){
	stringstream p;
	p << "Nombre: "<<name<<endl;
	p << "Identificacion: " << id << endl;
	p << "Asiento: " << asiento << endl;
	return p.str();
}
void Persona::setName(string n) { name = n; }
void Persona::setId(string i) { id = i; }
Persona::~Persona(){
	name = " ";
	id = " ";
	asiento = " ";
	cout << "Se ha destruido una persona!" << endl;
}
