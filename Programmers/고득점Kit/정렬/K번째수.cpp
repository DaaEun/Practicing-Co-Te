/*
	��������
	�迭 array�� i��° ���ں��� j��° ���ڱ��� �ڸ��� �������� ��, k��°�� �ִ� ���� ���Ϸ� �մϴ�.

	���� ��� array�� [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3�̶��

	array�� 2��°���� 5��°���� �ڸ��� [5, 2, 6, 3]�Դϴ�.
	1. 1���� ���� �迭�� �����ϸ� [2, 3, 5, 6]�Դϴ�.
	2. 2���� ���� �迭�� 3��° ���ڴ� 5�Դϴ�.
	3. �迭 array, [i, j, k]�� ���ҷ� ���� 2���� �迭 commands�� �Ű������� �־��� ��, 
	commands�� ��� ���ҿ� ���� �ռ� ������ ������ �������� �� ���� ����� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

	���ѻ���
	- array�� ���̴� 1 �̻� 100 �����Դϴ�.
	- array�� �� ���Ҵ� 1 �̻� 100 �����Դϴ�.
	- commands�� ���̴� 1 �̻� 50 �����Դϴ�.
	- commands�� �� ���Ҵ� ���̰� 3�Դϴ�.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i < commands.size(); i++) {
		vector<int> v;
		for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
			v.push_back(array[j]);
		}
		sort(v.begin(), v.end());
		answer.push_back(v[commands[i][2] - 1]);
	}
	return answer;
}
