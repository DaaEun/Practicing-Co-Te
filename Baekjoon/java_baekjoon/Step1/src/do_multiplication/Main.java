package do_multiplication;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int answer = 0;
		
		for(int i=0; i<3; i++) {
			int c = b % 10;
			System.out.println(a * c);
			answer += a * c * Math.pow(10, i);
			b = b/10;
		}
		
		System.out.println(answer);
		
		sc.close();
	}

}
