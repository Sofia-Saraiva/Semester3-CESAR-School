package informatica;

public class Computador {
	UCP ucp;
	Modelo modelo;
	int capacidadeRamEmGb;
	int capacidadeDiscoEmGb;
	boolean ehNotebook;
	
	Computador(UCP ucp, Modelo modelo, 
			int capacidadeRamEmGb, int capacidadeDiscoEmGb, boolean ehNotebook) {
		this.ucp = ucp;
		this.modelo = modelo;
		this.capacidadeRamEmGb = capacidadeRamEmGb;
		this.capacidadeDiscoEmGb = capacidadeDiscoEmGb;
		this.ehNotebook = ehNotebook;
	}
	
	String obterDescricaoPormenorizada() {
		String NoteDesk;
		if (ehNotebook) {
			NoteDesk = "Notebook";
		}
		else {
			NoteDesk = "Desktop";
		}
		
		return NoteDesk+" com processador "+modelo.marca+" "+modelo.descricao+" , "+capacidadeRamEmGb+" GB , "+capacidadeDiscoEmGb+" GB de disco.";
	}
}
