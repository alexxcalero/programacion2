// Nombre: Alex Calero Revilla
// Codigo: 20206455

import java.util.Scanner;

public class Principal {
	public static void main(String[] args) {
		Libreria lib = new Libreria();
		Scanner arch = new Scanner(System.in);
		
		lib.leerDatos(arch);     // Leo el nombre y la direccion de la libreria
		
		lib.leerLibros(arch);    // Inciso 1
		lib.leerClientes(arch);  // Inciso 2
		lib.leerVentas(arch);    // Inciso 3
		lib.calcularRanking();   // Inciso 4
		lib.imprimirReporte();   // Inciso 5: Estoy imprimiendo el resultado en ReporteDeVentas.txt
	}
}
