/*
	���� ����
	�� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �ֽ��ϴ�. 
	�Ʒ��� ���� ��Ģ�� �̿��Ͽ� begin���� target���� ��ȯ�ϴ� ���� ª�� ��ȯ ������ ã������ �մϴ�.

	1. �� ���� �� ���� ���ĺ��� �ٲ� �� �ֽ��ϴ�.
	2. words�� �ִ� �ܾ�θ� ��ȯ�� �� �ֽ��ϴ�.

	���� ��� begin�� "hit", target�� "cog", words�� ["hot","dot","dog","lot","log","cog"]��� 
	"hit" -> "hot" -> "dot" -> "dog" -> "cog"�� ���� 4�ܰ踦 ���� ��ȯ�� �� �ֽ��ϴ�.

	�� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �Ű������� �־��� ��, 
	�ּ� �� �ܰ��� ������ ���� begin�� target���� ��ȯ�� �� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

	���ѻ���
	- �� �ܾ�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
	- �� �ܾ��� ���̴� 3 �̻� 10 �����̸� ��� �ܾ��� ���̴� �����ϴ�.
	- words���� 3�� �̻� 50�� ������ �ܾ ������ �ߺ��Ǵ� �ܾ�� �����ϴ�.
	- begin�� target�� ���� �ʽ��ϴ�.
	- ��ȯ�� �� ���� ��쿡�� 0�� return �մϴ�.
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int visit[50];

// �ִܰŸ� ã�� : BFS
int bfs(string begin, string target, vector<string> words) {
	queue<pair<int, string>> q;
	q.push({ 0,begin });

	int t_idx = 987654321;
	while (!q.empty()) {
		int start = q.front().first;
		begin = q.front().second;	// ���ϴ� ���ڿ� ������Ʈ
		q.pop();

		for (int i = 0; i < words.size(); i++) {
			if (target.compare(words[i]) == 0) {	// target�� words[i]�� ���� ���
				t_idx = i;
			}
			if (begin.length() == words[i].length() && !visit[i]) {
			// ���̰� ���� ���
			// �湮���� ���� ���
			// �� ���� ���� ��� ����
				int diff = 0;
				for (int j = 0; j < begin.length(); j++) {	
					if (begin[j] != words[i][j]) {	//begin�� ���ڿ� words[i]�� ���ڿ��� ���� ��ġ���� ���� ���ڰ� �ƴ� ���
						diff++;
					}
				}
				
				if (diff == 1) {	//diff = 1�� ��츸 Ž�� ����
					q.push({ i,words[i] });			// �ش� ���ڿ� Ž��
					visit[i] = visit[start] + 1;	// i��° ���ڿ��� start+1 ���ڿ��� �湮���� ǥ��
				}
			}
		}
	}//while-end
	if (t_idx == 987654321) {	// target�� words�ȿ� �������� �ʴ� ���
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