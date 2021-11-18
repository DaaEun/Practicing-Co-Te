package q11399;

import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		int total_time = 0;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		String str = sc.nextLine();
		String[] arr = str.split(" ");
		int[] time = Arrays.stream(arr).mapToInt(Integer::parseInt).toArray();
		Arrays.sort(time);
		for(int i = 0; i < n; i++) {
			total_time += time[i]*(n-i);
		}
		System.out.println(total_time);
		sc.close();
	}
}
