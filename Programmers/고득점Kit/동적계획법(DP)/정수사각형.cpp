/*
	문제 설명
	위와 같은 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 찾아보려고 합니다. 
	아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로만 이동 가능합니다. 
	예를 들어 3에서는 그 아래칸의 8 또는 1로만 이동이 가능합니다.

	삼각형의 정보가 담긴 배열 triangle이 매개변수로 주어질 때, 거쳐간 숫자의 최댓값을 return 하도록 solution 함수를 완성하세요.

	제한사항
	- 삼각형의 높이는 1 이상 500 이하입니다.
	- 삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수입니다.
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
			if (j == 0) {	//삼각형의 맨 앞의 수(가장 왼쪽의 수)
				dp[i][j] = triangle[i][j] + dp[i - 1][0];
			}
			else if (j == triangle[i].size() - 1) {		//삼각형의 맨 뒤의 수(가장 오른쪽의 수)
				dp[i][j] = triangle[i][j] + dp[i - 1][j-1];
			}
			else {
				dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}
	for (int i = 0; i < triangle[triangle.size() - 1].size(); i++) {	//0 ~ 삼각형 마지막 줄의 마지막 숫자 인덱스
		answer = max(answer, dp[triangle.size() - 1][i]);
	}
	return answer;
}