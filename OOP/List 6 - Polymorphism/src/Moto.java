public class Moto {
    private String modelo;
    private double preco;
    private double potencia;
    private int tipoMotor;

    public Moto() {

    }

    public Moto(String modelo, double preco, double potencia, int tipoMotor) {
        this.modelo = modelo;
        this.preco = preco;
        this.potencia = potencia;
        this.tipoMotor = tipoMotor;
    }

    public Moto(String modelo, double preco) {
        this(modelo,preco,0,0);
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public double getPotencia() {
        return potencia;
    }

    public void setPotencia(double potencia) {
        this.potencia = potencia;
    }

    public int getTipoMotor() {
        return tipoMotor;
    }

    public void setTipoMotor(int tipoMotor) {
        this.tipoMotor = tipoMotor;
    }
}
