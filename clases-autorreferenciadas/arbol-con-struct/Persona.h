/*
 * Proyecto : arbol-con-struct
 * Archivo  : Persona.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 13 de junio de 2024, 01:46
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <fstream>
using namespace std;

class Persona {
public:
	Persona();
	Persona(const Persona &orig);
	virtual ~Persona();
    void SetSueldo(double sueldo);
    double GetSueldo() const;
    void SetNombre(const char *nombre);
    void GetNombre(char *nombre) const;
    void SetDni(int dni);
    int GetDni() const;
	void operator =(const Persona &p);
	bool operator >(const Persona &p);
	bool operator ==(int dni);
	bool operator >(int dni);
private:
	int dni;
	char *nombre;
	double sueldo;
};

void operator >>(ifstream &arch, Persona &p);
void operator <<(ofstream &arch, const Persona &p);

#endif /* PERSONA_H */
