import java.util.ArrayList;
import java.util.Scanner;

public class Empresa {
	private ArrayList<Omnibus> flota;
	
	public Empresa() {
		flota = new ArrayList<Omnibus>();
	}
	
	public void cargarFlota(Scanner arch) {
		while(arch.hasNext()) {
			Omnibus omnibus = new Omnibus();
			if(omnibus.leerDatos(arch))
				flota.add(omnibus);
			else
				break;
		}
	}
	
	public void asignarPasajeros(Scanner arch) {
		String tipo;
		Pasajero pasajero;
		while(arch.hasNext()) {
			tipo = arch.next();
			if(tipo.compareTo("P") == 0)  // Es de primera clase
				pasajero = new PrimeraClase();
			else  // Es clase turista
				pasajero = new ClaseTurista();
			
			pasajero.leerDatos(arch);  // Leo los datos del pasajero
			
			for(Omnibus omnibus : flota) {
				if(omnibus.asignarPasajero(pasajero))
					break;  // Si se asigna en un bus, se corta la iteracion
			}
		}
	}
	
	public void emitirReporte() {
		System.out.println("EMPRESA DE TRANSPORTE TURISTICO");
		System.out.println();
		for(Omnibus omnibus : flota) {
			omnibus.imprimirDatos();
		}
	}
}
