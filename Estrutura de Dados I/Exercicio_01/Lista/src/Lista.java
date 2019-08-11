public interface Lista {
	public void addUltimo(Aluno aluno);

	public Aluno getUltimo();

	public int getUltimaPosicao();

	public void addPosicao(Aluno aluno, int pos);

	public Aluno getPosicao(int pos);

	public void removerAlunoPosicao(int posicao);

	public int getNumAlunos(Aluno aluno);

	public int getAluno(String nome);
}