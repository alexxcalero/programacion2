public class Cuadrado extends Figura {
	public Cuadrado(String id, double base, double altura) {
		super(id, base, altura);
	}

	@Override
	public void calcularArea() {
		System.out.println("Figura: Cuadrado (" + getId() + ")");
		System.out.println("Formula = Base x Altura");
		System.out.println("Area = " + getBase() * getAltura());
	}
}
