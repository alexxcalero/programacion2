/*
 * Proyecto : LAB4-2024_1-PunterosGenericos
 * Archivo  : PunterosGenericos.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de abril de 2024, 08:06
 */

#include <iomanip>
#include <fstream>
#include <cstring>
#include "PunterosGenericos.h"
#include "AperturaDeArchivos.h"
#include "MuestraPunteroGenerico.h"
using namespace std;

void cargaclientes(void *&clientes) {
	ifstream arch;
	AperturaDeUnArchivoDeTextosParaLeer(arch, "Clientes.csv");
	void *buffClientes[100]{}, *registro, **auxClientes;
	int numDat = 0;
	while(true) {
		registro = leerCliente(arch);
		if(arch.eof()) break;
		buffClientes[numDat] = registro;
		numDat++;
	}
	// Recorto a memoria exacta
	auxClientes = new void*[numDat + 1]{};
	for(int i = 0; i < numDat; i++)
		auxClientes[i] = buffClientes[i];
	clientes = auxClientes;
	muestraclientes(clientes);
}

void *leerCliente(ifstream &arch) {
	void **registro;
	int _dni, *dni;
	char *nombre;

	arch >> _dni;
	if(arch.eof()) return nullptr;
	arch.get();
	nombre = leerCadena(arch, 100, '\n');

	dni = new int;
	*dni = _dni;

	registro = new void*[2];
	registro[DNI] = dni;
	registro[NOMB] = nombre;

	return registro;
}

char *leerCadena(ifstream &arch, int size, char delim) {
	char *cadena, cad[size];
	arch.getline(cad, size, delim);
	if(arch.eof()) return nullptr;
	cadena = new char[strlen(cad) + 1];
	strcpy(cadena, cad);
	return cadena;
}

void creareserva(void *&reserva) {
	ifstream arch;
	AperturaDeUnArchivoDeTextosParaLeer(arch, "Libros.csv");
	void *buffReserva[300]{}, *registro, **auxReserva;
	int numDat = 0;
	while(true) {
		registro = leerLibro(arch);
		if(arch.eof()) break;
		buffReserva[numDat] = registro;
		numDat++;
	}
	// Recorto a memoria exacta
	auxReserva = new void*[numDat + 1]{};
	for(int i = 0; i < numDat; i++)
		auxReserva[i] = buffReserva[i];
	reserva = auxReserva;
	muestrareservas(reserva);
}

void *leerLibro(ifstream &arch) {
	void **registro;
	char *codigo, *nombre, *autor;
	int _stock, *stock;

	codigo = leerCadena(arch, 8, ',');
	if(arch.eof()) return nullptr;
	nombre = leerCadena(arch, 100, ',');
	autor = leerCadena(arch, 100, ',');
	arch >> _stock;
	while(arch.get() != '\n');  // Leo todo lo que sobra en la linea

	stock = new int;
	*stock = _stock;

	registro = new void*[5];
	registro[COD] = codigo;
	registro[TIT] = nombre;
	registro[AUT] = autor;
	// Espacios igual al stock y al inicio todos nullptr
	registro[PED] = new void*[_stock]{};
	registro[STK] = stock;

	return registro;
}

void cargareservar(void *clientes, void *&reserva) {
	ifstream arch;
	AperturaDeUnArchivoDeTextosParaLeer(arch, "Pedidos2.csv");
	void **auxClientes = (void**)clientes;
	void **auxReserva = (void**)reserva;
	int _dni, posCli, posLib, cantPed[300]{};
	char *codLib;
	while(true) {
		arch >> _dni;
		if(arch.eof()) break;
		arch.get();  // Leo la coma
		codLib = leerCadena(arch, 8, '\n');
		posLib = buscarLibro(codLib, reserva);
		if(posLib != -1) {
			posCli = buscarCliente(_dni, clientes);
			if(posCli != -1) {
				registrarPedido(auxReserva[posLib], auxClientes[posCli], _dni, cantPed[posLib]);
			}
		}
	}
}

int buscarLibro(char *codBuscado, void *reserva) {
	void **auxReserva = (void**)reserva;
	for(int i = 0; auxReserva[i]; i++) {
		void **registro = (void**)auxReserva[i];
		char *codLib = (char*)registro[COD];
		if(strcmp(codBuscado, codLib) == 0)
			return i;
	}
	return -1;
}

int buscarCliente(int dniBuscado, void *clientes) {
	void **auxClientes = (void**)clientes;
	for(int i = 0; auxClientes[i]; i++) {
		void **registro = (void**)auxClientes[i];
		int *dni = (int*)registro[DNI];
		int _dni = *dni;
		if(dniBuscado == _dni)
			return i;
	}
	return -1;
}

void registrarPedido(void *&reserva, void *cliente, int dniCli, int &cant) {
	void **regLib = (void**)reserva;
	int *stock = (int*)regLib[STK];
	int _stock = *stock;
	// Verifico que todavia haya stock de libros para entregar el pedido
	if(cant < _stock) {
		void **regCli = (void**)cliente;
		char *nombCli = (char*)regCli[NOMB];
		// Creo un nuevo espacio de memoria para el nombre y dni del cliente
		// que pidio dicho pedido
		char *nombre = new char[strlen(nombCli) + 1];
		strcpy(nombre, nombCli);
		int *dni = new int;
		*dni = dniCli;

		// Bajo un nivel al arreglo de pedidos por libro
		void **pedidos = (void**)regLib[PED];
		// Inserto el cliente que solicito el pedido en el arreglo de pedidos
		pedidos[cant] = insertarLibro(dni, nombre);

		// Aumento la cuenta de pedidos por libro
		cant++;
	}
}

void *insertarLibro(int *dni, char *nombre) {
	void **registro;
	registro = new void*[2]{};
	registro[DNI_PED] = dni;
	registro[NOMB_PED] = nombre;
	return registro;
}
