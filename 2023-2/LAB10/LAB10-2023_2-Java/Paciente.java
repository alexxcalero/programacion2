import java.util.Scanner;

public class Paciente {
	private int dni;
	private String nombre;
	private String distrito;
	private double tiempoTotal;
	private double gastosTotales;
	private int cantidadDeConsultas;

	public Paciente(int dni, String nombre, String distrito) {
		this.dni = dni;
		this.nombre = nombre;
		this.distrito = distrito;
		tiempoTotal = 0.0;
		gastosTotales = 0.0;
		cantidadDeConsultas = 0;
	}

	public Paciente() {
		tiempoTotal = 0.0;
		gastosTotales = 0.0;
		cantidadDeConsultas = 0;
	}

	public void setDni(int dni) {
		this.dni = dni;
	}
	public int getDni() {
		return dni;
	}
	
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	public String getNombre() {
		return nombre;
	}
	
	public void setDistrito(String distrito) {
		this.distrito = distrito;
	}
	public String getDistrito() {
		return distrito;
	}
	
	public void setTiempoTotal(double tiempoTotal) {
		this.tiempoTotal = tiempoTotal;
	}
	public double getTiempoTotal() {
		return tiempoTotal;
	}
	
	public void setGastosTotales(double gastosTotales) {
		this.gastosTotales = gastosTotales;
	}
	public double getGastosTotales() {
		return gastosTotales;
	}
	
	public void setCantidadDeConsultas(int cantidadDeConsultas) {
		this.cantidadDeConsultas = cantidadDeConsultas;
	}
	public int getCantidadDeConsultas() {
		return cantidadDeConsultas;
	}

	// 45201670  ROCIO_YOLANDA_ACUNA_YINO Santa_Anita
	public boolean leerDatos(Scanner arch) {
		dni = arch.nextInt();
		if(dni == 0) return false;
		nombre = arch.next();
		distrito = arch.next();
		tiempoTotal = 0.0;
		gastosTotales = 0.0;
		cantidadDeConsultas = 0;
		return true;
	}

	public void agregarConsulta(int tiempoIni, int tiempoFin, double tarifa) {
		double tiempo = (double)tiempoFin - tiempoIni;
		tiempo /= 60.0;
		tiempoTotal += tiempo;
		gastosTotales += tiempo * tarifa;
		cantidadDeConsultas++;
	}

	public void imprimirDatos() {
		//System.out.println(dni + " - " + nombre + " - " + distrito + " - " + tiempoTotal + " - " + gastosTotales + " - " + cantidadDeConsultas);
		System.out.printf("%-12d %-40s %-25s %12.2f %15.2f %6d \n", dni, nombre, distrito, tiempoTotal, gastosTotales, cantidadDeConsultas);
	}
}
