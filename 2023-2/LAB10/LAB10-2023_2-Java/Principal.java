// Nombre: Alex Calero Revilla
// Codigo: 20206455

import java.util.Scanner;

public class Principal {
	public static void main(String[] args) {
		ClinicaLP1 clinica = new ClinicaLP1();
		Scanner arch = new Scanner(System.in);

		clinica.leerMedicos(arch);
		clinica.leerPacientes(arch);
		clinica.leerConsultas(arch);

		// Se tiene que compilar y correr dos veces el programa para generar los diferentes reportes,
		// descomentando y comentando las lineas correspondientes a los reportes de medicos y pacientes.
		//clinica.imprimirReporteDeMedicos();
		clinica.imprimirReporteDePacientes();
	}
}
