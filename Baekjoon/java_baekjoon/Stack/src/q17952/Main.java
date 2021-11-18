package q17952;

import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();  

		Stack<Integer> stack = new Stack<>();
		int[][] assign = new int[n][2];
		int total = 0;

		for(int i = 0; i < n; i++) {
			int idx = sc.nextInt();
			
			if(idx == 1) {
				assign[i][0] = sc.nextInt();	// 과제 점수
				assign[i][1] = sc.nextInt();	// 과제 시간
				stack.add(i);
			}
			
			if(!stack.empty()){
				int doing = stack.peek();
				assign[doing][1]--;
				if(assign[doing][1] == 0) {
					stack.pop();
					total += assign[doing][0];
				}
			}
		}//for-end
		System.out.println(total);
		sc.close();
	}
}