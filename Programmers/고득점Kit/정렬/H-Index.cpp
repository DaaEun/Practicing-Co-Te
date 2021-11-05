/*
	���� ����
	H-Index�� �������� ���꼺�� ������� ��Ÿ���� ��ǥ�Դϴ�. 
	��� �������� H-Index�� ��Ÿ���� ���� h�� ���Ϸ��� �մϴ�. 
	��Ű���1�� ������, H-Index�� ������ ���� ���մϴ�.

	� �����ڰ� ��ǥ�� �� n�� ��, h�� �̻� �ο�� ���� h�� �̻��̰� 
	������ ���� h�� ���� �ο�Ǿ��ٸ� h�� �ִ��� �� �������� H-Index�Դϴ�.

	� �����ڰ� ��ǥ�� ���� �ο� Ƚ���� ���� �迭 citations�� �Ű������� �־��� ��, 
	�� �������� H-Index�� return �ϵ��� solution �Լ��� �ۼ����ּ���.


	���ѻ���
	- �����ڰ� ��ǥ�� ���� ���� 1�� �̻� 1,000�� �����Դϴ�.
	- ���� �ο� Ƚ���� 0ȸ �̻� 10,000ȸ �����Դϴ�.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(),greater<int>());	//sort(start, end, grearter<>()) : ���� �������� ����
	//���� ū���� 0�� ��� answer = 0;
	
	if (!citations[0]) return answer;	//citations�� �������� ������ �ٷ� 0 ���.

	for (int i = 0; i < citations.size(); i++) {
		if (citations[i] > i) answer++;
		else break;
	}
	return answer;
	//for (int i = 0; i <= citations[citations.size() - 1]; i++) {
	//	
	//	int start = 0;
	//	for (; start < citations.size(); start++) {
	//		if (citations[start] >= i)	break;
	//	}

	//	//cout << i << "�� �̻�" << start << citations.size() - start << endl;
	//	cout << i << "�� �̻� �ο�� ���� " << start + 1 << "�� �̻��̰�, ������ ���� "
	//		<< citations.size() - (start + 1) << "���� �ο�" << endl;

	//	if (citations.size() - start >= i) {
	//		answer = i;
	//	}
	//}//for-end
	//
	//return answer;
}