import java.util.Scanner;

public abstract class Pasajero {
	private int dni;
	private String nombre;
	private String destino;
	
	public String getDestino() {
		return destino;
	}
	
	public void leerDatos(Scanner arch) {
		dni = arch.nextInt();
		nombre = arch.next();
		destino = arch.next();
	}
	
	public abstract String getTipo();
	
	public void imprimirDatos() {
		System.out.println("DNI: " + dni + " NOMBRE: " + nombre + " DESTINO: " + destino);
	}
}
