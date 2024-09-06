import java.util.Scanner;

public class RedireccionamientoConClases {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Persona persona = new Persona();
		while(sc.hasNext()) {
			persona.leerDatos(sc);
			persona.imprimirDatos();
		}
	}
}
