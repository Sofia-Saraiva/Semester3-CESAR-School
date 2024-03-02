package JavaEstruturado;
import java.util.Scanner;

public class JavaEstruturado1 {

	public static void main(String[] args) {
		Scanner INPUT = new Scanner(System.in);
		int num = INPUT.nextInt();
		
		if (num < 0) {
			System.out.println("MENOR QUE ZERO");
		}
		else if (num > 16) {
			System.out.println("OVERFLOW");
		}
		else {
			if (num == 0 ) {
				System.out.println("1");
			}
			else {
				int total = 1;
				for (int i = 1; i < num+1; i++) {
					total *= i;
					System.out.println(total);
				}
			}
		}
	}
}