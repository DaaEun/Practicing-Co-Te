package k_number;

import java.util.*;

public class Solution {

	public static int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for(int i=0; i<commands.length; i++) {
        	ArrayList<Integer> arr = new ArrayList<Integer>();
        	
        	for(int j=commands[i][0]-1; j<commands[i][1]; j++) {
        		arr.add(array[j]);
        	}
        	Collections.sort(arr);
        	answer[i]=arr.get(commands[i][2]-1);
        }
        return answer;
    }
	
	public static void main(String[] args) {
		
		int[] array = {1, 5, 2, 6, 3, 7, 4};
		int[][] commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
		int[] result = solution(array, commands);
		System.out.println(Arrays.toString(result));

	}

}
