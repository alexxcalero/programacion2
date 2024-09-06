import java.util.Scanner;

public class Principal {
	public static void main(String[] args) {
		Empresa empresa = new Empresa();
		Scanner arch = new Scanner(System.in);
		
		empresa.cargarFlota(arch);
		empresa.asignarPasajeros(arch);
		empresa.emitirReporte();
		
	}
}
