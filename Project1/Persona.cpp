#include "Persona.h"
Persona::Persona(){};
Persona::Persona(string n, string i) { name = n; id = i; }
string Persona::getName() {	return name; }
string Persona::getId() { return id; }
Persona::~Persona(){}
