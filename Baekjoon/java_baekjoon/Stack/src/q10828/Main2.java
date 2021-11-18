package q10828;

import java.util.Scanner;
import java.util.Stack;

public class Main2 {

	public static void main(String[] args) {
		
		Stack<Integer> stack = new Stack<>();
		
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int n = sc.nextInt();
		
		for(int i = 0; i < n; i++) {
			String order = sc.next();

			switch (order) {
			case "push":
				stack.push(sc.nextInt());
				break;
				
			case "pop":
				if(stack.empty()) {
					sb.append(-1).append('\n');
					break;
				}
				else {
					sb.append(stack.peek()).append('\n');
					stack.pop();
					break;
				}

			case "size":
				sb.append(stack.size()).append('\n');
				break;
				
			case "empty":
				sb.append(stack.empty() ? 1 : 0).append('\n');
				break;
				
			case "top":
				if(stack.empty()) {
					sb.append(-1).append('\n');
					break;
				}
				else {
					sb.append(stack.peek()).append('\n');
					break;
				}
			} //switch-end
		} //for-end
		System.out.println(sb);
		sc.close();
	}

}
