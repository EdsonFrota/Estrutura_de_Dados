import static org.junit.Assert.*;

import org.junit.Test;

public class HP12CTest {

	@Test
	public void testSimple() {
		 hp = new HP12C();
		float resultado;
        resultado = hp.calcula("10 15 +");
		
		assertEquals(25, resultado, 0);
	}

}
