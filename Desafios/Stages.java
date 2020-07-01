import java.util.*;

public class Stages{

	private static SortedSet<Character> possibleStages;
	private static char[] array;
	private static int available, max_stages;
	private static Scanner in;


	Stages(){
		in = new Scanner(System.in);
		available = in.nextInt();		
		max_stages = in.nextInt();
		possibleStages = new TreeSet<Character>();
		array = new char[available];
	}

	public static int solve(){

		String s = in.next();

		for(int i = 0; i < available; i++)
			possibleStages.add(s.charAt(i));
		
		available = possibleStages.size();
		
		Iterator it = possibleStages.iterator();
		int y = 0;
		while(it.hasNext()){
			array[y] = (char) it.next();
			y++;
		}


		/*for(int num : possibleStages)
			System.out.printf(" %c ", num);
		System.out.println(" ");*/


		//Arrays.sort(possibleStages);

		/*for(int num : possibleStages)
			System.out.printf(" %c ", num);
		System.out.println(" ");*/

		int resposta = 0;
		int cont = 0;
		int index = 0;
		while(cont < max_stages && index < available){

			resposta += (array[index] - 'a' + 1);

			//System.out.println("resposta = "+resposta);

			cont++;

			if((index+1 < available) && (array[index+1] > array[index]+1))
				index++;
			else
				index += 2;
		}

		if(cont != max_stages)
			return -1;
		else
			return resposta;
	}


	public static void main(String args[]){
		Stages solver = new Stages();
		System.out.println(solver.solve());
	}
}