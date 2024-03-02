package cursoPOO;
import java.util.Scanner;

public class Quest5 {

	public static void main(String[] args) {
		float numero;
		while (true) {
			Scanner num = new Scanner(System.in);
			numero = num.nextFloat();
			if (numero == 1) {
				break;
			}
			else {
				if (numero < 2 || numero > 20) {
					System.out.println(numero);
				}
			}
		}
	}

}
