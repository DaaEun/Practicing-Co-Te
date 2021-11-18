package math_test;

import java.util.*;

class Solution {
	
    public static int[] solution(int[] answers) {
        int[] answer= {};
        int[] arr1 = {1, 2, 3, 4, 5};
        int[] arr2 = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] arr3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
        
        for(int i=0; i<answers.length; i++) {
        	if(answers[i] == arr1[i%5]) {
        		num1++;
        	}
        	if(answers[i] == arr2[i%8]) {
        		num2++;
        	}
        	if(answers[i] == arr3[i%10]) {
        		num3++;
        	}	
        }
        
        if(num1>=num2 && num1>=num3) {
        	if(num1==num2 && num1==num3) {
        		answer = new int[] {1,2,3};
        	}
        	else if(num1==num2) {
        		answer = new int[] {1,2};
        	}
        	else if(num1==num3) {
        		answer = new int[] {1,3};
        	}
        	else {
        		answer = new int[] {1};
        	}
        }
        else if(num2>=num3){
        	if(num2==num3) {
        		answer = new int[] {2,3};
        	}
        	else {
        		answer = new int[] {2};
        	}
        }
        else{
        	answer = new int[] {3};
        }
   	
        return answer;
    }
    
    public static void main(String[] args) {
		
    	int[] answers = {1,2,3,4,5};
//    	int[] answers = {1,3,2,4,2};
    	int[] result = solution(answers);
    	System.out.println(Arrays.toString(result));
	}
}
