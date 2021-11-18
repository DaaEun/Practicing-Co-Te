package multiplication_table;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		
		for(int n = 1; n<=9; n++) {
			System.out.println(m + " * " + n + " = " + m*n);
		}

	}

}
