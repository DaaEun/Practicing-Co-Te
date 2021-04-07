import sys

# 입력값 받기
n = int(sys.stdin.readline())
road = list(map(int, sys.stdin.readline().split()))
oilPrice = list(map(int, sys.stdin.readline().split()))

# 출력값, 총 비용 선언 및 초기화
total = 0

# 싼 금액의 기름 선언 및 초기화
cheap_oil = oilPrice[0]

for i, price in enumerate(oilPrice):

    # oilPrice의 크기가 road의 크기보다 1 크다.
    if(i == len(road)): break

    if(cheap_oil > price): 
        cheap_oil = price
    
    total += cheap_oil * road[i]    

print(total)