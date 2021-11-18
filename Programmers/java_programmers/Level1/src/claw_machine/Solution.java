package claw_machine;

import java.util.*;

class Solution {

	public static int solution(int[][] board, int[] moves) {

		ArrayList<Integer> box = new ArrayList<>();
		int answer = 0;

		for(int i=0; i<moves.length; i++) {
			for(int j=0; j<board.length; j++) {
				if(board[j][moves[i]-1] != 0) {
					box.add(board[j][moves[i]-1]);
					board[j][moves[i]-1] = 0;
					break;
				}
			}
		}
//		System.out.println(box);
		boolean flag = true;

		while(flag) {

			for(int i=1; i<box.size(); i++) {
				if(box.get(i-1) == box.get(i)) {
					box.remove(i);
					box.remove(i-1);
					answer += 2;
					break;
				}
			}

			for(int i=1; i<box.size(); i++) {
				if(box.get(i-1) == box.get(i)) {
					flag = true;
					break;
				}
				else flag = false;
			}
		}
//		System.out.println(box);
		return answer;
	}

	public static void main(String[] args) {

		int[][] board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
		int[] moves = {1,5,3,5,1,2,1,4};

		int result = solution(board,moves);

		System.out.println(result);
	} 
}
