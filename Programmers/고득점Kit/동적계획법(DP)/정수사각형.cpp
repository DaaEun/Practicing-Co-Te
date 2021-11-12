/*
	���� ����
	���� ���� �ﰢ���� ����⿡�� �ٴڱ��� �̾����� ��� ��, ���İ� ������ ���� ���� ū ��츦 ã�ƺ����� �մϴ�. 
	�Ʒ� ĭ���� �̵��� ���� �밢�� �������� �� ĭ ������ �Ǵ� �������θ� �̵� �����մϴ�. 
	���� ��� 3������ �� �Ʒ�ĭ�� 8 �Ǵ� 1�θ� �̵��� �����մϴ�.

	�ﰢ���� ������ ��� �迭 triangle�� �Ű������� �־��� ��, ���İ� ������ �ִ��� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

	���ѻ���
	- �ﰢ���� ���̴� 1 �̻� 500 �����Դϴ�.
	- �ﰢ���� �̷�� �ִ� ���ڴ� 0 �̻� 9,999 ������ �����Դϴ�.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
	int answer = 0;

	dp[0][0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			if (j == 0) {	//�ﰢ���� �� ���� ��(���� ������ ��)
				dp[i][j] = triangle[i][j] + dp[i - 1][0];
			}
			else if (j == triangle[i].size() - 1) {		//�ﰢ���� �� ���� ��(���� �������� ��)
				dp[i][j] = triangle[i][j] + dp[i - 1][j-1];
			}
			else {
				dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}
	for (int i = 0; i < triangle[triangle.size() - 1].size(); i++) {	//0 ~ �ﰢ�� ������ ���� ������ ���� �ε���
		answer = max(answer, dp[triangle.size() - 1][i]);
	}
	return answer;
}