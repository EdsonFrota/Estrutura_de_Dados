
public class Lista_Vetor implements Lista_Aluno{
    
    private Aluno[] alunos = new Aluno[10];
	 int ultimaPosicao;
         int totaldeAlunos = 0;

	public Lista_Vetor() {
		alunos = new Aluno[10];
		ultimaPosicao = 0;
	}

    @Override
    public void addUltimo(Aluno aluno) {
        for (int ultimaPosicao = 0;ultimaPosicao < this.alunos.length;ultimaPosicao++) {
                if (this.alunos[ultimaPosicao] == null) {
                    this.alunos[ultimaPosicao] = aluno;
                    break;
                }
            }
            ultimaPosicao = ultimaPosicao + 1;    
    }

    @Override
    public Aluno getUltimo() {
        
      return (alunos[ultimaPosicao]);
        
    }

    @Override
    public int getUltimaPosicao() {
        
        int pos=0;
		for(int i = this.alunos.length;i >= 0;i -= 1){
                    if(this.alunos[i] != null){
                        pos = i+1;
                    }
                }
                return (pos);       
    }

    @Override
    public void addPosicao(Aluno aluno, int pos) {
        if((pos >= 0)&&(pos <= this.alunos.length)){
                for(int i = this.alunos.length + 1;i >= pos;i -=1){
                    this.alunos[i+1] = this.alunos[i];
                }
                this.alunos[pos] = aluno;
            }
    }

    @Override
    public Aluno getPosicao(int pos) {
        return (this.alunos[pos]);
    }

    @Override
    public void removerAlunoPosicao(int posicao) {
        int pos = 0;
        if(alunos[pos]!=null){
                for(int i = pos;i < this.alunos.length;i++){
                    this.alunos[pos] = this.alunos[i+1];
                }
            }
    }

    @Override
    public int getNumAlunos(Aluno aluno) {
         for (Aluno aluno1 : this.alunos) {
                if (aluno1 != null) {
                    totaldeAlunos++; 
                }
            }
            return totaldeAlunos;
    }

    @Override
    public int getAluno(String nome) {
       return (0);
    }
    
}
