/*
	��������
	���α׷��ӽ� �������� ��� ���� �۾��� ���� ���Դϴ�. �� ����� ������ 100%�� �� ���񽺿� �ݿ��� �� �ֽ��ϴ�.

	��, �� ����� ���߼ӵ��� ��� �ٸ��� ������ �ڿ� �ִ� ����� �տ� �ִ� ��ɺ��� ���� ���ߵ� �� �ְ�, 
	�̶� �ڿ� �ִ� ����� �տ� �ִ� ����� ������ �� �Բ� �����˴ϴ�.

	���� �����Ǿ�� �ϴ� ������� �۾��� ������ ���� ���� �迭 progresses�� �� �۾��� ���� �ӵ��� ���� 
	���� �迭 speeds�� �־��� �� �� �������� �� ���� ����� �����Ǵ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.


	���� ����
	- �۾��� ����(progresses, speeds�迭�� ����)�� 100�� �����Դϴ�.
	- �۾� ������ 100 �̸��� �ڿ����Դϴ�.
	- �۾� �ӵ��� 100 ������ �ڿ����Դϴ�.
	- ������ �Ϸ翡 �� ���� �� �� ������, �Ϸ��� ���� �̷�����ٰ� �����մϴ�. 
	���� ��� �������� 95%�� �۾��� ���� �ӵ��� �Ϸ翡 4%��� ������ 2�� �ڿ� �̷�����ϴ�.
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

	vector<int> answer;
	int work = 0;	

	while (work < progresses.size()) {  // progresses.size()��ŭ ����
	
		queue<int> q;
		if (progresses[work] >= 100) {
			for (int i = work; i < progresses.size(); i++) {
				q.push(progresses[i]);
			}
			int cnt = 0;	// ������ �۾��� ���� count
		
			while (true) {
				if (q.front() >= 100 && !q.empty()) {
					cnt++;
					q.pop();
				}
				else {
					work += cnt;
					answer.push_back(cnt);	// cnt ���� answer�� �߰�
					break;
				}
			}
		}	// if-end
		else {
			for (int i = work; i < progresses.size(); i++) {	// �Ϸ��� �۾����� ����
				progresses[i] += speeds[i];
			}
		}
	}	// while-end
	return answer;
}