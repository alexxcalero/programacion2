import java.util.Scanner;
import java.util.ArrayList;

public class ListaDePersonas {
	private ArrayList<Persona> listaDePersonas;

	public ListaDePersonas() {
		listaDePersonas = new ArrayList<Persona>();
	}

	public void leerPersonas() {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			Persona persona = new Persona();
			persona.leerDatos(sc);
			listaDePersonas.add(persona);
		}
	}

	public void mostrarPersonas() {
		for(Persona p : listaDePersonas)
			p.imprimirDatos();
	}
}
