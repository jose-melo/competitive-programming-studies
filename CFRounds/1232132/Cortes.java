import java.util.*;

public class Cortes{

	public static void main(String[] args){

		int num_cortes, p, max, num_elementos, i;

		int[] v;

		Scanner in = new Scanner(System.in);

		num_elementos = in.nextInt();
		num_cortes = in.nextInt();

		v = new int[num_elementos+1];
		int cortes[] = new int[num_elementos+1];
		max = -1;
		int k = 0;
		int resposta = 0;
		for(p = 1; p <= num_elementos; p++){

			if(v[p] > max && num_elementos-p > num_cortes)
				max = v[p];
			else{
				if(num_cortes > 0 && num_elementos-p > num_cortes){
					cortes[k] = p-1;
					resposta += max;
					num_cortes--;
					max = -1;
					k++;
				}else{
					if(num_elementos-p <= cortes){
						cortes[k] = p-1;
						resposta += max;
						num_cortes--;
						max = -1;
						k++;
					}

				}
			}
		}

		System.out.println(resposta);
		for(int i = 0; i < cortes.length; i++)
			System.out.println(cortes[i]);

	}


}