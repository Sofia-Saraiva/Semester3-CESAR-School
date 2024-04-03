package itemvenda;

public class ItemVenda {
	Produto produto;
	TipoPagamento pagamento;
	int quantidade;
	double aliquotaImposto;
	boolean isentoImposto;
	
	public ItemVenda(Produto produto, TipoPagamento pagamento, int quantidade, 
			double aliquotaImposto, boolean isentoImposto) {
		this.produto = produto;
		this.pagamento = pagamento;
		this.quantidade = quantidade;
		this.aliquotaImposto = aliquotaImposto;
		this.isentoImposto = isentoImposto;
		
	}
	
	public double calcularImposto() {
		if (!isentoImposto) {
			double imposto = aliquotaImposto / 100 * (produto.preco * quantidade);
			return imposto;
		}
		else {
			return 0;
		}
	}
	
	public double calcularValorTotal(double imposto) {
		double valorTotal = imposto + (produto.preco + quantidade);
		return valorTotal;
	}
	
	public double calcularLucroItem(double custoRateado, double imposto) {
		double valorTotal = calcularValorTotal(imposto);
		return valorTotal - imposto - custoRateado - pagamento.tarifa;
	}
}
