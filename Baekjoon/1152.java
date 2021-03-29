import java.util.Scanner;

// DaaEun 풀이 
// 메모리 	: 38388KB	시간 : 612ms
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		String[] arr = str.split(" ");
		
		int answer = arr.length;
		
		for(String i : arr) {
			if(i.equals("")) answer--;
		}
		System.out.println(answer);
		sc.close();
	}
}
