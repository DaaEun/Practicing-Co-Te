package leap_year;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int year = sc.nextInt();
		
		if(year % 4 == 0) {
			if(year % 100 != 0 || year % 400 == 0) {	// 윤년인 경우
				System.out.println("1");
			}
			else {
				System.out.println("0");
			}
		}
		else {
			System.out.println("0");
		}
		
		sc.close();

	}

}
