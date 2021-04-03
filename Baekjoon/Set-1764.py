import sys

n , m = map(int, sys.stdin.readline().split())
no_listen = [sys.stdin.readline().strip() for i in range(n)]
no_see = [sys.stdin.readline().strip() for i in range(m)]

no_all = sorted(list(set(no_listen) & set(no_see)))

print(len(no_all))
for name in no_all:
    print(name)