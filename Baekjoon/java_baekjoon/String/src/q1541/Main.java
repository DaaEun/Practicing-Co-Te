package q1541;

import java.util.Scanner;

//DaaEun 풀이 
//메모리 	: 18320KB	시간 : 248ms
public class Main {

	public static void main(String[] args) {
	
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		String[] plus_arr = str.split("-");
		int answer = Integer.MAX_VALUE;
		for(int i = 0; i < plus_arr.length; i++) {
			int sum = 0;
			String[] nums = plus_arr[i].split("\\+");
			for(String num : nums) sum += Integer.parseInt(num);	
			if (answer == Integer.MAX_VALUE) answer = sum; 
			else answer -= sum;
		} // for-end
		System.out.println(answer);
		sc.close();
	}
}
