package incomplete_marathoner;

import java.util.Arrays;

public class Solution2 {

	 public String solution(String[] participant, String[] completion) {
		 	
	        Arrays.sort(participant);
	        Arrays.sort(completion);
		 	String answer = participant[completion.length];

	        for (int i = 0; i < completion.length; i++) {
	            if (!participant[i].equalsIgnoreCase(completion[i]))
	                return participant[i];
	        }

	        return answer;
	    }
}
