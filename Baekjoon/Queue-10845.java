import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
	
		Queue<Integer> queue = new LinkedList<>();
		int last = 0;
		
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int n = sc.nextInt();
		
		for(int i = 0; i < n; i++) {
			String order = sc.next();

			switch (order) {
			case "push":
				last = sc.nextInt();
				queue.offer(last);
				break;
				
			case "pop":
				if(queue.isEmpty()) {
					sb.append(-1).append('\n');
					break;
				}
				else {
					sb.append(queue.poll()).append('\n');
					break;
				}

			case "size":
				sb.append(queue.size()).append('\n');
				break;
				
			case "empty":
				sb.append(queue.isEmpty() ? 1 : 0).append('\n');
				break;
				
			case "front":
				if(queue.isEmpty()) {
					sb.append(-1).append('\n');
					break;
				}
				else {
					sb.append(queue.peek()).append('\n');
					break;
				}
			case "back":
				if(queue.isEmpty()) {
					sb.append(-1).append('\n');
					break;
				}
				else {
					sb.append(last).append('\n');
					break;
				}
			} //switch-end
		} //for-end
		System.out.println(sb);
		sc.close();	
	}
}