
package javaapplication7;

import java.util.Scanner;

public class JavaApplication7 {

    public static void main(String args []) {
    
        Scanner input = new Scanner(System.in);
        
        Ordenadora Objeto;
        Objeto = new Ordenadora();

        int total_veiculos;
        int veiculos;

        System.out.println(" Entre com a quantidade de Caminhões: ");
        total_veiculos = input.nextInt();

        System.out.println(" Informe a sequência em que os caminhões estão organizados: ");

        try {

            for (int area = 0; area < total_veiculos; area++) {

                veiculos = input.nextInt();
                Objeto.ordena(veiculos);

            }

        } catch (ArrayIndexOutOfBoundsException e) {

            System.out.println(" ERRO: " + e.getMessage());

        }

        Objeto.saida(total_veiculos);
    }
}

    

