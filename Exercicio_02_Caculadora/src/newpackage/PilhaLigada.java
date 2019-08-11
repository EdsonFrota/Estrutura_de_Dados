
package newpackage;

import java.util.Stack;

class PilhaLigada implements Pilha {
    
     Stack pilha = new Stack();

    @Override
    public void push(String elemento) {
       
        this.pilha.push(elemento);
        
    }

    @Override
    public String pop() {
        
        return (String)this.pilha.pop();
        
    }

    @Override
    public int size() {
        
        return pilha.size();
      
    }

    @Override
    public String peek() {
        
        return (String)pilha.peek();
       
    }
}
