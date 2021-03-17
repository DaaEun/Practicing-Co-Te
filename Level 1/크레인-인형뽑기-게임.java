import java.util.*;

class Solution {

	public static int solution(int[][] board, int[] moves) {

		Stack<Integer> box = new Stack<>();
		int answer = 0;

		for(int i=0; i<moves.length; i++) {
			for(int j=0; j<board.length; j++) {
				if(board[j][moves[i]-1] != 0) {
                    if(box.isEmpty())   box.push(board[j][moves[i]-1]);
                    else{
                        if(box.peek() == board[j][moves[i]-1]){
                            box.pop();
                            answer += 2;
                        }
                        else{
                            box.push(board[j][moves[i]-1]);
                        }   
		            }
                    board[j][moves[i]-1] = 0;
					break;
	            }
            }
        }
        return answer;
    }
}