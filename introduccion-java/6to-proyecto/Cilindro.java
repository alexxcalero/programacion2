public class Cilindro extends Circulo {
	private double altura;

	public Cilindro(String id, double radio, double altura) {
		super(id, radio);
		this.altura = altura;
	}

	public void setAltura(double altura) {
		this.altura = altura;
	}

	public double getAltura() {
		return altura;
	}

	@Override
	public double area() {
		return 2 * super.area() + perimetro() * altura;
	}

	public double areaDeLaBase() {
		return super.area();
	}

	public double volumen() {
		return super.area() * altura;
	}
}
