/*
 * Proyecto : EX1-2023_2-P3-PunterosAFuncion
 * Archivo  : ColaConProductos.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 02:59
 */

#ifndef COLACONPRODUCTOS_H
#define COLACONPRODUCTOS_H

#include <fstream>
using namespace std;

void procesarPedidos(int **fechaClienteCantidad, char **codigoDelProducto, void *&productos);
int buscarProducto(char *codProd, void *productos);
void reporteDePedidos(void *productos, const char *nombArch);
void imprimirDatos(ofstream &arch, void *dato);
void imprimirPedidos(ofstream &arch, void *cola);

#endif /* COLACONPRODUCTOS_H */
