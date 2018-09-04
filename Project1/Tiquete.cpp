#include "Tiquete.h"
Tiquete::Tiquete(string n, string i, string a) : nom(n), id(i), as(a) {}
string Tiquete::getNom() { return nom; }
string Tiquete::getId() { return id; }
string Tiquete::getAsiento() { return as; }
string Tiquete::toString() {
	stringstream p;
	p << "Nombre: " << nom << endl;
	p << "Identificacion: " << id << endl;
	p << "Asiento: " << as << endl;
	return p.str();
}
Tiquete::~Tiquete()
{
}
