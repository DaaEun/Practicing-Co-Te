package claw_machine;

import java.util.Stack;

class Solution2 {
	public static int solution(int[][] board, int[] moves) {
		int answer = 0;
		Stack<Integer> s = new Stack<Integer>();
		for(int i=0; i<moves.length; i++) {
			for(int j=0; j<board.length; j++) {
				/* 
				 * 해당 칸에 인형이 존재하는경우
				 * ↓ 아래로 내려가므로 행의 값이 계속 바껴야함 (0,0), (1,0), (2,0) ...
				 * moves배열에 있는 요소를 board[][] 배열의 '열' 값에 넣어서 비교
				 * 배열의 인덱스는 0부터 시작하므로 -1
				 */ 
				if(board[j][moves[i]-1] != 0) {
					
					// 스택이 비어있는경우 -> 해당 인형 넣기
					if(s.isEmpty())
						s.push(board[j][moves[i]-1]);
					
					// 스택이 비어있지 않는경우 -> 인형이 동일한지 아닌지 비교
					else {
						// 인형이 동일하면 제거 후 사라진 인형개수 +2
						if(s.peek() == board[j][moves[i]-1]) {
							s.pop();
							answer += 2;
						}
						// 인형이 동일하지 않으면 스택에 인형 넣기
						else {
							s.push(board[j][moves[i]-1]);
						}
					}
					// 해당 작업 끝난 후에는 인형을 빼냈으므로 0으로 만든다.(인형이 없다는 표시)
					board[j][moves[i]-1] = 0;
					break;
				}
			}
		}
		return answer;
	}
	
	public static void main(String[] args) {

		int[][] board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
		int[] moves = {1,5,3,5,1,2,1,4};

		int result = solution(board,moves);

		System.out.println(result);
	} 
}