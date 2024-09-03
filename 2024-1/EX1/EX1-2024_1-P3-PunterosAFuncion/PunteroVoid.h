/*
 * Proyecto : EX1-2024_1-P2-PunterosGenericos
 * Archivo  : PunteroVoid.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de mayo de 2024, 09:39
 */

#ifndef PUNTEROVOID_H
#define PUNTEROVOID_H

#define NO_ENCONTRADO -1

void cargaventas(char ***libro, void *&ventas);
void *insertarDatosVentas(char *codigo, char *nombre, char *autor);
void actualizaventas(int **ventasDniFechaPuntaje, char **ventasLibroCodigo, void *&ventas);
int buscarLibro(char *codLib, char **libros);

#endif /* PUNTEROVOID_H */
