package caminhão;

import java.util.Stack;
//import java.util.Scanner;
//import java.util.InputMismatchException;

/**
 *
 * @author EMERSON
 */
public class Verificador {

    int i = 0;  //pilhaFinal
    int j = 0; //pilhaLateral
    int h;

    Stack pilhaFinal = new Stack();
    Stack pilhaLateral = new Stack();

    public void verifica(int n) {
        if (n == 1) {
            addFinal(n);
            i++;
        } else if (n == i + 1) {
            addFinal(n);
            i++;
        } //Adiciona o primeiro elemento na pilha lateral
        else if (n != i + 1 && pilhaLateral.empty()) {
            addLateral(n);
            j++;
        } else if (!pilhaLateral.empty() && n < topoLateral()) {
            addLateral(n);
            j++;
        }
        
        try{
            for (h = 0; h < j; h++) {
            if (topoLateral() == i + 1) {
                int y = (int) pilhaLateral.pop();
                addFinal(y);
                i++;
            }
        }
        }catch(ArrayIndexOutOfBoundsException e) {
                System.out.println("Array fora do índice: "+e.getMessage());
                }
            
        
        
    }

    public void resultado(int m) {
        if (pilhaFinal.size() == m) {
            System.out.println("A sequência foi organizada!");
            for (i = 0; i < m; i++) {
                int x = (int) pilhaFinal.pop();
                System.out.printf("%d ", x);
            }
        } else {
            System.out.println("A sequência não pode ser organizada!");
            for (i = 0; i < m; i++) {
                int x = (int) pilhaFinal.pop();
                System.out.printf("%d ", x);
            }
        }
    }

    public void addFinal(int n) {
        pilhaFinal.push(n);
    }

    public void addLateral(int n) {
        pilhaLateral.push(n);
    }

    public int topoLateral() {
        int x = (int) pilhaLateral.peek();
        return x;
    }
}
