
public class HP12C {

    public Pilha pilha;
    
	public HP12C() {
		pilha = new PilhaLigada();
	}
	
	public float calcula(String linha) {
            
		String elementos[] = linha.split(" ");
		
		for (String e : elementos) {
		
                    switch(e){
                        
                        case "+":
                        break;
                        
                        case "-":
                        break;
                        
                        
                        case "*":
                        break;
                    
                        case "/":
                        break;
                        
                        default:
                            pilha.push(e);
                            break;
                    }
			
		}
		
		return -1;
	}
}
