/*
	���� ����
	� ���ڿ��� k���� ���� �������� �� ���� �� �ִ� ���� ū ���ڸ� ���Ϸ� �մϴ�.
	���� ���, ���� 1924���� �� �� ���� �����ϸ� [19, 12, 14, 92, 94, 24] �� ���� �� �ֽ��ϴ�. �� �� ���� ū ���ڴ� 94 �Դϴ�.

	���ڿ� �������� ���� number�� ������ ���� ���� k�� solution �Լ��� �Ű������� �־����ϴ�. 
	number���� k ���� ���� �������� �� ���� �� �ִ� �� �� ���� ū ���ڸ� ���ڿ� ���·� return �ϵ��� solution �Լ��� �ϼ��ϼ���.


	���� ����
	- number�� 1�ڸ� �̻�, 1,000,000�ڸ� ������ �����Դϴ�.
	- k�� 1 �̻� number�� �ڸ��� �̸��� �ڿ����Դϴ�.
*/
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	int len = number.length() - k;

	for (int i = 0, idx = -1; i < len; i++) {
		char max = '0';
		for (int j = idx + 1; j <= k + i; j++) {	
		//idx + 1 �� ������ �ڱ��ڽſ� ���� Ž���� ��������.
		//ȿ���� �ȵ����� idx=0, j=idx ����

		//j <= k + i ���� +i �� ������ answer�� ���ڸ� �ϳ��� �߰��ϴϱ�.

			if (max < number[j]) {
				max = number[j];
				idx = j;
			}
		}
		answer += max;
	}//for-end
	return answer;
}