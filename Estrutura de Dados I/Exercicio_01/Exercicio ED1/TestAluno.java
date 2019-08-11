
/**
 *
 * @author Edson Júnior Frota da Silva
 */

import java.util.Scanner;
import java.util.ArrayList;

public class TestAluno implements Aluno{
    
    String nome;
     int posicao, tam;
    
    Scanner ler = new Scanner(System.in);
    
    private final ArrayList<String> alunos = new ArrayList<>();
    private final int UltimaPsicao;
        
    public TestAluno(){
    
        UltimaPsicao = 0;
    }

    @Override
    public void addUltimo() {
        
        System.out.println("Informe o nome do Aluno para cadastrar: ");
         alunos.add(ler.nextLine());
         
    }

    @Override
    public String getUltimo() {
        
       nome = alunos.get(UltimaPsicao);
        return null;
            
    }

    @Override
    public int getUltimaPosicao() {
        
        return alunos.size();
    }

    @Override
    public void addPosicao() {
        
        System.out.println("Informe a posicao para cadastrar o aluno: ");
            posicao = ler.nextInt();
            
            System.out.println("Digite o Nome do aluno que deseja cadastrar");
            nome = ler.nextLine();
            alunos.add(posicao, nome);
    }

    @Override
    public void getPosicao() {
        
        
		System.out.println("Informe o nome que deseja encontrar");
                nome = ler.nextLine();
            
            if(alunos.contains(nome)){
                System.out.println("Cadastrado na posição: " + alunos.indexOf(nome));
            }
            else{
                System.out.println("Aluno não cadastrado");
    }
    }
    @Override
     public void removerAlunoPosicao(){
        
        alunos.remove(posicao);
    }

    

    @Override
    public int getNumAlunos() {
        tam = alunos.size();
		return tam;
    }

    @Override
    public int getAluno(String nome) {
        
        System.out.println("Digite a posição desejada: ");
        posicao = ler.nextInt();
        
        System.out.printf("Nome cadastrado na posição %d : %s ", posicao, alunos.get(posicao));
		return 0;
    }
 
}
