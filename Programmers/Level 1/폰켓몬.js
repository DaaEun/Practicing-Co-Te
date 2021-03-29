function solution(nums) {

    /*
    # 문제 알고리즘

    1. 폰켓몬의 종류를 획인하기 전에 최대로 가져갈 수 있는 폰켓몬 종류의 수(answer)은 N/2 이다.
    2. 연구실에 있는 폰켓몬의 종류를 세어본다.(중복 제거)
    3. 만약에 폰켓몬의 종류의 수가 N/2보다 크다면, 최대값인 N/2 개의 폰켓몬의 종류의 수를 가져간다.
    4. 만약에 폰켓몬의 종류의 수가 N/2보다 작다면, 같은 종류의 폰켓몬을 무조건 가져가므로 
    연구실에 있는 폰켓몬의 종류의 수를 가져간다.
    */
    var answer = nums.length/2;

    var set = new Set(nums);
    var count = set.size;

    if(count >= answer){
        return answer;
    }

    if(count < answer){
        return count;
    }
}