package figurasgeometricas;

public class Terreno {
	double area;
	double valorPorMetroQuadrado;
	Endereco endereco;
	
	Terreno(double valorPorMetroQuadrado, Endereco endereco) {
		this.valorPorMetroQuadrado = valorPorMetroQuadrado;
		this.endereco = endereco;
	}
	
	double calcularValorTerreno(double area, double valorPorMetroQuadrado) {
		return area * valorPorMetroQuadrado;
	}
}
