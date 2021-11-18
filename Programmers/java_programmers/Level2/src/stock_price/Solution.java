package stock_price;

import java.util.*;

class Solution {
	
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        int time = 0;
		Stack<Integer> stack = new Stack<>();
		
		for(int price = 0; price < prices.length; price++) {
			
			if(stack.empty()) {
				stack.push(prices[price]);
			}
			else {
				int tmp = prices[price];
				
				if(stack.peek() <= tmp) {
					stack.push(tmp);
				}
				else {
//					time++;
					stack.pop();
				}
			}
			time++;
		}
		
		
		
		
		
		
		
        return answer;
    }
}

/*
import java.util.Stack;

class Solution {
    public int[] solution(int[] prices) {
        Stack<Integer> beginIdxs = new Stack<>();
        int i=0;
        int[] terms = new int[prices.length];

        beginIdxs.push(i);
        for (i=1; i<prices.length; i++) {
            while (!beginIdxs.empty() && prices[i] < prices[beginIdxs.peek()]) {
                int beginIdx = beginIdxs.pop();
                terms[beginIdx] = i - beginIdx;
            }
            beginIdxs.push(i);
        }
        while (!beginIdxs.empty()) {
            int beginIdx = beginIdxs.pop();
            terms[beginIdx] = i - beginIdx - 1;
        }

        return terms;
    }
}
*/