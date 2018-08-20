#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <stdlib.h>
using namespace std;
class Persona{
private:
	string name;
	string id;
public:
	Persona();
	Persona(string,string);
	string getName();
	string getId();
	string toString();
	~Persona();
};
#endif // !PERSONA_H