import java.util.Scanner;

public class Segments{

	private static long a, b, c, d, queries;
	private static Scanner in;

	Segments(){
		in = new Scanner(System.in);
		queries = in.nextLong();
	}

	public static void solve(){

		while(queries > 0){

			a = in.nextLong();
			b = in.nextLong();
			c = in.nextLong();
			d = in.nextLong();
			if(a == c && b == d){
				System.out.println(a + " " + b);
			}else{
				
				if(a != d)
					System.out.println(a  + " " + d);
				else
					System.out.println(a  + " " + c);
			}
			queries--;
		}
	}

	public static void main(String args[]){
		Segments solverObject = new Segments();
		solverObject.solve();
	}
}