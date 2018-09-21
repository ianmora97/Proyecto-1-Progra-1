#ifndef COMPRATIQUETE_H
#define COMPRATIQUETE_H
#include "Tiquete.h"
using namespace std;
class CompraTiquete{
private:
	Tiquete **tiquete;
	int cant, tam;
public:
	CompraTiquete();
	void col(int c);
	void gotoxy(int x, int y);
	void ingresar(Vuelos *v);
	void visualizar();
	int menu();
	~CompraTiquete();
};
#endif // !COMPRATIQUETE_H