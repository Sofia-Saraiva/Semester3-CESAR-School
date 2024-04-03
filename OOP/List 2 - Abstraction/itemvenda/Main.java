package itemvenda;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner INPUT = new Scanner(System.in);
		
		System.out.println("Digite os dados do produto:");
		System.out.print("Código: ");
		long codigoProduto = INPUT.nextLong();
		INPUT.nextLine(); 
		System.out.print("Nome: ");
		String nome = INPUT.nextLine();
		System.out.print("Preço: ");
		double preco = INPUT.nextDouble();		
		Produto produto = new Produto(codigoProduto, nome, preco);
		
		System.out.println("Digite o código do tipo de pagamento:");
		int codigo = INPUT.nextInt();
		TipoPagamento pagamento = null;
        for (TipoPagamento tp : TipoPagamento.values()) {
            if (tp.getCodigo() == codigo) {
                pagamento = tp;
                break;
            }
        }
		
		System.out.println("Digite os dados do item de venda:");
		System.out.print("Quantidade: ");
		int quantidade = INPUT.nextInt();
		System.out.print("Imposto: ");
		double aliquotaImposto = INPUT.nextDouble();
		System.out.print("Isento de imposto? (true/false): ");
		boolean isentoImposto = INPUT.nextBoolean();
		ItemVenda item = new ItemVenda(produto, pagamento, quantidade, aliquotaImposto, isentoImposto);
		
		System.out.println("Custo Rateado: ");
		double custoRateado = INPUT.nextDouble();
		
		double imposto = item.calcularImposto();
		System.out.println(item.calcularValorTotal(imposto));
		System.out.println(imposto);
		System.out.println(item.calcularLucroItem(custoRateado, imposto));
	}

}
