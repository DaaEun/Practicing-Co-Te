package q10828;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		
		List<Integer> stack = new ArrayList<>();
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		
		for(int i = 0; i < n; i++) {
			String str = sc.nextLine();
			String[] order = str.split(" ");

			switch (order[0]) {
			case "push":
				stack.add(Integer.parseInt(order[1]));
				break;
				
			case "pop":
				if(stack.size() == 0) {
					System.out.println(-1);
					break;
				}
				else {
					System.out.println(stack.get(stack.size()-1));
					stack.remove(stack.size()-1);
					break;
				}
				
			case "size":
				System.out.println(stack.size());
				break;
				
			case "empty":
				System.out.println(stack.size() == 0 ? 1 : 0);
				break;
				
			case "top":
				if(stack.size() == 0) {
					System.out.println(-1);
					break;
				}
				else {
					System.out.println(stack.get(stack.size()-1));
					break;
				}
			} //switch-end
		} //for-end
		sc.close();
	}
}
//시간초과