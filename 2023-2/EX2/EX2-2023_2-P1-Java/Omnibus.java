import java.util.ArrayList;
import java.util.Scanner;

public class Omnibus {
	private String placa;
	private String chofer;
	private ArrayList<String> ruta;
	private int asientosPC;
	private int asientosCT;
	private ArrayList<Pasajero> pasajeros;
	
	public Omnibus() {
		ruta = new ArrayList<String>();
		pasajeros = new ArrayList<Pasajero>();
	}
	
	public int getAsientosPC() {
		return asientosPC;
	}
	public int getAsientosCT() {
		return asientosCT;
	}
	
	public boolean leerDatos(Scanner arch) {
		placa = arch.next();
		if(placa.compareTo("FIN") == 0)
			return false;
		chofer = arch.next();
		while(!arch.hasNextInt()) {  // Mientras que lo siguiente en leer no sea un entero
			String ciudad = arch.next();
			ruta.add(ciudad);
		}
		asientosPC = arch.nextInt();
		asientosCT = arch.nextInt();
		return true;
	}
	
	public boolean asignarPasajero(Pasajero pasajero) {
		String destino = pasajero.getDestino();
		String tipo = pasajero.getTipo();
		if(verificarDestinoEnRuta(destino)) {
			if(tipo.compareTo("P") == 0) {  // Es de primera clase
				if(asientosPC > 0) {  // Hay asientos disponibles
					pasajeros.add(pasajero);
					asientosPC--;
					return true;  // Retornamos true ni bien agregamos el pasajero a la lista
				}
				return false;  // Si no hay asientos disponibles retornamos falso
			} else {  // Es de clase turista
				if(asientosCT > 0) {  // Hay asientos disponibles
					pasajeros.add(pasajero);
					asientosCT--;
					return true;  // Retornamos true ni bien agregamos el pasajero a la lista
				}
				return false;  // Si no hay asientos disponibles retornamos falso
			}
		}
		return false;  // Si el destino no se encuentra en la ruta
	}
	
	public boolean verificarDestinoEnRuta(String destino) {
		for(String ciudad : ruta) {
			if(ciudad.compareTo(destino) == 0)
				return true;
		}
		return false;
	}
	
	public void imprimirDatos() {
		System.out.println("PLACA: " + placa);
		System.out.println("CHOFER: " + chofer);
		System.out.println("ASIENTOS PC LIBRES: " + asientosPC);
		System.out.println("ASIENTOS CT LIBRES: " + asientosCT);
		System.out.println("RUTA: ");
		for(String ciudad : ruta)
			System.out.print(ciudad + " ");
		System.out.println();
		System.out.println("PASAJEROS:");
		int cantPasajeros = 1;
		for(Pasajero pasajero : pasajeros) {
			System.out.print("  " + cantPasajeros + ".- ");
			pasajero.imprimirDatos();
			cantPasajeros++;
		}
		for(int i = 0; i < 80; i++)
			System.out.print("=");
		System.out.println();
		System.out.println();
	}
}
