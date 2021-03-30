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

		int[] AB = new int[n*n];
		int[] CD = new int[n*n];

		int idx = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				AB[idx] = ABCD[0][i] + ABCD[1][j];
				CD[idx] = ABCD[2][i] + ABCD[3][j];
				idx++;
			}
		}

		Arrays.sort(AB);
		Arrays.sort(CD);
		
	    int AB_idx = 0;
	    int CD_idx = CD.length-1;
		long answer = 0;
		while(AB_idx < AB.length && CD_idx >= 0) {
			long AB_sum = AB[AB_idx];
			long CD_sum = CD[CD_idx];
			long sum = AB_sum + CD_sum;
			int AB_cnt = 0;
			int CD_cnt = 0;
			if(sum == 0) {
				while(AB_idx < AB.length && AB[AB_idx] == AB_sum) {
					AB_idx++;
					AB_cnt++;
				}
				while(CD_idx >= 0 && CD[CD_idx] == CD_sum) {
					CD_idx--;
					CD_cnt++;
				}
				answer += AB_cnt * CD_cnt;
			} 
			else if(sum > 0) {
				CD_idx--;
			}
			else {
				AB_idx++;
			}
		}
		System.out.println(answer);
		sc.close();
	}
}
// 런타임 에러 (X)
// 틀렸습니다.(O)