package caminhão;

//import java.util.Stack;
import java.util.Scanner;
//import java.util.InputMismatchException;

/**
 *
 * @author EMERSON
 */
public class Caminhão {

    public static void main(String[] args) {

        Scanner entrada = new Scanner(System.in);
        Verificador verificador = new Verificador();
        
        int numero; int caminhao;

        
        System.out.println("Digite a quantidade de caminhões");
        numero = entrada.nextInt();
        
        System.out.println("Digite a sequência de caminhões");
        
        try{
             for(int i=0; i<numero; i++){
            caminhao = entrada.nextInt();
            verificador.verifica(caminhao);
        }
        }catch(ArrayIndexOutOfBoundsException e) {
                System.out.println("Array fora do índice: "+e.getMessage());
                }
       
        verificador.resultado(numero);
        
    }
}
