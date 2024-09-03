/*
 * Proyecto : sobrecarga-con-objetos
 * Archivo  : Heroe.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 22 de mayo de 2024, 23:55
 */

#include "Heroe.h"

Heroe::Heroe() {
	nombre = nullptr;
//	hp = 100;
//	mana = 100.0;
//	posx = 0;
//	posy = 0;
	SetHp(100);
	SetMana(100.0);
	SetPosx(0);
	SetPosy(0);
	cout << "Se ejecuto el constructor por defecto\n";
}

Heroe::Heroe(const char *nombre) {
//	this->nombre = new char[strlen(nombre) + 1];
//	strcpy(this->nombre, nombre);
//	hp = 100;
//	mana = 100;
//	posx = 0;
//	posy = 0;
	SetNombre(nombre);
	SetHp(100);
	SetMana(100);
	SetPosx(0);
	SetPosy(0);
	cout << "Se ejecuto el constructor con parametros\n";
}

Heroe::~Heroe() {
	if(nombre != nullptr)
		delete nombre;
	cout << "Se ejecuto el destructor\n";
}

void Heroe::SetPosy(int posy) {
	this->posy = posy;
}

int Heroe::GetPosy() const {
	return posy;
}

void Heroe::SetPosx(int posx) {
	this->posx = posx;
}

int Heroe::GetPosx() const {
	return posx;
}

void Heroe::SetMana(double mana) {
	this->mana = mana;
}

double Heroe::GetMana() const {
	return mana;
}

void Heroe::SetHp(int hp) {
	this->hp = hp;
}

int Heroe::GetHp() const {
	return hp;
}

void Heroe::SetNombre(const char *nombre) {
	if(this->nombre != nullptr) delete this->nombre;
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
}

void Heroe::GetNombre(char *nombre) const {
	if(this->nombre == nullptr) nombre[0] = 0;
	else strcpy(nombre,this->nombre);
}

void Heroe::crear() {
	hp = 1000;
	posx = 5;
	posy = 5;
	mana = 200.0;
	char nombre[60] = "Nombre Por Defecto";
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
}

void Heroe::mover(int x, int y, double costoMana) {
	posx += x;
	posy += y;
	mana -= costoMana;
}

void Heroe::curar(int hp) {
	this->hp += hp;
}

void Heroe::mostrar() {
	cout << "Nombre: ";
	if(nombre == nullptr)
		cout << "Nombre por defecto\n";
	else
		cout << nombre << endl;
	cout << "HP: " << GetHp() << " MANA: " << GetMana() << endl;
	cout << "Pos. X: " << GetPosx() << " Pos. Y: " << GetPosy() << endl;
}

// Se mueve a la posicion del otro heroe
void Heroe::operator +=(const Heroe &otro) {
	posx = otro.posx;
	posy = otro.posy;
}

// Resta vida
void Heroe::operator -=(const Heroe &otro) {
	if(hp - otro.hp < 0)
		hp = 0;
	else
		hp -= otro.hp;
}
