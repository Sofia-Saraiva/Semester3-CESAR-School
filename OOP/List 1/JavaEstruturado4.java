package JavaEstruturado;
import java.util.Scanner;

public class JavaEstruturado4 {

	public static void main(String[] args) {
		Scanner INPUT = new Scanner(System.in);
		int opcao = INPUT.nextInt();
		
		float a=0, b=0;
		
		if (opcao >= 1 && opcao <= 4) {
			a = INPUT.nextFloat();
			b = INPUT.nextFloat();
		}
		else {
			System.out.println("OPC ERRADA");
		}
		
		switch (opcao) {
			case 1:
				System.out.println(a + b);
				break;
			case 2:
				System.out.println(a - b);
				break;
			case 3:
				System.out.println(a * b);
				break;
			case 4:
				if (b == 0) {
					System.out.println("DIV ZERO");
				}
				else {
					System.out.println(a / b);
				}
				break;
		}
	}
}
