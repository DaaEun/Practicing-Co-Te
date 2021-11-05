/*
	���� ����
	Leo�� ī���� �緯 ���ٰ� �Ʒ� �׸��� ���� �߾ӿ��� ��������� ĥ���� �ְ� �׵θ� 1���� �������� ĥ���� �ִ� ���� ��� ī���� �ý��ϴ�.
	Leo�� ������ ���ƿͼ� �Ʊ� �� ī���� ������� �������� ��ĥ�� ������ ������ ���������, ��ü ī���� ũ��� ������� ���߽��ϴ�.

	Leo�� �� ī�꿡�� ���� ������ �� brown, ����� ������ �� yellow�� �Ű������� �־��� �� 
	ī���� ����, ���� ũ�⸦ ������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.


	���ѻ���
	- ���� ������ �� brown�� 8 �̻� 5,000 ������ �ڿ����Դϴ�.
	- ����� ������ �� yellow�� 1 �̻� 2,000,000 ������ �ڿ����Դϴ�.
	- ī���� ���� ���̴� ���� ���̿� ���ų�, ���� ���̺��� ��ϴ�.
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	
	vector<int> answer;
	int sum = brown + yellow;

	for (int height = 3; height < sum; height++) {
		if (!(sum % height)) {
			int weight = sum / height;
			if ((height - 2) * (weight - 2) == yellow) {
				answer.push_back(weight);
				answer.push_back(height);
				break;
			}
		}
	}//for-end

	return answer;
}