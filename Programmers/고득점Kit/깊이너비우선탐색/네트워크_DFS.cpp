/*
	���� ����
	��Ʈ��ũ�� ��ǻ�� ��ȣ ���� ������ ��ȯ�� �� �ֵ��� ����� ���¸� �ǹ��մϴ�. 
	���� ���, ��ǻ�� A�� ��ǻ�� B�� ���������� ����Ǿ��ְ�, 
	��ǻ�� B�� ��ǻ�� C�� ���������� ����Ǿ� ���� �� 
	��ǻ�� A�� ��ǻ�� C�� ���������� ����Ǿ� ������ ��ȯ�� �� �ֽ��ϴ�. 
	���� ��ǻ�� A, B, C�� ��� ���� ��Ʈ��ũ �� �ִٰ� �� �� �ֽ��ϴ�.

	��ǻ���� ���� n, ���ῡ ���� ������ ��� 2���� �迭 computers�� �Ű������� �־��� ��, 
	��Ʈ��ũ�� ������ return �ϵ��� solution �Լ��� �ۼ��Ͻÿ�.

	���ѻ���
	- ��ǻ���� ���� n�� 1 �̻� 200 ������ �ڿ����Դϴ�.
	- �� ��ǻ�ʹ� 0���� n-1�� ������ ǥ���մϴ�.
	- i�� ��ǻ�Ϳ� j�� ��ǻ�Ͱ� ����Ǿ� ������ computers[i][j]�� 1�� ǥ���մϴ�.
	- computer[i][i]�� �׻� 1�Դϴ�.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool visit[200];

void dfs(int start, int n, vector<vector<int>> computers) {
	visit[start] = true;
	for (int i = 0; i < computers[start].size(); i++) {
		if (i != start && !visit[i] && computers[start][i]) {
		// i != start			�̹� �湮�ؼ� ��Ʈ��ũ üũ �� �ʿ� ����.
		// !visit[i]			�湮�� ��ǻ�� ����
		// computers[start][i]	�ش� ��ǻ�Ϳ� ����Ǿ� �־�� ��.
		// ���� �� ���� ������ ��� �����ؾ��� dfs ���డ��.
			dfs(i, n, computers);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < computers.size(); i++) {
		if (!visit[i]) {	// �ش� ��ǻ�� �湮���� ���� ���
			cout << i << endl;
			dfs(i, n, computers);	//dfs �˰������� ��Ʈ��ũ ����
			answer++;	//��Ʈ��ũ 1�� �߰�
		}
	}

	dfs(0, n, computers);

	return answer;
}