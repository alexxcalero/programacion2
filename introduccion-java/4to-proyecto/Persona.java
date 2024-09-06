import java.util.Scanner;

public class Persona {
	// Atributos
	private int dni;
	private String nombre;
	private char sexo;
	private double sueldo;
	private boolean activo;

	// Constructores
	public Persona() {
		dni = 0;
		sueldo = 0.0;
		activo = false;
	}

	public Persona(int dni, String nombre, char sexo, double sueldo, boolean activo) {
		this.dni = dni;
		this.nombre = nombre;
		this.sexo = sexo;
		this.sueldo = sueldo;
		this.activo = activo;
	}

	public Persona(Persona persona) {
		asignarDatos(persona);
	}

	// EN JAVA NO SE IMPLEMENTAN DESTRUCTORES

	// Setters y getters
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

	public void setSexo(char sexo) {
		this.sexo = sexo;
	}
	public char getSexo() {
		return sexo;
	}

	public void setSueldo(double sueldo) {
		this.sueldo = sueldo;
	}
	public double getSueldo() {
		return sueldo;
	}

	public void setActivo(boolean activo) {
		this.activo = activo;
	}
	public boolean getActivo() {
		return activo;
	}

	// Metodos
	public void imprimirDatos() {
		System.out.println(dni + " - " + sexo + " - " + nombre + " - " + sueldo + " - " + activo);
	}

	public void asignarDatos(Persona persona) {
		this.dni = persona.dni;
		this.nombre = persona.nombre;
		this.sexo = persona.sexo;
		this.sueldo = persona.sueldo;
		this.activo = persona.activo;
	}

	public void leerDatos(Scanner sc) {
		// 37870823  M SAENZ_ARANDA_WILMER  23455.60
		String aux;
		dni = sc.nextInt();
		aux = sc.next();
		sexo = aux.charAt(0);
		nombre = sc.next();
		sueldo = sc.nextDouble();
		if(sueldo > 50000.0)
			activo = true;
	}
}
