import sys

# DFS 깊이우선탐색 알고리즘
def dfs(v):
    print(v, end=' ')
    visit[v] = 1
    for i in range(1, n + 1):
        if visit[i] == 0 and graph[v][i] == 1:
            dfs(i)

# BFS 너비우선탐색 알고리즘
def bfs(v):
    queue = [v]
    visit[v] = 0
    while(queue):
        v = queue[0]
        print(v, end=' ')
        del queue[0]
        for i in range(1, n + 1):
            if visit[i] == 1 and graph[v][i] == 1:
                queue.append(i)
                visit[i] = 0

# main

# n = 정점(node)의 수
# m = 간선의 수
# v = 탐색을 시작할 정점의 번호(start_node)
# n,m,v 입력받기
n, m, v = map(int,sys.stdin.readline().split())

# n+1 하는 이유? node 번호와 접근할 인덱스의 번호를 같도록 하기 위함.
# graph = 탐색할 그래프
# visit = 방문한 node / 0이면 방문X, 1이면 방문O
graph = [[0]*(n+1) for i in range(n+1)]
visit = [0 for i in range(n+1)]

# graph 입력받기
for i in range(m):
    x, y = map(int,sys.stdin.readline().split()) 
    graph[x][y] = 1
    graph[y][x] = 1

print(graph)
print(visit)

dfs(v)
print()
bfs(v)