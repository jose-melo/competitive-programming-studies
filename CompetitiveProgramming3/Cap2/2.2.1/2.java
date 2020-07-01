import java.util.*;

class ex2{
	
	public static void main(String[] args){


		Set<Integer> S = new TreeSet<Integer>();
		Scanner in = new Scanner(System.in);

		int n = in.nextInt();
		int v = in.nextInt();
		int val;
	
		for(int i = 0; i < n; i++){
	
			val = in.nextInt();
			if(!S.isEmpty()){
				if(S.contains(v - val)){
					int blau = v - val;
					System.out.println("Existem! " + blau+ " + " + val+" = " + v);
					return;
				}
			}
			S.add(val);
		}		

		return ;
	}
}
