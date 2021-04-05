def solution(prices):

    # answer 리스트의 크기와 초기화 값들을 선언한다.
    answer = [0]* len(prices)

    # prices의 인덱스를 담을 list를 선언한다.
    stack = []
    
    for i, price in enumerate(prices):

        # stack안에 값들이 존재하고 가격이 이전 시간의 가격보다 떨어지면 while문을 실행한다.
        while stack and price < prices[stack[-1]]:
            # stack안에서 해당 값(해당 가격이 위치하는 인덱스)을 pop한다.
            pre_i = stack.pop()
            # 해당 가격이 떨어지는데 걸린 시간(단위 : 초) = 현재 가격의 인덱스 - 해당 가격의 인덱스를 뺀 시간
            answer[pre_i] = i - pre_i
        
        # append()는 stack에서 push와 같은 역할이다.
        stack.append(i)
 
    # 끝까지 떨어지지 않은 가격들에 대한 시간들을 저장하기 위해
    # stack안에 남은 값들을 pop한다.
    while stack:
        no_fall_i = stack.pop()
        answer[no_fall_i] = (len(prices) - 1) - no_fall_i

    return answer