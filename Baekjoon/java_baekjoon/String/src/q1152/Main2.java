package q1152;
import java.io.IOException;

//메모리 	: 38388KB	시간 : 612ms
public class Main2 {
 
	public static void main(String[] args) throws IOException {
 
		int answer = 0;
		int pre_str = 32;	// 공백을 의미한다.
		int str ;
		
		while(true) {
			str = System.in.read();
            
			// 입력받은 문자가 공백일 때,
			if(str == 32) {
				// 이전의 문자가 공백이 아니면
				if(pre_str != 32) answer++;
			}
			// 입력받은 문자가 개행일때 ('\n')
			else if(str == 10) {
				// 이전의 문자가 공백이 아니면
				if(pre_str != 32) answer++;
				break;
			}
			pre_str = str;
		} // while 문 종료
		System.out.println(answer);
	}
}