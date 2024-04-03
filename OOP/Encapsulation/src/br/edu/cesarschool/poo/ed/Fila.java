package br.edu.cesarschool.poo.ed;
import estruturadados.ListaEncadeada;

public class Fila extends ListaEncadeada {
	private ListaEncadeada listaInterna;
	
	public Fila() {
		listaInterna = new ListaEncadeada();
	}
	
	void enfileirar(String conteudo) {
		listaInterna.incluirConteudo(conteudo);
	}
	
	String desenfileirar() {
		return listaInterna.removerConteudo(0);
	}
	
	String ler() {
		return listaInterna.obterConteudoPorIndice(0);
	}
}
