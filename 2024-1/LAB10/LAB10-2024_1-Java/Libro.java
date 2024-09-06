import java.util.ArrayList;
import java.util.Scanner;

public class Libro {
	private String codigo;
	private String titulo;
	private String autor;
	private double precio;
	private ArrayList<Venta> ventas;
	private int suma;
	private int ranking;
	private double totalVendido;
	
	public Libro() {
		ventas = new ArrayList<Venta>();
		suma = 0;
		ranking = 0;
		totalVendido = 0.0;
	}
	
	public Libro(String codigo, String titulo, String autor, double precio) {
		this.codigo = codigo;
		this.titulo = titulo;
		this.autor = autor;
		this.precio = precio;
		ventas = new ArrayList<Venta>();
		suma = 0;
		ranking = 0;
		totalVendido = 0.0;
	}
	
	public void setCodigo(String codigo) {
		this.codigo = codigo;
	}
	public String getCodigo() {
		return codigo;
	}
	
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}
	public String getTitulo() {
		return titulo;
	}
	
	public void setAutor(String autor) {
		this.autor = autor;
	}
	public String getAutor() {
		return autor;
	}
	
	public void setPrecio(double precio) {
		this.precio = precio;
	}
	public double getPrecio() {
		return precio;
	}
	
	public void setSuma(int suma) {
		this.suma = suma;
	}
	public int getSuma() {
		return suma;
	}
	
	public void setRanking(int ranking) {
		this.ranking = ranking;
	}
	public int getRanking() {
		return ranking;
	}
	
	public void setTotalVendido(double totalVendido) {
		this.totalVendido = totalVendido;
	}
	public double getTotalVendido() {
		return totalVendido;
	}
	
	public boolean leerDatos(Scanner arch) {
		codigo = arch.next();
		if(codigo.compareTo("FIN") == 0)
			return false;
		titulo = arch.next();
		autor = arch.next();
		precio = arch.nextDouble();
		suma = 0;
		ranking = 0;
		totalVendido = 0.0;
		return true;
	}
	
	// Pasamos la venta como parametro y la agregamos al ArrayList de ventas del libro
	public void agregarVenta(Venta venta) {
		suma += venta.getCalificacion();
		totalVendido += precio;  // Voy aumentando el precio del libro xq significa que hemos realizado una venta
		ventas.add(venta);
	}
	
	public void calcularRaking() {
		if(ventas.size() > 0) {  // Evitamos el dividir entre cero
			int totalVentas = ventas.size();
			int promedio = suma / totalVentas;
			if(promedio < 25) ranking = 1;
			else if(promedio < 50) ranking = 2;
			else if(promedio < 75) ranking = 3;
			else ranking = 4;
		} else {  // No se vendio nada
			ranking = 0;
		}
	}
	
	public void imprimirDatos(ArrayList<Cliente> clientes) {
		System.out.println("CODIGO: " + codigo + " TITULO: " + titulo + " AUTOR: " + autor + " PRECIO: " + precio);
		System.out.println("LIBROS VENDIDOS: " + ventas.size() + " RANKING: " + ranking);
		if(ventas.size() > 0) {  // Verifico que se hayan vendido libros para mostrar los datos de cada venta
			System.out.println();
			System.out.println("VENTAS REALIZADAS:");
			int cant = 1;
			for(Venta venta : ventas) {
				System.out.print("No. " + cant + " DNI: " + venta.getDni());
				String nombreCliente = obtenerNombreDelCliente(venta.getDni(), clientes);
				System.out.print(" NOMBRE: " + nombreCliente);
				System.out.println(" CALIFICACION: " + venta.getCalificacion());
				cant++;
			}
		}
	}
	
	public String obtenerNombreDelCliente(int dni, ArrayList<Cliente> clientes) {
		for(Cliente cliente : clientes)
			if(cliente.getDni() == dni)
				return cliente.getNombre();
		return "";  // En caso no lo encuentre, ademas, no compila sin esta linea
	}
}
