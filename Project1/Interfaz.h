#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
class Interfaz{
public:
	Interfaz();
	void col(int);
	void gotoxy(int x, int y);
	int menu();
	void imprime();
	int validar();
	~Interfaz();
};
#endif // !INTERFAZ_H