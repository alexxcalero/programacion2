import java.util.Scanner;

public class Cliente {
	private int dni;
	private String nombre;
	private double totalGastado;
	
	public Cliente() {
		totalGastado = 0.0;
	}
	
	public Cliente(int dni, String nombre) {
		this.dni = dni;
		this.nombre = nombre;
		totalGastado = 0.0;
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
	
	public void setTotalGastado(double totalGastado) {
		this.totalGastado = totalGastado;
	}
	public double getTotalGastado() {
		return totalGastado;
	}
	
	public boolean leerDatos(Scanner arch) {
		dni = arch.nextInt();
		if(dni == 0)
			return false;
		nombre = arch.next();
		totalGastado = 0.0;
		return true;
	}
	
	public void imprimirDatos() {
		System.out.println(nombre);  // Solo necesito imprimir el nombre en el reporte
	}
}
