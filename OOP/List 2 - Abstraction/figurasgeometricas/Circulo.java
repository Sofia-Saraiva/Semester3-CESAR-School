package figurasgeometricas;

public class Circulo {
	double raio;
	
	Circulo(double raio) {
		this.raio = raio;
	}
	
	double obterDiametro() {
		return 2 * raio;
	}
	
	double calcularArea() {
		return 3.14 * (raio * raio);
	}
	
	double calcularPerimetro() {
		return 2 * 3.14 * raio;
	}
	
	double calcularComprimentoArco(double anguloArco) {
		return (anguloArco * 3.14 * raio) / 180;
	}
}
