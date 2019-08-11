
package javaapplication7;

import java.util.Stack;

public class Ordenadora {
    
    Stack pilhaF = new Stack();
    Stack pilhaL = new Stack();
   
        int pilhaFinal = 0;
        int pilhaLateral = 0;
        int aux;
          
    public void ordena(int numero){
        
        if( numero == 1 ){
            
            adicionaFinal(numero);
            pilhaFinal++;
            
        }
        else if( numero == pilhaFinal + 1 ){
            
            adicionaFinal(numero);
            pilhaFinal++;
            
        }
        else if( numero != pilhaFinal + 1 && pilhaL.empty() ){
            
            adicionaLateral(numero);
                pilhaLateral++;
                
        }
        else if( !pilhaL.empty() && numero < lateralVetor() ){
            
            adicionaLateral(numero);
                pilhaLateral++;
                
        }
        
        try{
            
            for ( aux = 0; aux < pilhaLateral; aux++ ) {
                
            if ( lateralVetor() == pilhaFinal + 1 ) {
                
                int kA = (int) pilhaL.pop();
                adicionaFinal(kA);
                pilhaFinal++;
                
                 }
            
             }
            
        }
        
        catch(ArrayIndexOutOfBoundsException e) {
                System.out.println(" ERR0: " +e.getMessage());
  
    }
    
}
     public void saida(int variavel) {
         
        if ( pilhaF.size() == variavel ) {
            
            
            System.out.println(" É Possível Organizar da seguinte Forma: ");
            
            System.out.println("  \t ");
                       
            for ( pilhaFinal = 0; pilhaFinal < variavel; pilhaFinal++ ) {
                
               int kO  = (int) pilhaF.pop();
               
                System.out.printf(" [CAMINHÃO %d] -  ", kO );
                
            }
            
            System.out.println("  \n ");
        } 
        else {
            
            System.out.println("!!! Não é Possível Organizar a sequência de caminhões !!!");
        }
    }

      private void adicionaFinal(int numero) {
        pilhaF.push(numero);
    }

      private void adicionaLateral(int numero){
          
          pilhaL.push(numero);
 
      }
      
       public int lateralVetor() {
         int kO = (int) pilhaL.peek();
        return kO;
        
    }

    
}
