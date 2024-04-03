package br.edu.cesarschool.cc.poo.meiotransporte;
import br.edu.cesarschool.cc.poo.meiotransporte.naomotorizado.*;

class AsaDelta extends MeioTransporteNaoMotorizado {
    private TipoTracao tipoTracao;
    
    public AsaDelta(String nome, double cargaMaxima, double velocidadeMaxima, TipoTracao tipoTracao) {
        super(nome, cargaMaxima, velocidadeMaxima, tipoTracao);
        this.tipoTracao = tipoTracao;
    }
    
    public TipoTracao getTipoTracao() {
        return tipoTracao;
    }
    
    public void setTipoTracao(TipoTracao tipoTracao) {
        this.tipoTracao = tipoTracao;
    }
}
