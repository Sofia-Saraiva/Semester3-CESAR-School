package maquinas;

enum TipoCombustivel {
	DIESEL,
	GASOLINA,
	QUEROSENE,
	ETANOL;
}

public class Combustao extends Maquina {
	TipoCombustivel tipoCombustivel;
	
	public Combustao(String nome, double potencia, TipoCombustivel tipoCombustivel) {
		super(nome, potencia);
		this.tipoCombustivel = tipoCombustivel;
	}
	
	
    @Override
    public String toString() {
        return "Combustao{" +
                "nome='" + nome + '\'' +
                ", potencia=" + potencia +
                ", tipoCombustivel=" + tipoCombustivel +
                '}';
    }
}
