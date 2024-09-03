/*
 * Proyecto : sobrecarga-con-objetos
 * Archivo  : Heroe.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 22 de mayo de 2024, 23:55
 */

#ifndef HEROE_H
#define HEROE_H

#include <iostream>
#include <cstring>
using namespace std;

class Heroe {
public:
	Heroe();  // Constructor por defecto
	Heroe(const char *nombre);  // Constructor con parametros
	virtual ~Heroe();  // Destructor
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetMana(double mana);
    double GetMana() const;
    void SetHp(int hp);
    int GetHp() const;
    void SetNombre(const char *nombre);
    void GetNombre(char *nombre) const;
	void crear();
	void mover(int x, int y, double mana);
	void curar(int hp);
	void mostrar();
	void operator +=(const Heroe &);
	void operator -=(const Heroe &);
private:
	char *nombre;
	int hp;
	double mana;
	int posx;
	int posy;
};

#endif /* HEROE_H */
