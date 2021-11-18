package q2220;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] heap = new int[n+1];
		
		heap[n] = 1;
		for(int i = 1; i < n; i++) {
			for(int j = i; j > 1; j /= 2)
				heap[j] = heap[j/2];
			heap[1] = i + 1;
		}
		for(int k = 1; k <= n; k++) 
			System.out.print(heap[k] + " ");
		sc.close();
	}
}