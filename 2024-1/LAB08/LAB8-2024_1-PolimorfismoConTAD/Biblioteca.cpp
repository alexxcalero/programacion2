/*
 * Proyecto : LAB8-2024_1-PolimorfismoConTAD
 * Archivo  : Biblioteca.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de junio de 2024, 08:13
 */

#include "Biblioteca.h"

Biblioteca::Biblioteca() {
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::carga() {
	ifstream arch("Estantes2.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Estantes2.csv\n";
		exit(1);
	}
	int numEstantes = 0, id;
	char clase, c;
	double peso;
	while(1) {
		arch >> clase;
		if(arch.eof()) break;
		arch >> c >> id >> c >> peso;
		arch.get();
		AEstantes[numEstantes].SetClase(clase);
		AEstantes[numEstantes].SetId(id);
		AEstantes[numEstantes].SetCapacidad(peso);
		numEstantes++;
	}
	AEstantes[numEstantes].SetId(-1);  // Para tener el fin del arreglo
//    for(int i = 0; AEstantes[i].GetId() != -1; i++) {
//        cout << AEstantes[i].GetClase() << " " << AEstantes[i].GetId() << " " << AEstantes[i].GetCapacidad() << endl;
//    }
}

void Biblioteca::llena() {
	ifstream arch("Libros3.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Libros3.csv\n";
		exit(1);
	}
	bool insertado;
	char tipo;
	Libro *nuevoLibro;
	while(1) {
		insertado = false;
		arch >> tipo;
		if(arch.eof()) break;
		arch.get();

		if(tipo == 'E') nuevoLibro = new Enciclopedia;
		else if(tipo == 'N') nuevoLibro = new Novela;
		else nuevoLibro = new Revista;

		nuevoLibro->lee(arch);

		for(int i = 0; AEstantes[i].GetId() != -1; i++) {
			if(AEstantes[i].verificarEspacio(nuevoLibro)) {
				AEstantes[i].insertarLibro(nuevoLibro);
				insertado = true;
			}

		}
		if(insertado == false)
			delete nuevoLibro;
	}
}

void Biblioteca::baja() {
	for(int i = 0; AEstantes[i].GetId() != -1; i++)
		AEstantes[i].actualizarVigencia();
}

void Biblioteca::muestra() {
	ofstream arch("ReporteDeEstantes.txt", ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ReporteDeEstantes.txt\n";
		exit(1);
	}
	arch << "Estantes:\n";
	imprimirLinea(arch, 50, '=');
	arch << endl;
	for(int i = 0; AEstantes[i].GetId() != -1; i++) {
		AEstantes[i].imprimirDatosDelEstante(arch);
//        AEstantes[i].imprimirLibros(arch);
	}
}

void Biblioteca::imprimirLinea(ofstream &arch, int cant, char c) {
	for(int i = 0; i < cant; i++)
		arch << c;
	arch << endl;
}
