package cursoPOO;
import java.util.Scanner;

public class Quest3 {

	public static void main(String[] args) {
		Scanner obj = new Scanner(System.in);
		float a = obj.nextFloat();
		float b = obj.nextFloat();
		float c = obj.nextFloat();
		
		float delta = (b * b) - 4 * a * c;
		
		if (delta > 0) {
			double raiz1 = (-b + Math.sqrt(delta)) / (2 * a);
			double raiz2 = (-b - Math.sqrt(delta)) / (2 * a);
			System.out.println("Raiz 1: " + raiz1);
			System.out.println("Raiz 2: " + raiz2);
		}
		else if (delta == 0) {
			double raiz = -b / (2*a);
			System.out.println("Raiz: " + raiz);
		}
		else {
			System.out.println("Nenhuma raiz real");
		}
	}

}
