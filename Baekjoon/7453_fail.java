import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();

		int[][] ABCD = new int[4][n];		
		for(int i = 0; i < n; i++) {
			String str = sc.nextLine();
			String[] abcd = str.split(" ");
			for(int j = 0; j < 4; j++)	
				ABCD[j][i] = Integer.parseInt(abcd[j]);
		}

		int n2 = (int) Math.pow(n, 2);
		long[] AB = new long[n2];
		long[] CD = new long[n2];

		int idx = 0;
		for(long a : ABCD[0]) {
			for(long b : ABCD[1]) { 
				AB[idx] = a+b;
				idx++;
			}
		}

		idx = 0;
		for(long c : ABCD[2]) {
			for(long d : ABCD[3]) {
				CD[idx] = c+d;
				idx++;
			}
		}


		Arrays.sort(AB);
		Arrays.sort(CD);
		
		int answer = 0;
		int point = n2-1;

		for(int i=0; i <n2; i++){

			if(AB[i] <= 0) {
				for(int idx2 = n2-1; idx2 >= 0; idx2--) {
					if(CD[idx2] < 0) {
						point = idx2; 
						break;
					}
					else {
						if(AB[i] + CD[idx2] == 0) answer++;
						else if(AB[i] + CD[idx2] < 0) break; 
					}
				}
			}//if-end
			else { 
				for(int idx3 = 0; idx3 <= point; idx3++) {
					if(AB[i] + CD[idx3] == 0) answer++;
					else if(AB[i] + CD[idx3] > 0) break; 
				}
			}//else-end
		}

		System.out.println(answer);
		sc.close();
	}
}