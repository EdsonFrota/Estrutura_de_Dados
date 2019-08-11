
package newpackage;

public class HP12C {
    
    public Pilha Pilha_IMPLEMENTS;
    String Operacao_Desejada;
    double resultado;
    
    public HP12C(){
    Pilha_IMPLEMENTS = new PilhaLigada();
    
}
    public double Calcula(String linha){
    
        String elementos[] = linha.split(" ");
    
        for (String e : elementos) {
          
            Pilha_IMPLEMENTS.push(e);
               }

      
        if (Pilha_IMPLEMENTS.peek().equals('+')) {
            Operacao_Desejada = Pilha_IMPLEMENTS.pop();
            resultado = Double.parseDouble(Pilha_IMPLEMENTS.pop()) + Double.parseDouble(Pilha_IMPLEMENTS.pop());
        }
    
        if (Pilha_IMPLEMENTS.peek().equals('-')) {
            Operacao_Desejada = Pilha_IMPLEMENTS.pop();
            resultado = Double.parseDouble(Pilha_IMPLEMENTS.pop()) - Double.parseDouble(Pilha_IMPLEMENTS.pop());
        }
    
        if (Pilha_IMPLEMENTS.peek().equals('*')) {
            Operacao_Desejada = Pilha_IMPLEMENTS.pop();
            resultado = Double.parseDouble(Pilha_IMPLEMENTS.pop()) * Double.parseDouble(Pilha_IMPLEMENTS.pop());
        }
        
    
        if (Pilha_IMPLEMENTS.peek().equals('/')) {
            Operacao_Desejada = Pilha_IMPLEMENTS.pop();
            resultado = Double.parseDouble(Pilha_IMPLEMENTS.pop()) / Double.parseDouble(Pilha_IMPLEMENTS.pop());
        }

        return resultado;
    
    }

    double calcula(String _15_) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}
