import java.util.Scanner;

public class PointsInSegments{

	private static int[] pointLine, result;
	private static int num_points, num_segments, aux_reader, cont;
	private static Scanner in;

	PointsInSegments(){
		in = new Scanner(System.in);
		num_segments = in.nextInt();
		num_points = in.nextInt();
		pointLine = new int[num_points + 10];
		result = new int[num_points + 10];
		cont = 0;

		for(int i = 0; i < num_points + 5; i++)
			pointLine[i] = 0;
	}

	public static int getTotal(){
		return cont;
	}

	public static int[] solve(){

		while(num_segments > 0){
			aux_reader = in.nextInt();
			pointLine[aux_reader] += 1;	
			aux_reader = in.nextInt();
			pointLine[aux_reader + 1] += -1;
			num_segments--;
		}

		for(int i = 2; i <= num_points + 1; i++)
			pointLine[i] = pointLine[i-1] + pointLine[i];
		
		for(int i = 1; i <= num_points; i++)
			if(pointLine[i] == 0){
				result[cont] = i; 
				cont++;
			}
		
		return result;
	}

	public static void main(String args[]){

		PointsInSegments solverObject = new PointsInSegments();
		int[] resposta;

		resposta = solverObject.solve();

		System.out.println(solverObject.getTotal());

		for(int i = 0; i < solverObject.getTotal(); i++)
			System.out.print(resposta[i] + " ");
		System.out.println(" ");
	}

}