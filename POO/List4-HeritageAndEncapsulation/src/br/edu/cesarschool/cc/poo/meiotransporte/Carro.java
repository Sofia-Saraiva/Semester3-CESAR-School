package br.edu.cesarschool.cc.poo.meiotransporte;
import br.edu.cesarschool.cc.poo.meiotransporte.motorizado.MeioTransporteMotorizado;

class Carro extends MeioTransporteMotorizado {

    public Carro(String nome, double cargaMaxima, double velocidadeMaxima, double potenciaMotor, double capacidadeCombustivel, double consumoMedio) {
        super(nome, cargaMaxima, velocidadeMaxima, potenciaMotor, capacidadeCombustivel, consumoMedio);
    }

    double calcularEficiencia() {
        return getCargaMaxima() / getConsumoMedio();
    }
    
    public double getPotenciaMotor() {
        return super.getPotenciaMotor();
    }
    
    public void setPotenciaMotor(double potenciaMotor) {
        super.setPotenciaMotor(potenciaMotor);
    }
    
    public double getCapacidadeCombustivel() {
        return super.getCapacidadeCombustivel();
    }
    
    public void setCapacidadeCombustivel(double capacidadeCombustivel) {
        super.setCapacidadeCombustivel(capacidadeCombustivel);
    }
    
    public double getConsumoMedio() {
        return super.getConsumoMedio();
    }
    
    public void setConsumoMedio(double consumoMedio) {
        super.setConsumoMedio(consumoMedio);
    }
}
