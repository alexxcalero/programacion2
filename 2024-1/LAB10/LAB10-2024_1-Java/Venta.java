import java.util.Scanner;

public class Venta {
	private int dni;
	private int fecha;
	private int calificacion;
	
	public Venta() {
		fecha = 0;
		calificacion = 0;
	}
	
	public Venta(int dni, int fecha, int calificacion) {
		this.dni = dni;
		this.fecha = fecha;
		this.calificacion = calificacion;
	}
	
	public void setDni(int dni) {
		this.dni = dni;
	}
	public int getDni() {
		return dni;
	}
	
	public void setFecha(int fecha) {
		this.fecha = fecha;
	}
	public int getFecha() {
		return fecha;
	}
	
	public void setCalificacion(int calificacion) {
		this.calificacion = calificacion;
	}
	public int getCalificacion() {
		return calificacion;
	}
	
	public void leerDatos(Scanner arch) {
		int dia, mes, anho;
		
		dni = arch.nextInt();
		
		dia = arch.nextInt();
		mes = arch.nextInt();
		anho = arch.nextInt();
		
		fecha = anho * 10000 + mes * 100 + dia;
		
		calificacion = arch.nextInt();
	}
}
