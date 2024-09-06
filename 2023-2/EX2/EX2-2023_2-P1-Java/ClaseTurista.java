import java.util.Scanner;

public class ClaseTurista extends Pasajero {
	private boolean valija;
	private boolean almuerzo;
	private double tarifaExtra;  // 85.5 para valija y 55.90 para almuerzo
	
	public ClaseTurista() {
		tarifaExtra = 0.0;
	}
	
	@Override
	public void leerDatos(Scanner arch) {
		super.leerDatos(arch);
		String llevaValija = arch.next();
		String llevaAlmuerzo = arch.next();
		
		if(llevaValija.compareTo("S") == 0) {
			valija = true;
			tarifaExtra += 85.50;
		}
		else
			valija = false;
		
		if(llevaAlmuerzo.compareTo("S") == 0) {
			almuerzo = true;
			tarifaExtra += 55.90;
		}
		else
			almuerzo = false;
	}
	
	@Override
	public String getTipo() {
		return "T";
	}
	
	@Override
	public void imprimirDatos() {
		super.imprimirDatos();
		System.out.print("    CLASE TURISTA");
		if(valija || almuerzo) System.out.print(" - EXTRAS: ");
		if(valija) System.out.print("VALIJA ");
		if(almuerzo) System.out.print("ALMUERZO ");
		System.out.println(" - TARIFA EXTRA: " + tarifaExtra);
	}
}
