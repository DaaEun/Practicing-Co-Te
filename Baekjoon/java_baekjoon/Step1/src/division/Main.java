package division;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		double a = sc.nextInt();
		double b = sc.nextInt();
		
		double answer = a / b;
		
		System.out.println(answer);
		
		sc.close();

	}

}
