#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include <Windows.h>
using namespace std;
class Interfaz{
public:
	Interfaz();
	void col(int);
	int menu();
	void imprime();
	int validar();
	~Interfaz();
};
#endif // !INTERFAZ_H