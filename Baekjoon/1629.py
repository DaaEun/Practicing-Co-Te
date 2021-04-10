import sys

# 분할정복 알고리즘 재귀함수
def Divide_Conquer(base, power, division):
    if power == 1:
        return base % division

    if power % 2 == 0:
        tmp = Divide_Conquer(base, power/2, division)
        return (tmp * tmp) % division

    else:
        tmp = Divide_Conquer(base, (power-1)/2, division)
        return (tmp * tmp * base) % division

# main
a,b,c = map(int,sys.stdin.readline().split()) 
print(Divide_Conquer(a,b,c))