/*
 * Proyecto : EX1-2024_1-P3-PunterosAFuncion
 * Archivo  : ColaPrioridadGenerica.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de mayo de 2024, 10:15
 */

#include "Enums.h"
#include "ColaPrioridadGenerica.h"

void generacola(void *&cola) {
	void **auxCola = new void*[4]{};
	void **nodoPrio3 = new void*[2]{};
	void **nodoPrio2 = new void*[2]{};
	void **nodoPrio1 = new void*[2]{};

	nodoPrio3[DATO] = nullptr;
	nodoPrio3[SIG] = nodoPrio2;
	nodoPrio2[DATO] = nullptr;
	nodoPrio2[SIG] = nodoPrio1;
	nodoPrio1[DATO] = nullptr;
	nodoPrio1[SIG] = nullptr;

	auxCola[CAB] = nodoPrio3;
	auxCola[PRIO3] = nodoPrio3;
	auxCola[PRIO2] = nodoPrio2;
	auxCola[PRIO1] = nodoPrio1;

	cola = auxCola;
}

void encolar(void *dato, void *cola) {
	void **auxCola = (void**)cola;
	void **auxDato = (void**)dato;
	int *rank = (int*)auxDato[RANK];
	void **prioridad3, **prioridad2, **prioridad1;
	if(colavacia(cola)) {
		if(*rank == 3) {
			prioridad3 = (void**)auxCola[PRIO3];
			prioridad3[DATO] = dato;
		} else if(*rank == 2) {
			prioridad2 = (void**)auxCola[PRIO2];
			prioridad2[DATO] = dato;
		} else {
			prioridad1 = (void**)auxCola[PRIO1];
			prioridad1[DATO] = dato;
		}
	} else {
		void **nuevoNodo = new void*[2]{};
		nuevoNodo[DATO] = dato;
		if(*rank == 3) {
			prioridad3 = (void**)auxCola[PRIO3];
			nuevoNodo[SIG] = prioridad3[SIG];
			prioridad3[SIG] = nuevoNodo;
		} else if(*rank == 2) {
			prioridad2 = (void**)auxCola[PRIO2];
			nuevoNodo[SIG] = prioridad2[SIG];
			prioridad2[SIG] = nuevoNodo;
		} else {
			prioridad1 = (void**)auxCola[PRIO1];
			nuevoNodo[SIG] = prioridad1[SIG];
			prioridad1[SIG] = nuevoNodo;
		}
	}
}

bool colavacia(void *cola) {
	void **auxCola = (void**)cola;
	void **cabeza = (void**)auxCola[CAB];
	void **prioridad3 = (void**)auxCola[PRIO3];
	void **prioridad2 = (void**)auxCola[PRIO2];
	void **prioridad1 = (void**)auxCola[PRIO1];
	if(cabeza[DATO] == nullptr && prioridad3[DATO] == nullptr &&
			prioridad2[DATO] == nullptr && prioridad1[DATO] == nullptr)
		return true;
	else
		return false;
}
