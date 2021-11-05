/*
	문제 설명
	네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미합니다. 
	예를 들어, 컴퓨터 A와 컴퓨터 B가 직접적으로 연결되어있고, 
	컴퓨터 B와 컴퓨터 C가 직접적으로 연결되어 있을 때 
	컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 정보를 교환할 수 있습니다. 
	따라서 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 수 있습니다.

	컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때, 
	네트워크의 개수를 return 하도록 solution 함수를 작성하시오.

	제한사항
	- 컴퓨터의 개수 n은 1 이상 200 이하인 자연수입니다.
	- 각 컴퓨터는 0부터 n-1인 정수로 표현합니다.
	- i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.
	- computer[i][i]는 항상 1입니다.
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
		// i != start			이미 방문해서 네트워크 체크 할 필요 없음.
		// !visit[i]			방문한 컴퓨터 제외
		// computers[start][i]	해당 컴퓨터와 연결되어 있어야 함.
		// 위의 세 가지 조건을 모두 만족해야지 dfs 진행가능.
			dfs(i, n, computers);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < computers.size(); i++) {
		if (!visit[i]) {	// 해당 컴퓨터 방문하지 않은 경우
			cout << i << endl;
			dfs(i, n, computers);	//dfs 알고리즘으로 네트워크 생성
			answer++;	//네트워크 1개 추가
		}
	}

	dfs(0, n, computers);

	return answer;
}