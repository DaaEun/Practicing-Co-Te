package hate_same_num;

import java.util.*;

public class Solution {

	public static int[] solution(int []arr) {
		ArrayList<Integer> answer = new ArrayList<>();
		answer.add(arr[0]);
		int preNum = arr[0];
		
		for(int a : arr) {
			if(preNum != a) {
				answer.add(a);
				preNum = a;
			}
		}
		int[] ans = new int[answer.size()];
		
		for(int i=0; i<ans.length; i++) {
			ans[i] = answer.get(i);
		}
		return ans;
	}

	public static void main(String[] args) {

//		int[] arr = {1,1,3,3,0,1,1};
		int[] arr = {4,4,4,3,3};
		System.out.println(Arrays.toString(solution(arr)));
	}

}
