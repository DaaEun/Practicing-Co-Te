package grade;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int grade = sc.nextInt();
		
		if(grade < 0 || grade > 100) {
			System.out.println("올바른 성적을 입력하세요.");
		}
		
		if(90 <= grade && grade <= 100) {
			System.out.println("A");
		}
		else if(80 <= grade) {
			System.out.println("B");
		}
		else if(70 <= grade) {
			System.out.println("C");
		}
		else if(60 <= grade) {
			System.out.println("D");
		}
		else {
			System.out.println("F");
		}
	}

}
