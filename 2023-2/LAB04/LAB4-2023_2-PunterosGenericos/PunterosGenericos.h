/*
 * Proyecto : LAB4-2023_2-PunterosGenericos
 * Archivo  : PunterosGenericos.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 25 de abril de 2024, 21:54
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#include <fstream>
using namespace std;

enum Prod {COD, DESC, PREC, TIPO};
enum Cli {DNI, NOMB, LIST_PED, CRED};
enum Ped {COD_PROD, CANT, TOTAL};

void cargaproductos(void *&productos);
void *leerProducto(ifstream &arch);
char *leerCadena(ifstream &arch, int size, char delim);
void memoriaExacta(void *&arreglo, void **buffArrEstatico, int numDat);
void cargaclientes(void *&clientes);
void *leerCliente(ifstream &arch);
void cargapedidos(void *productos, void *&clientes);
int buscarCliente(int dniCli, void *c);
int buscarProducto(char *codProd, void *p);
void registrarPedido(void *&cliente, void *producto, char *cod, int cantSol, int &cantPed);
void *insertarPedido(char *cod, int cantSol, double total);
void recortarEspacios(void *&clientes, int *cantPed);

#endif /* PUNTEROSGENERICOS_H */
