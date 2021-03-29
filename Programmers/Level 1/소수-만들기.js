// 소수인지 아닌지 결정하는 함수
function isPrime(n){
    
    // n >= 6(= 1 + 2 + 3)
    // n=1, 2, 3 인 경우, 예외처리를 해야하나 n은 무조건 6 이상의 자연수이므로 생략했다.
    if (n % 2 === 0) {
        return false;
    }

    var divisor = 3;
    var root = Math.sqrt(n);
    while (root >= divisor) {
        if (n % divisor == 0) {
            return false;
        }
        divisor += 2;
    }
    return true;
}


function solution(nums) {
    var answer = 0;

    for(var i=0; i<(nums.length-2); i++){
        for(var j=i+1; j<(nums.length-1); j++){
            for(var k=j+1; k<nums.length; k++){
                // total = nums에서 3개 수의 합
                var total = nums[i]+nums[j]+nums[k];
                // 소수이면 answer 값을 1 증가
                isPrime(total)? answer++: answer;
            }
        }
    }
    return answer;
}