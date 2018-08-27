#include "Vuelos.h"
Vuelos::Vuelos() {
	avion = NULL;
	nomRuta = "";
	fecha = "";
	horaSalida = 0;
	horaLlegada = 0;
	aereoSalida = "";
	aereoLlegada = "";
	piloto = "";
}
void Vuelos::col(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }
void Vuelos::muestraFecha(){
}
string Vuelos::getNomRuta() { return nomRuta; }
string Vuelos::getFecha() { return fecha; }
int Vuelos::getHoraSalida() { return horaSalida; }
int Vuelos::getHoraLlegada() { return horaLlegada; }
string Vuelos::getAereoSalida() { return aereoSalida; }
string Vuelos::getAereoLlegada() { return aereoLlegada; }
string Vuelos::getPiloto() { return piloto; }
void Vuelos::setNomRuta(string n) { nomRuta = n; }
void Vuelos::setFecha(string f) { fecha = f; }
void Vuelos::setHoraSalida(int hs) { horaSalida = hs; }
void Vuelos::setHoraLlegada(int hl) { horaLlegada = hl; }
void Vuelos::setAereoSalida(string as) { aereoSalida = as; }
void Vuelos::setAereoLlegada(string al) { aereoLlegada = al; }
void Vuelos::setPiloto(string p) { piloto = p; }
string Vuelos::toString() {
	stringstream p;
	p << "Avion asignado: \n"
		<<"----------------------\n"
		<<avion->toString()<<endl;
	p << "Nombre de la ruta: "<<nomRuta<<endl;
	p << "Fecha: "<<fecha<<endl;
	p << "Hora de Salida: "<<horaSalida<<endl;
	p << "Hora de llegada: "<<horaLlegada<<endl;
	p << "Aereopuerto de Salida: "<<aereoSalida<<endl;
	p << "Aereopuerto de Llegada: "<<aereoLlegada<<endl;
	p << "Nombre del Piloto: "<<piloto<<endl;
	return p.str();
}
void Vuelos::setAvion(int i) {
	FlotaGestion f;
	*avion = f.devuelve(i);
}
Vuelos::~Vuelos(){
	avion = NULL;
	nomRuta = "";
	fecha = "";
	horaSalida = 0;
	horaLlegada = 0;
	aereoSalida = "";
	aereoLlegada = "";
	piloto = "";
}
