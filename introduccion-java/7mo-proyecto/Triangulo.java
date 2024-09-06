public class Triangulo extends Figura {
	public Triangulo(String id, double base, double altura) {
		super(id, base, altura);
	}

	@Override
	public void calcularArea() {
		System.out.println("Figura: Triangulo (" + getId() + ")");
		System.out.println("Formula = (Base x Altura)/2");
		System.out.println("Area = " + (getBase() * getAltura()) / 2);
	}
}
