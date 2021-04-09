import sys

def Recursive_Power(C, n, division):
    if n == 1:
        return C % division

    if n % 2 == 0:
        y = Recursive_Power(C,n/2, division)
        return (y*y) % division

    else:
        y= Recursive_Power(C,(n-1)/2, division)
        return (y*y*C) % division

a,b,c = map(int,sys.stdin.readline().split()) 

print(Recursive_Power(a,b,c))