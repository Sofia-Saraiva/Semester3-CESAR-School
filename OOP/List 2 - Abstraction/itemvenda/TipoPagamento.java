package itemvenda;

public enum TipoPagamento {
    DINHEIRO(1, "Dinheiro", 0.0, false),
    CARTAO_CREDITO(2, "Cartão de crédito", 0.05, true),
    CARTAO_DEBITO(3, "Cartão de débito", 0.03, true),
    CHEQUE(4, "Cheque", 0.0, false),
    VALE_ALIMENTACAO_PAPEL(5, "Vale Alimentação Papel", 0.0, false),
    VALE_ALIMENTACAO_CARTAO(6, "Vale Alimentação Cartão", 0.0, false),
    PIX(7, "PIX", 0.01, true);

    int codigo;
    String descricao;
    double tarifa;
    boolean pagamentoEletronico;

    TipoPagamento(int codigo, String descricao, double tarifa, boolean pagamentoEletronico) {
        this.codigo = codigo;
        this.descricao = descricao;
        this.tarifa = tarifa;
        this.pagamentoEletronico = pagamentoEletronico;
    }

    public int getCodigo() {
        return codigo;
    }

}
