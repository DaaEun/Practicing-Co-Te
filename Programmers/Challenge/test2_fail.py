import re

def solution(s):
    answer = 0

    for i in range(len(s)):
        tmp = s[i:] + s[:i]
        for t in tmp:
            if t == '[':
                if ']' in tmp:
                    tmp = re.sub(t,'', tmp)
                    tmp.pop(tmp.find(']'))
        tmp1 = re.sub('\[[\{\}\(\)]*\]', '', tmp)
        tmp2 = re.sub('\{(\[|\]|\(|\))\}', '', tmp1)
        tmp3 = re.sub('\((\{|\}|\{|\})\)', '', tmp2)

        if not tmp3:
            answer += 1
        
    return answer