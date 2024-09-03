/*
 * Proyecto : LAB4-2024_1-PunterosGenericos
 * Archivo  : PunterosGenericos.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de abril de 2024, 08:06
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#include <fstream>
using namespace std;

enum Cli {DNI, NOMB};
enum Lib {COD, TIT, AUT, PED, STK};
enum Ped {DNI_PED, NOMB_PED};

void cargaclientes(void *&clientes);
void *leerCliente(ifstream &arch);
char *leerCadena(ifstream &arch, int size, char delim);
void creareserva(void *&reserva);
void *leerLibro(ifstream &arch);
void cargareservar(void *clientes, void *&reserva);
int buscarLibro(char *codBuscado, void *reserva);
int buscarCliente(int dniBuscado, void *clientes);
void registrarPedido(void *&reserva, void *cliente, int dniCli, int &cant);
void *insertarLibro(int *dni, char *nombre);

#endif /* PUNTEROSGENERICOS_H */
