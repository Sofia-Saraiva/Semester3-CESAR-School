package JavaEstruturado;
import java.util.Scanner;

public class JavaEstruturado3 {

	public static void main(String[] args) {
		double ma = 0;
		double mg = 1;
		double mh = 0;
		for (int i = 0; i < 5; i++) {
			Scanner INPUT = new Scanner(System.in);
			float num = INPUT.nextFloat();
			
			ma += num;
			mg *= num;
			mh = mh + (1/num);
		}
		
		System.out.println(ma / 5);
		System.out.println(Math.pow(mg, 1.0 / 5.0));
		System.out.println(5/mh);
	}
}
