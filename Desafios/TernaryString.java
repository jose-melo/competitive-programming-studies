import java.util.*;

public class TernaryString{

	private static char[] str, resposta;
	private static String aux_string;
	private static char[] a, b;
	private static Scanner in;

	TernaryString(){
		in = new Scanner(System.in);
	}

	public static char[] solve(){
		aux_string = in.next();

		str = aux_string.toCharArray();

		a = new char[aux_string.length()];
		b = new char[aux_string.length()];
		resposta = new char[aux_string.length()];

		int cont_a = 0, cont_b = 0;
		boolean acabou = false;
		for(int i = 0; i < aux_string.length() && !acabou; i++){
			if(str[i] == '2'){
				for(int j = i; j < aux_string.length(); j++){
					if(str[j] == '1'){
						a[cont_a] = str[j];
						cont_a++;
					}
					else{
						b[cont_b] = str[j];
						cont_b++;
					}
				}
				acabou = true;	
			}else{
				a[cont_a] = str[i];
				cont_a++;
			}
		}
		
		Arrays.sort(a, 0, cont_a);

		for(int i = 0; i < cont_a; i++)
			resposta[i] = a[i];
		for(int i = 0; i < cont_b; i++)
			resposta[cont_a + i] = b[i];

		return resposta;
	}

	public static void main(String args[]){

		TernaryString solver = new TernaryString();
		System.out.println(solver.solve());

	}
}