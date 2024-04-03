package JavaEstruturado;
import java.util.Scanner;

public class JavaEstruturado2 {

	public static void main(String[] args) {
		double soma = 0;
		
		while (true) {
			Scanner INPUT = new Scanner(System.in);
			float num = INPUT.nextFloat();
			
			if (num < 0) {
				System.out.println(soma);
				break;
			}
			else if (num >= 5 && num <= 5000) {
				soma += num;
			}
		}
	}
}
