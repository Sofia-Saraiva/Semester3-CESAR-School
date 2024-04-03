package informatica;

public class UCP {
	double clockBase;
	double fatorTurbo;
	Modelo modelo;
	
	UCP(double clockBase, double fatorTurbo, Modelo modelo) {
		this.clockBase = clockBase;
		this.fatorTurbo = fatorTurbo;
		this.modelo = modelo;
	}
	
	double calcularClockMaximo() {
		return clockBase * fatorTurbo;
	}
}
