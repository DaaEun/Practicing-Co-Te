package q2503;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		ArrayList<int[]> answers = new ArrayList<>();
		int[] answer = new int[3];
		for(int i = 1; i < 10; i++) {
			answer[0] = i;
			for(int j = 1; j < 10; j++) {
				answer[1] = j;
				for(int k = 1; k < 10; k++) {
					answer[2] = k;
					answers.add(answer);
				}
			}
		}
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
			
		for(int cnt = 0; cnt < n; cnt++) {
			int guess_num = sc.nextInt();
			int strike = sc.nextInt();
			int ball = sc.nextInt();
			

			int hundred = guess_num / 100;
			int rest = guess_num % 100;
			int ten = rest / 10;
			int one = rest % 10;
			
			switch(strike) {
			case 0:
				switch(ball) {
				case 0:
					for(int[] num : answers) {
						if(hundred == num[0] || hundred == num[1] || hundred == num[2] ||
								ten == num[0] || ten == num[1] || ten == num[2] ||
								one == num[0] || one == num[1] || one == num[2]) {
							answers.remove(num);
						}
					}
					break;
				case 1:
					for(int[] num : answers) {
						// hundred 1b
						if(hundred == num[0]) {
							answers.remove(num);
						}
						else if(hundred == num[1]) {
							if(ten == num[0] || ten == num[2] || one == num[0] || one == num[2]) {
								answers.remove(num);
							}
						}
						else if(hundred == num[2]) {
							if(ten == num[0] || ten == num[1] || one == num[0] || one == num[1]) {
								answers.remove(num);
							}
						}
						// ten 1b
						if(ten == num[0]) {
							if(hundred == num[1] || hundred == num[2] || one == num[1] || one == num[2]) {
								answers.remove(num);
							}
						}
						else if(ten == num[1]) {
							answers.remove(num);
						}
						else if(ten == num[2]) {
							if(hundred == num[0] || hundred == num[1] || one == num[0] || one == num[1]) {
								answers.remove(num);
							}
						}
						// one 1b
						if(one == num[0]) {
							if(hundred == num[1] || hundred == num[2] || ten == num[1] || ten == num[2]) {
								answers.remove(num);
							}
						}
						else if(one == num[1]) {
							if(hundred == num[0] || hundred == num[2] || ten == num[0] || ten == num[2]) {
								answers.remove(num);
							}
						}
						else if(one == num[2]) {
							answers.remove(num);
						}
					}
					break;
				case 2:
					for(int[] num : answers) {
						// hundred 1b && ten 1b
						if(hundred == num[0] || ten == num[1]) {
							answers.remove(num);
						}
						else if(hundred == num[1]) {
							if(ten != num[0] || ten != num[2] || one == num[0] || one == num[2]) {
								answers.remove(num);
							}
						}
						else if(ten == num[0]) {
							if(hundred != num[1] || hundred != num[2] || one == num[1] || one == num[2]) {
								answers.remove(num);
							}
						}
						// hundred 1b && one 1b
						if(hundred == num[0] || one == num[2]) {
							answers.remove(num);
						}
						else if(hundred == num[2]) {
							if(ten == num[0] || ten == num[1] || one != num[0] || one != num[1]) {
								answers.remove(num);
							}
						}
						else if(one == num[0]) {
							if(hundred != num[1] || hundred != num[2] || ten == num[1] || ten == num[2]) {
								answers.remove(num);
							}
						}
						// ten 1b && one 1b
						if(ten == num[1] || one == num[2]) {
							answers.remove(num);
						}
						else if(ten == num[2]) {
							if(hundred == num[0] || hundred == num[1] || one != num[0] || one != num[1]) {
								answers.remove(num);
							}
						}
						else if(one == num[1]) {
							if(hundred == num[0] || hundred == num[2] || ten != num[0] || ten != num[2]) {
								answers.remove(num);
							}
						}
					}
					break;
				case 3:

			case 1:
				switch(ball) {
				case 0:
				case 1:
				case 2:				
				}
			case 2:
				switch(ball) {
				case 0:
				case 1:
				}
			case 3:			
			}
		
		}
		
			
			
			
			
		}
		
		
		
		
		
		
		
		sc.close();
	}
}