/*
	���� ����
	�Ϲ����� �����ʹ� �μ� ��û�� ���� ������� �μ��մϴ�. 
	�׷��� ������ �߿��� ������ ���߿� �μ�� �� �ֽ��ϴ�. 
	�̷� ������ �����ϱ� ���� �߿䵵�� ���� ������ ���� �μ��ϴ� �����͸� �����߽��ϴ�. 
	�� ���Ӱ� ������ �����ʹ� �Ʒ��� ���� ������� �μ� �۾��� �����մϴ�.

	1. �μ� ������� ���� �տ� �ִ� ����(J)�� ����Ͽ��� �����ϴ�.
	2. ������ �μ� ����Ͽ��� J���� �߿䵵�� ���� ������ �� ���� �����ϸ� J�� ������� ���� �������� �ֽ��ϴ�.
	3. �׷��� ������ J�� �μ��մϴ�.

	���� ���, 4���� ����(A, B, C, D)�� ������� �μ� ����Ͽ� �ְ� �߿䵵�� 2 1 3 2 ��� C D A B ������ �μ��ϰ� �˴ϴ�.
	���� �μ⸦ ��û�� ������ �� ��°�� �μ�Ǵ��� �˰� �ͽ��ϴ�. ���� ������ C�� 1��°��, A�� 3��°�� �μ�˴ϴ�.
	
	���� ����Ͽ� �ִ� ������ �߿䵵�� ������� ��� �迭 priorities�� 
	���� �μ⸦ ��û�� ������ ���� ������� � ��ġ�� �ִ����� �˷��ִ� location�� �Ű������� �־��� ��, 
	���� �μ⸦ ��û�� ������ �� ��°�� �μ�Ǵ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.


	���ѻ���
	- ���� ����Ͽ��� 1�� �̻� 100�� ������ ������ �ֽ��ϴ�.
	- �μ� �۾��� �߿䵵�� 1~9�� ǥ���ϸ� ���ڰ� Ŭ���� �߿��ϴٴ� ���Դϴ�.
	- location�� 0 �̻� (���� ����Ͽ� �ִ� �۾� �� - 1) ������ ���� ������ ������� ���� �տ� ������ 0, �� ��°�� ������ 1�� ǥ���մϴ�.
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {

	int answer = 0;
	
	queue<pair<int, int>> prrty_idx;	//�߿䵵�� �ε��� ť
	priority_queue <int> prrty;			//�������� �߿䵵 ť
	
	for (int i = 0; i < priorities.size(); i++) {
		prrty_idx.push({ priorities[i], i });
		prrty.push(priorities[i]);
	}

	while (!prrty_idx.empty() && !prrty.empty()) {
		if (prrty_idx.front().first == prrty.top()) {	//prrty_idx ���� �� �߿䵵 ���ҿ� prrty�� �켱���� ���� ���Ұ� ���ٸ�
			answer++;

			if (prrty_idx.front().second == location) {	//prrty_idx ���� �� �ε��� ���ҿ� location�� ���ٸ�
				return answer;
			}
			prrty_idx.pop();
			prrty.pop();
		}
		else {	//�׷��� �ʴٸ�, �ش� prrty_idx ���Ұ��� �ڷ� ������.
			pair<int, int>temp = { prrty_idx.front().first, prrty_idx.front().second };
			prrty_idx.pop();
			prrty_idx.push(temp);
		}
	}	// while-end

	return answer;
}