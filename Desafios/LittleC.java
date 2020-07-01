import java.util.Scanner;

public class LittleC{

	private static long n, mod;
	private static long[] resposta;
	private static Scanner in;

	LittleC(){
		resposta = new long[3];		
		in = new Scanner(System.in);
		n = in.nextLong();
		mod = n % 3;

		//System.out.println(mod);

	}

	public static long[] solve(){

		if(mod == 0){
			resposta[0] = n-2;
			resposta[1] = 1;
			resposta[2] = 1;
			
			return resposta;
		}

		if(mod == 1){
			resposta[0] = n-2;
			resposta[1] = 1;
			resposta[2] = 1;
			
			return resposta;
		}

		
		resposta[0] = 1;
		resposta[1] = 2;
		resposta[2] = n-3;
			
	return resposta;
	}


	public static void main(String args[]){

		LittleC solver = new LittleC();
		long[] res;

		res = solver.solve();

		System.out.println(res[0] + " " + res[1] + " " + res[2]);
	}
}