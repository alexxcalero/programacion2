public class Herencia {
	public static void main(String[] args) {
		Circulo circulo = new Circulo("Circulo A", 56.75);
		System.out.println("Objeto:    " + circulo.getId());
		System.out.println("Radio:     " + circulo.getRadio());
		System.out.println("Area:      " + circulo.area());
		System.out.println("Perimetro: " + circulo.perimetro());
		System.out.println();

		Cilindro cilindro = new Cilindro("Cilindro A", 11.90, 25.77);
		System.out.println("Objeto:                " + cilindro.getId());
		System.out.println("Radio:                 " + cilindro.getRadio());
		System.out.println("Altura:                " + cilindro.getAltura());
		System.out.println("Volumen:               " + cilindro.volumen());
		System.out.println("Area de la base:       " + cilindro.areaDeLaBase());
		System.out.println("Area de la superficie: " + cilindro.area());
	}
}
