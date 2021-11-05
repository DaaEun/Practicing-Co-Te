/*
	문제 설명
	아래와 같이 5와 사칙연산만으로 12를 표현할 수 있습니다.

	12 = 5 + 5 + (5 / 5) + (5 / 5)
	12 = 55 / 5 + 5 / 5
	12 = (55 + 5) / 5

	5를 사용한 횟수는 각각 6,5,4 입니다. 그리고 이중 가장 작은 경우는 4입니다.

	이처럼 숫자 N과 number가 주어질 때, N과 사칙연산만 사용해서 표현 할 수 있는 방법 중 
	N 사용횟수의 최솟값을 return 하도록 solution 함수를 작성하세요.

	제한사항
	- N은 1 이상 9 이하입니다.
	- number는 1 이상 32,000 이하입니다.
	- 수식에는 괄호와 사칙연산만 가능하며 나누기 연산에서 나머지는 무시합니다.
	- 최솟값이 8보다 크면 -1을 return 합니다.
*/

//Dynamic Programming 어렵다...
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int answer = -1;

void dfs(int N, int cnt, int tmp, int number) {
// int N		문제 n
// int cnt		계산 횟수
// int tmp		계산 수
// int number	문제 number
// string s

	if (cnt > 8) return;	// cnt가 8초과이면 탈출

	if (tmp == number) {
		if (answer == -1 || cnt < answer) {	//처음 tmp와 number 일치하는 경우 OR cnt가 최솟값보다 작은 경우
			answer = cnt;	// answer 업데이트
		}
		return;
	}
	 
	int n = 0;
	
	for (int i = 0; i < 8; i++) {
		n = n * 10 + N;	// N ~ NNNNNN의 수
		dfs(N, cnt + i + 1, tmp + n, number);
		dfs(N, cnt + i + 1, tmp - n, number);
		dfs(N, cnt + i + 1, tmp * n, number);
		dfs(N, cnt + i + 1, tmp / n, number);
	}

}

int solution(int N, int number) {
	dfs(N, 0, 0, number);	//dfs(int N, int cnt, int tmp, int number)
	return answer;
}