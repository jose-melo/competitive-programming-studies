import java.util.*;


class ex1 {

	
	public static void main(String[] args){

		Scanner in = new Scanner(System.in);

		int n = in.nextInt();

		ArrayList<Integer> S = new ArrayList<Integer>();

		for(int i = 0; i < n; i++)
			S.add(in.nextInt());
		
		for(int i = 0; i < n; i++)
			System.out.print(S.get(i) + " ");
		
		Collections.sort(S);

		for(int i = 0;i < n; i++)
			System.out.print(S.get(i) + " ");			
		
		for(int i = 1; i < n; i++){
			if(S.get(i) == S.get(i-1)){
				System.out.println("There's duplicates!");
				return;
			}
		}
		System.out.println("There's no duplicates!");
	
		return;
	}




}





