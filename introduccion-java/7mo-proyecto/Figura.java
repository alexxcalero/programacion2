public abstract class Figura {
	private String id;
	private double base;
	private double altura;

	public Figura(String id, double base, double altura) {
		this.id = id;
		this.base = base;
		this.altura = altura;
	}

	public void setId(String id) {
		this.id = id;
	}
	public String getId() {
		return id;
	}

	public void setBase(double base) {
		this.base = base;
	}
	public double getBase() {
		return base;
	}

	public void setAltura(double altura) {
		this.altura = altura;
	}
	public double getAltura() {
		return altura;
	}

	public abstract void calcularArea();
}
