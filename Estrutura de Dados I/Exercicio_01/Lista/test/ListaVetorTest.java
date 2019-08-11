import static org.junit.Assert.*;

import org.junit.Test;

public class ListaVetorTest {

	@Test
	public void testAdicionarAlunoFinalLista() {
		Lista l = new ListaVetor();
		Aluno a = new Aluno("Marcos");
		l.addUltimo(a);
		
		assertEquals(a, l.getUltimo());
		assertEquals(0, l.getUltimaPosicao());
	}
	
	@Test
	public void testAdicionarAlunoFinalListaCompleto() {
		Lista l = new ListaVetor();
		
		for (int i = 0; i <= 123; i++) {
			Aluno a = new Aluno("Marcos");
			l.addUltimo(a);	
		
			assertEquals(a, l.getUltimo());
			assertEquals(i, l.getUltimaPosicao());
		}
		
		assertEquals(123, l.getUltimaPosicao());
	}
	
	@Test
	public void testAdicionarAlunoPosicao() {
		Lista l = new ListaVetor();
		Aluno a = new Aluno("JoÃ£o Carlos");
		l.addPosicao(a, 3);
		
		assertEquals(a, l.getPosicao(3));
		assertEquals(a, l.getUltimo());
		assertEquals(3, l.getUltimaPosicao());
	}
	

	@Test
	public void testAdicionarAlunoPosicaoCompleto() {
		Lista l = new ListaVetor();
		Aluno a = new Aluno("JoÃ£o Carlos");
		l.addPosicao(a, 512);
		
		assertEquals(a, l.getPosicao(512));
		assertEquals(a, l.getUltimo());
		assertEquals(512, l.getUltimaPosicao());
	}
	
	@Test
	public void testRemoverAlunoPosicao() {
		Lista l = new ListaVetor();
		Aluno a = new Aluno("Eduardo");
		l.addPosicao(a, 4);
		assertEquals(a, l.getPosicao(4));
		
		l.removerAlunoPosicao(4);
		assertNull(l.getPosicao(4));

		assertEquals(0, l.getUltimaPosicao());
	}

	@Test
	public void testRemoverAlunoNaoExistente() {
		Lista l = new ListaVetor();
		Aluno a = new Aluno("Eduardo");
		l.addPosicao(a, 1012);
		assertEquals(a, l.getPosicao(1012));
		
		l.removerAlunoPosicao(1048);
		assertNull(l.getPosicao(1048));

		assertEquals(1012, l.getUltimaPosicao());
	}
}
