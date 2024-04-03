package maquinas;

public class Eletrica extends Maquina {
	double voltagem;
	boolean tipoCorrente;
	
	public Eletrica(String nome, double potencia, double voltagem, boolean tipoCorrente) {
		super(nome, potencia);
		this.voltagem = voltagem;
		this.tipoCorrente = tipoCorrente;
	}
	
	public double corrente() {
		return (potencia/voltagem);
	}
	
    @Override
    public String toString() {
        return "Eletrica{" +
                "nome='" + nome + '\'' +
                ", potencia=" + potencia +
                ", voltagem=" + voltagem +
                ", tipoCorrente=" + (tipoCorrente ? "AC" : "DC") +
                '}';
    }
}
