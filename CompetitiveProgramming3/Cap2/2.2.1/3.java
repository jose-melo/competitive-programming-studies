import java.util.*;

class ex3{

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);

		int n = in.nextInt();
		int[] S = new int[112345];


		for(int i = 0; i < n; i++){
			S[i] = in.nextInt();
		}


		int mx = -1;
		int cont = 1;
		for(int i = 0; i < n-1; i++){
			if(S[i+1] >= S[i]){
				cont++;
			}else{
				if(cont > mx)
					mx = cont;
				cont = 1;
			}
		}
		
		if(cont > mx)
			mx = cont;

		System.out.println("Resposta: " + Integer.toString(mx));
		return;
	}

}
