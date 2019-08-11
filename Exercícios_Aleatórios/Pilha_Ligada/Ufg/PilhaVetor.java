package Ufg;

public class PilhaVetor implements Pilha{
	int[] pilha;
	int UltimaPosicao;
	//int tamanho;
	
	public PilhaVetor(){
		pilha = new int[100];
		UltimaPosicao = 0;
		
	}
	
	@Override
	public void push(int x) {
		pilha[UltimaPosicao] = x;
		UltimaPosicao++;
	
	}
	
	@Override
	public int pop() {
		int x = pilha[UltimaPosicao - 1];
		UltimaPosicao--;
		return x;

	}
	
	@Override
	public int peek() {
		return pilha[UltimaPosicao-1];
		
		
	}
	
	@Override
	public int size() {
		return UltimaPosicao;
	}

	@Override
	public boolean isEmpty() {
		return UltimaPosicao == 0;
	}
	

}
