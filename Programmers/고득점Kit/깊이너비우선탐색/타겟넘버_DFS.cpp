/*
	��������	
	n���� ���� �ƴ� ������ �ֽ��ϴ�. �� ���� ������ ���ϰų� ���� Ÿ�� �ѹ��� ������� �մϴ�. 
	���� ��� [1, 1, 1, 1, 1]�� ���� 3�� ������� ���� �ټ� ����� �� �� �ֽ��ϴ�.

	����� �� �ִ� ���ڰ� ��� �迭 numbers, Ÿ�� �ѹ� target�� �Ű������� �־��� �� 
	���ڸ� ������ ���ϰ� ���� Ÿ�� �ѹ��� ����� ����� ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

	���ѻ���
	�־����� ������ ������ 2�� �̻� 20�� �����Դϴ�.
	�� ���ڴ� 1 �̻� 50 ������ �ڿ����Դϴ�.
	Ÿ�� �ѹ��� 1 �̻� 1000 ������ �ڿ����Դϴ�.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int answer = 0;
int tnum;	//Ÿ�� �ѹ�

void dfs(int cnt, int tmp, vector<int>& numbers) {
//int tmp	��� ��

	if (cnt == numbers.size()) {	// cnt�� �迭 numbers ũ��� ���� ���
		if (tmp == tnum)	answer++;	//Ÿ�ٳѹ��� tmp�� ���� ��� answer!
		return;
	}

	int plus_tmp = tmp + numbers[cnt];	//����
	int minus_tmp = tmp - numbers[cnt];	//����

	dfs(cnt + 1, plus_tmp, numbers);
	dfs(cnt + 1, minus_tmp, numbers);
}

int solution(vector<int> numbers, int target) {
	tnum = target;
	dfs(0, 0, numbers);
	return answer;
}