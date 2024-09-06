import java.util.ArrayList;
import java.util.Scanner;

public class Libreria {
	private String nombre;
	private String direccion;
	private ArrayList<Libro> libros;
	private ArrayList<Cliente> clientes;
	private int cantidadVendida;
	private double totalVendido;
	
	public Libreria() {
		libros = new ArrayList<Libro>();
		clientes = new ArrayList<Cliente>();
		cantidadVendida = 0;
		totalVendido = 0.0;
	}
	
	public Libreria(String nombre, String direccion) {
		this.nombre = nombre;
		this.direccion = direccion;
		libros = new ArrayList<Libro>();
		clientes = new ArrayList<Cliente>();
		cantidadVendida = 0;
		totalVendido = 0.0;
	}
	
	// Leo los datos de la libreria y me salto las dos
	// primeras lineas del archivo VentasDeLibros.txt
	public void leerDatos(Scanner arch) {
		nombre = arch.next();
		direccion = arch.next();
	}
	
	public void leerLibros(Scanner arch) {
		while(arch.hasNext()) {
			Libro libro = new Libro();
			if(libro.leerDatos(arch))
				libros.add(libro);
			else
				break;
		}
	}
	
	public void leerClientes(Scanner arch) {
		while(arch.hasNext()) {
			Cliente cliente = new Cliente();
			if(cliente.leerDatos(arch))
				clientes.add(cliente);
			else
				break;
		}
	}
	
	public void leerVentas(Scanner arch) {
		int posLibro;
		String codLibro;
		while(arch.hasNext()) {
			codLibro = arch.next();
			posLibro = buscarLibro(codLibro);
			if(posLibro != -1) {
				Venta venta = new Venta();
				venta.leerDatos(arch);
				libros.get(posLibro).agregarVenta(venta);  // Metodo para agregar la venta al ArrayList
			}
		}
	}
	
	public int buscarLibro(String codLibro) {
		for(int i = 0; i < libros.size(); i++) {
			String codigo = libros.get(i).getCodigo();
			if(codigo.compareTo(codLibro) == 0)
				return i;
		}
		return -1;
	}
	
	public void calcularRanking() {
		for(Libro libro : libros)
			libro.calcularRaking();
	}
	
	public void imprimirReporte() {
		System.out.println(nombre);
		System.out.println(direccion);
		System.out.println("RESULTADO DE LAS VENTAS REALIZADAS:");
		System.out.println();
		imprimirLibros();
	}
	
	public void imprimirLibros() {
		int cant = 1;
		for(Libro libro : libros) {
			System.out.println("LIBRO NO. " + cant);
			libro.imprimirDatos(clientes);
			System.out.println();
			cant++;
		}
		System.out.println();
	}
}
