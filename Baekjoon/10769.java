import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		String[] arr = str.split(":-");
		int happy = 0;
		int sad = 0;
		for(String a : arr) {
			String temp = a.substring(0,1);
			if(temp.equals(")")) happy++;
			if(temp.equals("(")) sad++;
		} //for-end

		if(happy == 0 && sad == 0) System.out.println("none");
		else {
			if(happy == sad) System.out.println("unsure");
			else if(happy > sad) System.out.println("happy");
			else System.out.println("sad");
		}
		sc.close();
	}
}