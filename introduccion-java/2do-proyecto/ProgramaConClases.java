public class ProgramaConClases {
	public static void main(String[] args) {
		Persona persona1, persona2, persona3;

		persona1 = new Persona(12345678, "Alex Calero Revilla", 'M', 1050, true);
		System.out.print("Persona 1: ");
		persona1.imprimirDatos();

		persona2 = new Persona();
		persona2.setDni(23456789);
		persona2.setNombre("Mathias Benites");
		persona2.setSexo('M');
		persona2.setSueldo(1400);
		persona2.setActivo(true);
		System.out.print("Persona 2: ");
		persona2.imprimirDatos();

		// Hay que tener cuidado con la asignacion de objetos,
		// ya que estos por detras son punteros
		// persona3 = persona1;
		// persona3.setDni(99999999);
		// System.out.println();
		// System.out.print("Persona 1: ");
		// persona1.imprimirDatos();
		// System.out.print("Persona 3: ");
		// persona3.imprimirDatos();

		// Se hace uso del constructor copia y ya no hay problema
		persona3 = new Persona(persona1);
		persona3.setDni(34567890);
		persona3.setNombre("Lionel Messi Cuccittini");
		System.out.println();
		System.out.print("Persona 1: ");
		persona1.imprimirDatos();
		System.out.print("Persona 3: ");
		persona3.imprimirDatos();
	}
}
