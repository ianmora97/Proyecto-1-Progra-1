#ifndef TIQUETE_H
#define TIQUETE_H
#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>
using namespace std;
class Tiquete{
private:
	string nom;
	string id;
	string as;
public:
	Tiquete(string,string,string);
	string getNom();
	string getId();
	string getAsiento();
	string toString();
	~Tiquete();
};
#endif // !TIQUETE_H