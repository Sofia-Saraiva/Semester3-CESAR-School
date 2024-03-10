package informatica;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner INPUT = new Scanner(System.in);
		
		System.out.println("Dados do UCP");
		System.out.println("Clock base: ");
		double clockBase = INPUT.nextDouble();
		
		System.out.println("Fator turbo: ");
		double fatorTurbo = INPUT.nextDouble();
		INPUT.nextLine();
		
		System.out.println("Dados do modelo");
		System.out.println("Descrição: ");
		String descricao = INPUT.nextLine();
		
		System.out.println("Marca: ");
		String marca = INPUT.nextLine();
		
		System.out.println("Dados do computador: ");
		System.out.println("Capacidade RAM em GB: ");
		int capacidadeRamEmGb = INPUT.nextInt();
		System.out.println("Capacidade Disco em GB: ");
		int capacidadeDiscoEmGb = INPUT.nextInt();
		System.out.println("É notebook (true/false): ");
		boolean ehNotebook = INPUT.nextBoolean();
		
		Modelo modelo = new Modelo(descricao, marca);
		UCP ucp = new UCP(clockBase, fatorTurbo, modelo);
		Computador computador = new Computador(ucp, modelo, capacidadeRamEmGb, capacidadeDiscoEmGb, ehNotebook);
		
		System.out.println("Clock máximo: "+ucp.calcularClockMaximo());
		System.out.println("Descrição: "+computador.obterDescricaoPormenorizada());
	}

}
