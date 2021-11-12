/*
	���� ����
	�Ʒ��� ���� 5�� ��Ģ���길���� 12�� ǥ���� �� �ֽ��ϴ�.

	12 = 5 + 5 + (5 / 5) + (5 / 5)
	12 = 55 / 5 + 5 / 5
	12 = (55 + 5) / 5

	5�� ����� Ƚ���� ���� 6,5,4 �Դϴ�. �׸��� ���� ���� ���� ���� 4�Դϴ�.

	��ó�� ���� N�� number�� �־��� ��, N�� ��Ģ���길 ����ؼ� ǥ�� �� �� �ִ� ��� �� 
	N ���Ƚ���� �ּڰ��� return �ϵ��� solution �Լ��� �ۼ��ϼ���.

	���ѻ���
	- N�� 1 �̻� 9 �����Դϴ�.
	- number�� 1 �̻� 32,000 �����Դϴ�.
	- ���Ŀ��� ��ȣ�� ��Ģ���길 �����ϸ� ������ ���꿡�� �������� �����մϴ�.
	- �ּڰ��� 8���� ũ�� -1�� return �մϴ�.
*/

//Dynamic Programming ��ƴ�...
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int answer = -1;

void dfs(int N, int cnt, int tmp, int number) {
// int N		���� n
// int cnt		��� Ƚ��
// int tmp		��� ��
// int number	���� number
// string s

	if (cnt > 8) return;	// cnt�� 8�ʰ��̸� Ż��

	if (tmp == number) {
		if (answer == -1 || cnt < answer) {	//ó�� tmp�� number ��ġ�ϴ� ��� OR cnt�� �ּڰ����� ���� ���
			answer = cnt;	// answer ������Ʈ
		}
		return;
	}
	 
	int n = 0;
	
	for (int i = 0; i < 8; i++) {
		n = n * 10 + N;	// N ~ NNNNNN�� ��
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