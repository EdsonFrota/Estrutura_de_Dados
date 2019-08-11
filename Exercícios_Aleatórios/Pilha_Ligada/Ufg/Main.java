package Ufg;

import java.util.Scanner;

public class Main {
	
	public static void main (String args []){
		
		Scanner scan = new Scanner (System.in);
		int n = scan.nextInt();
		
		Pilha p = new PilhaVetor();
		for(int i = 0; i < n; i++){
			System.out.println(i + ": ");
			int x = scan.nextInt();
			
			p.push(x);
			
		}
		
		System.out.println("Tamnho: " + p.size());
		System.out.println("Pop: " + p.pop());
	}
	
	

}
