/*
	문제 설명
	두 개의 단어 begin, target과 단어의 집합 words가 있습니다. 
	아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.

	1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
	2. words에 있는 단어로만 변환할 수 있습니다.

	예를 들어 begin이 "hit", target가 "cog", words가 ["hot","dot","dog","lot","log","cog"]라면 
	"hit" -> "hot" -> "dot" -> "dog" -> "cog"와 같이 4단계를 거쳐 변환할 수 있습니다.

	두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 
	최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.

	제한사항
	- 각 단어는 알파벳 소문자로만 이루어져 있습니다.
	- 각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.
	- words에는 3개 이상 50개 이하의 단어가 있으며 중복되는 단어는 없습니다.
	- begin과 target은 같지 않습니다.
	- 변환할 수 없는 경우에는 0를 return 합니다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int visit[50];

// 최단거리 찾기 : BFS
int bfs(string begin, string target, vector<string> words) {
	queue<pair<int, string>> q;
	q.push({ 0,begin });

	int t_idx = 987654321;
	while (!q.empty()) {
		int start = q.front().first;
		begin = q.front().second;	// 비교하는 문자열 업데이트
		q.pop();

		for (int i = 0; i < words.size(); i++) {
			if (target.compare(words[i]) == 0) {	// target과 words[i]가 같은 경우
				t_idx = i;
			}
			if (begin.length() == words[i].length() && !visit[i]) {
			// 길이가 같은 경우
			// 방문하지 않은 경우
			// 두 가지 조건 모두 만족
				int diff = 0;
				for (int j = 0; j < begin.length(); j++) {	
					if (begin[j] != words[i][j]) {	//begin의 문자와 words[i]의 문자에서 같은 위치에서 같은 문자가 아닌 경우
						diff++;
					}
				}
				
				if (diff == 1) {	//diff = 1인 경우만 탐색 가능
					q.push({ i,words[i] });			// 해당 문자열 탐색
					visit[i] = visit[start] + 1;	// i번째 문자열이 start+1 문자열에 방문했음 표시
				}
			}
		}
	}//while-end
	if (t_idx == 987654321) {	// target이 words안에 존재하지 않는 경우
		return 0;
	}
	else {
		return visit[t_idx];
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	answer = bfs(begin, target, words);
	return answer;
}