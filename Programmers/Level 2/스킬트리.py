# 코드수정중
def solution(skill, skill_trees):
    answer = 0

    for skill_tree in skill_trees:
        reverse_skill_tree = skill_tree[::-1]
        do_tree = True
        i = 0
        for later_skill in skill[::-1]:
            do_skill = False

            # if(i == len(skill_tree)):
            #     break        

            for j in range(i, len(skill_tree)):
                if(reverse_skill_tree[j] == later_skill):
                    i = j + 1
                    do_skill = True
                    break

        #     if(do_skill == False):
        #         do_tree = False
        #         break

        # if(do_tree == True):
        #     print(skill_tree)
        #     answer += 1    

    return answer