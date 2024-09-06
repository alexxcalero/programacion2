/*
 * Proyecto : EX2-2022_1-P2-STLPolimorfico
 * Archivo  : Programa.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 20 de junio de 2024, 19:22
 */

#include "Programa.h"

Programa::Programa() {
}

Programa::Programa(const Programa &orig) {
}

Programa::~Programa() {
}

void Programa::Carga() {
	CargaProductos();
	CargaLista();
}

void Programa::CargaProductos() {
	ifstream arch("Productos4.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Productos4.csv\n";
		exit(1);
	}
	int categoria;
	while(1) {
		arch >> categoria;
		if(arch.eof()) break;
		arch.get();
		NProducto producto;
		producto.asignarMemoria(categoria);
		arch >> producto;
		vproductos.push_back(producto);
	}
}

void Programa::CargaLista() {
	ifstream arch("Pedidos4.csv", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Productos4.csv\n";
		exit(1);
	}
	lpedidos.crear(arch);
}

void Programa::Actualiza() {
	for(NProducto producto : vproductos) {
		int prioridad = producto.obtenerPrioridad();
		if(prioridad == 1) {
			int codigo = producto.obtenerCodigo();
			lpedidos.reordenar(codigo);
		}
	}
}

void Programa::Imprime() {
	ImprimeProductos();
	ImprimeLista();
}

void Programa::ImprimeProductos() {
	ofstream arch("ReporteDeProductos.txt", ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ReporteDeProductos.txt\n";
		exit(1);
	}
	arch << setw(60) << "REPORTE DE PRODUCTOS" << endl << endl;
	imprimirEncabezadosDeProductos(arch);
	for(auto i : vproductos) {
		arch << i;
	}
}

void Programa::imprimirEncabezadosDeProductos(ofstream &arch) {
	arch << left << setw(10) << "CODIGO" << setw(46) << "NOMBRE" << setw(10) << "STOCK";
	arch << setw(10) << "CATEG." << setw(10) << "PRIO." << "DESC." << endl;
	imprimirLinea(arch, 100, '=');
}

void Programa::ImprimeLista() {
	ofstream arch("ReporteDePedidos.txt", ios::out);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo ReporteDePedidos.txt\n";
		exit(1);
	}
	arch << setw(60) << "PROGRAMA DE PEDIDOS" << endl << endl;
	imprimirEncabezadosDePedidos(arch);
	lpedidos.imprimir(arch);
}

void Programa::imprimirEncabezadosDePedidos(ofstream &arch) {
	arch << left << setw(18) << "Fecha" << setw(27) << "Codigo del Producto";
	arch << setw(20) << "Cantidad" << setw(10) << "Monto" << "Prioridad" << endl;
	imprimirLinea(arch, 100, '=');
}

void Programa::imprimirLinea(ofstream &arch, int cant, char c) {
	for(int i = 0; i < cant; i++)
		arch << c;
	arch << endl;
}
