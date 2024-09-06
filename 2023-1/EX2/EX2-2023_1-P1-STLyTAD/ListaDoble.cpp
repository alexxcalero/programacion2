/*
 * Proyecto : EX2-2023_1-P1-STLyTAD
 * Archivo  : ListaDoble.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de julio de 2024, 12:55
 */

#include "ListaDoble.h"

ListaDoble::ListaDoble() {
	ini = nullptr;
	fin = nullptr;
}

ListaDoble::ListaDoble(const ListaDoble &orig) {
}

ListaDoble::~ListaDoble() {
}

void ListaDoble::insertar(Alumno &alumno) {
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->dato.agregarAlumno(alumno);
	nuevoNodo->ant = nullptr;
	nuevoNodo->sig = nullptr;

	if(esListaVacia()) {
		ini = nuevoNodo;
		fin = nuevoNodo;
	} else {
		Nodo *rec = ini;
		Nodo *ant = nullptr;
		bool seEncuentra = false;
		while(rec) {
			if(rec->dato.getCodigoDelAlumno() == alumno.GetCodigo()) {  // Ya esta en la lista
				seEncuentra = true;
				break;
			}
			if(rec->dato.getCodigoDelAlumno() > alumno.GetCodigo())
				break;
			ant = rec;
			rec = rec->sig;
		}
		if(!seEncuentra) {  // Hago las conexiones cuando no se encuentra en la lista
			nuevoNodo->sig = rec;
			if(rec == nullptr) {  // Inserto al final de la lista
				fin->sig = nuevoNodo;
				nuevoNodo->ant = fin;
				fin = nuevoNodo;
			} else {
				if(ant != nullptr) {  // Inserto al medio de la lista
					rec->ant = nuevoNodo;
					nuevoNodo->ant = ant;
					ant->sig = nuevoNodo;
				} else {  // Inserto al inicio de la lista
					ini->ant = nuevoNodo;
					ini = nuevoNodo;
				}
			}
		}
	}
}

bool ListaDoble::esListaVacia() {
	return ini == nullptr && fin == nullptr;
}

bool ListaDoble::buscarAlumno(int codAlumno) {
	Nodo *rec = ini;
	while(rec) {
		if(rec->dato.getCodigoDelAlumno() == codAlumno)
			return true;
		rec = rec->sig;
	}
	return false;
}

void ListaDoble::leerNotasDelAlumno(ifstream &arch, int ciclo, int codAlumno) {
	Nodo *rec = ini;
	while(rec) {
		if(rec->dato.getCodigoDelAlumno() == codAlumno) {
			rec->dato.leerNotas(arch, ciclo);
			return;
		}
		rec = rec->sig;
	}
}

void ListaDoble::imprimir(ofstream &arch) {
	if(esListaVacia()) {
		cout << "La lista esta vacia\n";
		return;
	}
	Nodo *rec = ini;
	while(rec) {
		rec->dato.imprimir(arch);
		rec = rec->sig;
	}
}

void ListaDoble::actualizarNotas() {
	if(esListaVacia())
		return;
	Nodo *rec = ini;
	while(rec) {
		rec->dato.actualizarYtotalizar();
		rec = rec->sig;
	}
}
