import java.util.Scanner;

public class Coins{

	private static long totalSum, num_coins, res;
	private static Scanner in;

	Coins(){
		in = new Scanner(System.in);
		num_coins = in.nextLong();
		totalSum = in.nextLong();
		res = 0;
	}

	public static long solve(){

		while(totalSum != 0){
			res += totalSum / num_coins;
			totalSum = totalSum % num_coins;
			num_coins = totalSum;
		}

	return res;
	}

	public static void main(String args[]){
		Coins solver = new Coins();
		System.out.println(solver.solve());
	}

}