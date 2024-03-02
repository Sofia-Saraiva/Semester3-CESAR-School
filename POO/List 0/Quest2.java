package cursoPOO;
import java.util.Scanner;

public class Quest2 {

	public static void main(String[] args) {
		
		float numero;
		do {
			Scanner num = new Scanner(System.in);
			numero = num.nextFloat();
			
			if (numero < 2 || numero > 20) {
				System.out.println(numero);
			}
		} while (numero != 1);

	}

}
