import sys

# 이분탐색 함수
def BinarySearch(num, n_list, left, right):
    if(left > right):
        return False

    mid = (left + right) // 2
    if(n_list[mid] < num):
        return BinarySearch(num, n_list, mid+1, right)
    elif(n_list[mid] > num):
        return BinarySearch(num, n_list, left, mid-1)
    else:        
        return True

# main
n = int(sys.stdin.readline())
n_list = sorted(list(map(int, sys.stdin.readline().split())))
m = int(sys.stdin.readline())
m_list = list(map(int, sys.stdin.readline().split()))

for num in m_list:
    if BinarySearch(num, n_list, 0, n-1):
        print(1)
    else:
        print(0)    