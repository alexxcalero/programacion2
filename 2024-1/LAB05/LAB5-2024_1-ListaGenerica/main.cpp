/*
 * Proyecto : LAB5-2024_1-ListaGenerica
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 3 de mayo de 2024, 08:05
 */

#include "FuncionesEnteras.h"
#include "BibliotecaGenerica.h"
#include "FuncionesRegistros.h"

int main(int argc, char** argv) {
	void *pedidos1, *pedidos2, *pedidosfinal;

	crealista(pedidos1, leenum, "RegistroNum1.txt");
	imprimelista(pedidos1, imprimenum, "ReporteNum1.txt");
	crealista(pedidos2, leenum, "RegistroNum2.txt");
	imprimelista(pedidos2, imprimenum, "ReporteNum2.txt");
	combinalista(pedidos1, pedidos2, pedidosfinal, cmpnum);
	imprimelista(pedidosfinal, imprimenum, "ReporteNumFinal.txt");

	crealista(pedidos1, leeregistro, "Pedidos31.csv");
	imprimelista(pedidos1, imprimeregistro, "ReporteReg1.txt");
	crealista(pedidos2, leeregistro, "Pedidos32.csv");
	imprimelista(pedidos2, imprimeregistro, "ReporteReg2.txt");
	combinalista(pedidos1, pedidos2, pedidosfinal, cmpregistro);
	imprimelista(pedidosfinal, imprimeregistro, "ReporteRegFinal.txt");

	return 0;
}
