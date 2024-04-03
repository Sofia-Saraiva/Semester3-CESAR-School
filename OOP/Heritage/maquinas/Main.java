package maquinas;

public class Main {

	public static void main(String[] args) {
		Eletrica p1 = new Eletrica("Gerador", 100, 10, true);
		System.out.println(p1.corrente());
		System.out.println(p1.toString());
		Combustao p2 = new Combustao("Carro", 100, TipoCombustivel.DIESEL);
		System.out.println(p2.toString());
	}
}
