package cursoPOO;
import java.util.Scanner;

public class Quest1 {

	public static void main(String[] args) {
		Scanner num = new Scanner(System.in);
		System.out.println("Digite um número");
		
		int numero = num.nextInt();
		
		if (numero < 0) {
			System.out.println("número menor que zero");
		}
		else {
			for (int i = 0; i <= numero; i+=2) {
				System.out.println(i);
			}
		}

	}

}
