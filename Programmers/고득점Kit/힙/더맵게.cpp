/*
	���� ����
	�ſ� ���� �����ϴ� Leo�� ��� ������ ���ں� ������ K �̻����� ����� �ͽ��ϴ�. 
	��� ������ ���ں� ������ K �̻����� ����� ���� 
	Leo�� ���ں� ������ ���� ���� �� ���� ������ �Ʒ��� ���� Ư���� ������� ���� ���ο� ������ ����ϴ�.

	���� ������ ���ں� ���� = ���� ���� ���� ������ ���ں� ���� + (�� ��°�� ���� ���� ������ ���ں� ���� * 2)
	
	Leo�� ��� ������ ���ں� ������ K �̻��� �� ������ �ݺ��Ͽ� �����ϴ�.
	Leo�� ���� ������ ���ں� ������ ���� �迭 scoville�� ���ϴ� ���ں� ���� K�� �־��� ��, 
	��� ������ ���ں� ������ K �̻����� ����� ���� ����� �ϴ� �ּ� Ƚ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.


	���� ����
	- scoville�� ���̴� 2 �̻� 1,000,000 �����Դϴ�.
	- K�� 0 �̻� 1,000,000,000 �����Դϴ�.
	- scoville�� ���Ҵ� ���� 0 �̻� 1,000,000 �����Դϴ�.
	- ��� ������ ���ں� ������ K �̻����� ���� �� ���� ��쿡�� -1�� return �մϴ�.
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}

	while (!pq.empty()) {
		int a = pq.top();
		pq.pop();
		if (a >= K)
			break;
		else {	//��� ������ ���ں� ������ K �̻����� ���� �� ���� ��쿡�� -1�� return 
			if (pq.empty()) {
				return -1;
			}
		}

		int b = pq.top();
		pq.pop();
		pq.push(a + b * 2);
		answer++;

	}//while_end

	return answer;
}