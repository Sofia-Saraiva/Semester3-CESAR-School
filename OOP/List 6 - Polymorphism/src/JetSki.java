public class JetSki extends Moto {
    private int tipoCasco;

    public JetSki() {
    }

    public JetSki(String modelo, double preco, double potencia, int tipoMotor, int tipoCasco) {
        super(modelo, preco, potencia, tipoMotor);
        this.tipoCasco = tipoCasco;
    }

    public JetSki(String modelo, double preco, int tipoCasco) {
        this(modelo, preco, 0, 0, tipoCasco);
    }

    public int getTipoCasco() {
        return tipoCasco;
    }

    public void setTipoCasco(int tipoCasco) {
        this.tipoCasco = tipoCasco;
    }
}
