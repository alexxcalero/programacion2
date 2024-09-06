import java.util.ArrayList;
import java.util.Scanner;

public class PrimeraClase extends Pasajero {
	private ArrayList<String> articulosSolicitados;
	
	public PrimeraClase() {
		articulosSolicitados = new ArrayList<String>();
	}
	
	@Override
	public void leerDatos(Scanner arch) {
		super.leerDatos(arch);
		int cantArticulos = arch.nextInt();
		for(int i = 0; i < cantArticulos; i++) {
			String articulos = arch.next();
			articulosSolicitados.add(articulos);
		}
	}
	
	@Override
	public String getTipo() {
		return "P";
	}
	
	@Override
	public void imprimirDatos() {
		super.imprimirDatos();
		System.out.print("    PRIMERA CLASE - EXTRAS: ");
		for(String articulo : articulosSolicitados)
			System.out.print(articulo + " ");
		System.out.println();
	}
}
