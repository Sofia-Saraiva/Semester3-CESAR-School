package figurasgeometricas;

public class Paralelogramo {
	double base;
	double altura;
	
	Paralelogramo(double base, double altura) {
		this.base = base;
		this.altura = altura;
	}
	
	double calcularArea() {
		return base * altura;
	}
}
