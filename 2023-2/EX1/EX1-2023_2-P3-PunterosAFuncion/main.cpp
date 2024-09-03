/*
 * Proyecto : EX1-2023_2-P3-PunterosAFuncion
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de mayo de 2024, 01:08
 */

#include "Pregunta1.h"
#include "Pregunta2.h"
#include "ColaGenerica.h"
#include "ColaConEnteros.h"
#include "ColaConProductos.h"

int main(int argc, char** argv) {
	char **codigoDelProducto;
	int **fechaClienteCantidad;
	void *productos;
	void *cola;

	cargarPedidos(fechaClienteCantidad, codigoDelProducto, "Pedidos.csv");
	pruebaDeCargaDePedidos(fechaClienteCantidad, codigoDelProducto, "PruebaPedidos.txt");
	cargarProductos(productos, "Productos.csv");
	pruebaDeCargaDeProductos(productos);

	cargaEnteros(cola, leenumero, "Numeros.txt");
	mostrarEnteros(cola, imprimenumero, "ReporteNumeros.txt");
	procesarPedidos(fechaClienteCantidad, codigoDelProducto, productos);
	reporteDePedidos(productos, "ReporteFinal.txt");

	return 0;
}
