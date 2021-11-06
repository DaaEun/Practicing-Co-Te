//TWpower's Tech Blog ����

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(int start, vector<int> graph[], bool check[]) {
	queue<int> q;

	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		printf("%d ", tmp);
		for (int i = 0; i < graph[tmp].size(); i++) {

			// �湮���� �ʾҴٸ�
			if (check[graph[tmp][i]] == false) {
				// ť�� �־��ְ� �湮������ ǥ���Ѵ�.
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = true;
			}
		}
	}

}

int main() {

	int n, m, start;
	cin >> n >> m >> start;

	vector<int> graph[n + 1];
	// Visual Studio�� ���
	/* ������ ���ؼ� �迭�� �������� ������ ��
	vector<int> * graph = new vector<int>[n+1];
	*/
	bool check[n + 1];
	fill(check, check + n + 1, false);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// Sorting�� �� �Ѱ���?
	// ���߿� �ϳ��� �������� ������ Ž���� �� node ���� ���������� �����ؾ��ϱ� ����
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	//bfs
	bfs(start, graph, check);
	printf("\n");

	return 0;
}
