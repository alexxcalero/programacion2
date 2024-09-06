public class Circulo {
	private String id;
	private double radio;
	private final double PI = 3.141592;

	public Circulo() {
		id = "C00X";
		radio = 5;
	}

	public Circulo(String id, double radio) {
		this.id = id;
		this.radio = radio;
	}

	public void setId(String id) {
		this.id = id;
	}
	public String getId() {
		return id;
	}

	public void setRadio(double radio) {
		this.radio = radio;
	}
	public double getRadio() {
		return radio;
	}

	public double area() {
		return PI * radio * radio;
	}

	public double perimetro() {
		return 2 * PI * radio;
	}
}
