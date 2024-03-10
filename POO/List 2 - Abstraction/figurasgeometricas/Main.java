package figurasgeometricas;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner INPUT = new Scanner(System.in);
		System.out.println("1- triangular\n2- retangular ou quadrado\n3- circular");
		int forma = INPUT.nextInt();
		
		System.out.println("Valor por metro quadrado: ");
		double valorPorMetroQuadrado = INPUT.nextDouble();
		
		System.out.println("CEP: ");
		long cep = INPUT.nextLong();
		INPUT.nextLine();
		
		System.out.println("Logradouro: ");
		String logradouro = INPUT.nextLine();
		
		System.out.println("Número: ");
		int numero = INPUT.nextInt();
		
		System.out.println("Complemento: ");
		String complemento = INPUT.nextLine();
		INPUT.nextLine();
		
		Endereco endereco = new Endereco(cep, logradouro, numero, complemento);
		Terreno terreno = new Terreno(valorPorMetroQuadrado, endereco);
		
		double area = 0;
		
		switch (forma) {
		case 1:
			System.out.println("Lados do triângulo: ");
			double l1 = INPUT.nextDouble();
			double l2 = INPUT.nextDouble();
			double l3 = INPUT.nextDouble();
			Triangulo triangulo = new Triangulo(l1, l2, l3);
			area = triangulo.calcularArea();
			
			break;
		case 2:
			System.out.println("Base e altura: ");
			double base = INPUT.nextDouble();
			double altura = INPUT.nextDouble();
			Paralelogramo paralelogramo = new Paralelogramo(base, altura);
			area = paralelogramo.calcularArea();
			break;
		case 3:
			System.out.println("Raio: ");
			double raio = INPUT.nextDouble();
			Circulo circulo = new Circulo(raio);
			area = circulo.calcularArea();
			break;
		default:
			System.out.println("TIPO ERRADO");
			break;
		}
		
		System.out.println("Área: "+area);
		System.out.println("Valor do terreno: "+terreno.calcularValorTerreno(area, valorPorMetroQuadrado));
		
	}

}
