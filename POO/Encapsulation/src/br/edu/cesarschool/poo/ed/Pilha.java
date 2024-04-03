package br.edu.cesarschool.poo.ed;
import estruturadados.ListaEncadeada;

public class Pilha extends ListaEncadeada {
	private ListaEncadeada listaInterna;
	
	public Pilha() {
		listaInterna = new ListaEncadeada();
	}
	
	void empilhar(String conteudo) {
		listaInterna.incluirConteudo(conteudo);
	}
	
	String desempilhar() {
		return listaInterna.removerConteudo(listaInterna.getTamanhoLista() - 1);
	}
	
	String ler() {
		return listaInterna.obterConteudoPorIndice(listaInterna.getTamanhoLista() - 1);
	}
}