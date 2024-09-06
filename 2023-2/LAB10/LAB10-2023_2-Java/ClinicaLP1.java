import java.util.Scanner;
import java.util.ArrayList;

public class ClinicaLP1 {
	private ArrayList<Medico> medicos;
	private ArrayList<Paciente> pacientes;

	public ClinicaLP1() {
		medicos = new ArrayList<Medico>();
		pacientes = new ArrayList<Paciente>();
	}

	public void leerMedicos(Scanner arch) {
		Medico medico;
		while(arch.hasNext()) {
			medico = new Medico();
			if(medico.leerDatos(arch))
				medicos.add(medico);
			if(medico.getCodigo() == 0) break;
		}
	}

	public void leerPacientes(Scanner arch) {
		Paciente paciente;
		while(arch.hasNext()) {
			paciente = new Paciente();
			if(paciente.leerDatos(arch))
				pacientes.add(paciente);
			if(paciente.getDni() == 0) break;
		}
	}

	//   DNI       COD  HI  MI   SI HF    MF    SF
	// 94683380   60934 12  27   11 13    51    17
	public void leerConsultas(Scanner arch) {
		int dni, cod, posPaciente, posMedico;
		int horaIni, minIni, segIni, tiempoIni;
		int horaFin, minFin, segFin, tiempoFin;
		while(arch.hasNext()) {
			dni = arch.nextInt();
			posPaciente = buscarPaciente(dni);
			if(posPaciente != -1) {
				cod = arch.nextInt();
				posMedico = buscarMedico(cod);
				if(posMedico != -1) {
					horaIni = arch.nextInt();
					minIni = arch.nextInt();
					segIni = arch.nextInt();
					tiempoIni = horaIni * 3600 + minIni * 60 + segIni;
					horaFin = arch.nextInt();
					minFin = arch.nextInt();
					segFin = arch.nextInt();
					tiempoFin = horaFin * 3600 + minFin * 60 + segFin;
					pacientes.get(posPaciente).agregarConsulta(tiempoIni, tiempoFin, medicos.get(posMedico).getTarifa());
					medicos.get(posMedico).agregarConsulta(tiempoIni, tiempoFin);
				}
			}
		}
	}

	public int buscarPaciente(int dni) {
		for(int i = 0; i < pacientes.size(); i++)
			if(pacientes.get(i).getDni() == dni)
				return i;
		return -1;
	}

	public int buscarMedico(int codigo) {
		for(int i = 0; i < medicos.size(); i++)
			if(medicos.get(i).getCodigo() == codigo)
				return i;
		return -1;
	}

	public void imprimirReporteDeMedicos() {
		System.out.printf("%70s \n", "REPORTE DE MEDICOS");
		imprimirLinea(122, '=');
		for(Medico m : medicos)
			m.imprimirDatos();
	}

	public void imprimirReporteDePacientes() {
		System.out.printf("%70s \n", "REPORTE DE PACIENTES");
		imprimirLinea(118, '=');
		for(Paciente p : pacientes)
			p.imprimirDatos();
	}

	public void imprimirLinea(int cant, char c) {
		for(int i = 0; i < cant; i++)
			System.out.print(c);
		System.out.println();
	}
}
