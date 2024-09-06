import java.util.Scanner;

public class RedireccionamientoES {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);  // La entrada de datos sera por consola
		int dni;
		String nombre, aux;
		char sexo;
		double sueldo;
		while(sc.hasNext()) {  // hasNext() devuelve un booleando que indica si hay algo mas que leer o no
			// 37870823  M SAENZ_ARANDA_WILMER  23455.60
			dni = sc.nextInt();
			aux = sc.next();  // En aux, se lee el caracter como String
			sexo = aux.charAt(0);  // En sexo, se guarda el caracter leido en aux
			nombre = sc.next();
			sueldo = sc.nextDouble();
			System.out.println(dni + " - " + sexo + " - " + nombre + " - " + sueldo);
		}
	}
}
