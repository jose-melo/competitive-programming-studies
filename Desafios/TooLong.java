import java.util.Scanner;

public class TooLong{

	private static int n;
	private static Scanner in;

	TooLong(){
		in = new Scanner(System.in);
		n = in.nextInt();
	}

	public static void solve(){
		while(n > 0){

			String s = in.next();

			if(s.length() > 10){
				System.out.println(s.charAt(0) + Integer.toString((s.length() - 2)) + s.charAt(s.length() - 1));
			}else{
				System.out.println(s);
			}
			n--;
		}

	}

	public static void main(String args[]){
		TooLong solverObject = new TooLong();
		solverObject.solve();
	}
}