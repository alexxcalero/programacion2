import java.util.Scanner;

public class Medico {
	private int codigo;
	private String nombre;
	private String especialidad;
	private double tarifa;
	private double tiempoTotal;
	private double ingresosTotales;
	private int cantidadDeConsultas;

	public Medico(int codigo, String nombre, String especialidad, double tarifa) {
		this.codigo = codigo;
		this.nombre  = nombre;
		this.especialidad = especialidad;
		this.tarifa = tarifa;
		tiempoTotal = 0.0;
		ingresosTotales = 0.0;
		cantidadDeConsultas = 0;
	}

	public Medico() {
		tiempoTotal = 0.0;
		ingresosTotales = 0.0;
		cantidadDeConsultas = 0;
	}

	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}
	public int getCodigo() {
		return codigo;
	}
	
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	public String getNombre() {
		return nombre;
	}
	
	public void setEspecialidad(String especialidad) {
		this.especialidad = especialidad;
	}
	public String getEspecialidad() {
		return especialidad;
	}
	
	public void setTarifa(double tarifa) {
		this.tarifa = tarifa;
	}
	public double getTarifa() {
		return tarifa;
	}
	
	public void setTiempoTotal(double tiempoTotal) {
		this.tiempoTotal = tiempoTotal;
	}
	public double getTiempoTotal() {
		return tiempoTotal;
	}
	
	public void setIngresosTotales(double ingresosTotales) {
		this.ingresosTotales = ingresosTotales;
	}
	public double getIngresosTotales() {
		return ingresosTotales;
	}
	
	public void setCantidadDeConsultas(int cantidadDeConsultas) {
		this.cantidadDeConsultas = cantidadDeConsultas;
	}
	public int getCantidadDeConsultas() {
		return cantidadDeConsultas;
	}

	// 50611  EDGAR_MUNOZ_VERGEL    Urologia  112.85
	public boolean leerDatos(Scanner arch) {
		codigo = arch.nextInt();
		if(codigo == 0) return false;
		nombre = arch.next();
		especialidad = arch.next();
		tarifa = arch.nextDouble();
		tiempoTotal = 0.0;
		ingresosTotales = 0.0;
		cantidadDeConsultas = 0;
		return true;
	}

	public void agregarConsulta(int tiempoIni, int tiempoFin) {
		double tiempo = (double)tiempoFin - tiempoIni;
		tiempo /= 60.0;
		tiempoTotal += tiempo;
		ingresosTotales += tiempo * tarifa;
		cantidadDeConsultas++;
	}

	public void imprimirDatos() {
		//System.out.println(codigo + " - " + nombre + " - " + especialidad + " - " + tarifa + " - " + tiempoTotal + " - " + ingresosTotales + " - " + cantidadDeConsultas);
		System.out.printf("%-10d %-40s %-20s %12.2f %12.2f %13.2f %6d \n", codigo, nombre, especialidad, tarifa, tiempoTotal, ingresosTotales, cantidadDeConsultas);
	}
}
