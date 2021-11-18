package incomplete_marathoner;

import java.util.ArrayList;

class Solution {

	public static String solution(String[] participant, String[] completion) {
		String answer = "";

		ArrayList<String> part = new ArrayList<>();
		for(String p : participant) part.add(p);

		for(int j=0; j<completion.length; j++) {
			if(part.contains(completion[j])) {
				part.remove(completion[j]);
			}
		}

		for(String p : part) {
			if(p != null) { 
				answer = p; 
				break;
			}
		}
		return answer;
	}

	public static void main(String[] args) {
		String[] participant = {"marina", "josipa", "nikola", "vinko", "filipa"};
		String[] completion  = {"josipa", "filipa", "marina", "nikola"};

		String incompl = solution(participant, completion);
		System.out.println(incompl);
	}
}
