package pt_clothes;

import java.util.*;

class Solution {

	public static int solution(int n, int[] lost, int[] reserve) {

		Arrays.sort(lost);
		Arrays.sort(reserve);

		int answer = n-lost.length;

		for(int i=0; i<lost.length; i++) {

			for(int j=0; j<reserve.length; j++) {

				if(lost[i] == reserve[j]) {
					answer++;
					reserve[j] = -1;
					break;
				}
				else if(lost[i] ==reserve[j]+1) {
					if(j+1 < reserve.length && lost[i] == reserve[j+1]) {
						answer++;
						reserve[j+1] = -1;
						break;
					}
					else {
						answer++;
						reserve[j] = -1;
						break;
					}
				}
				else if(lost[i] == reserve[j]-1) {
					if(i+1 < lost.length && lost[i+1] == reserve[j]) {
						answer++;
						reserve[j] = -1;
						i++;
						break;
					}
					else {
						answer++;
						reserve[j] = -1;
						break;
					}
				}
			}
		}
		return answer;
	}

	public static void main(String[] args) {

		//    	int n = 5;
		//    	int[] lost = {2,4};
		//    	int[] reserve = {3};
		int n = 9;
		int[] lost = {2,4,7,8};
		int[] reserve = {3,6,9};

		int result = solution(n, lost, reserve);
		System.out.println(result);
	}
}
