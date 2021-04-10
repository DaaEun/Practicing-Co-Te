import sys
import re

# 입력값 받기
s = sys.stdin.readline().strip()

# s 문자열에서 'pi', 'ka', 'chu' 문자열 제거
tmp = re.sub('pi|ka|chu', '', s)

if not tmp:
    print('YES')
else:
    print('NO')    