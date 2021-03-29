//소수 판별 함수
function isPrime(n) {
    if (n <= 1) {
      return false;
    }
    if (n === 2 || n === 3) {
      return true;
    }
    if (n % 2 === 0) {
      return false;
    }
    let divisor = 3;
    let limit = Math.sqrt(n);
    while (limit >= divisor) {
      if (n % divisor === 0) {
        return false;
      }
      divisor += 2;
    }
    return true;
}
  
function solution(numbers) {
    var answer = 0;
    
    let set = new Set();
    numOfCase(numbers,'');

    // 완전탐색 함수
    function numOfCase(arr,str) {
        if(arr.length) {
            for(let i = 0; i <arr.length; i++) {
                let copy = [...arr];    // 객체를 배열로 
                copy.splice(i,1);
                numOfCase(copy,str + arr[i])
            }
        }
        // console.log(str);
        if(str > 0) set.add(Number(str));
    }
    
    for (let num of set) {
    isPrime(num)? answer++: answer;
    }
    return answer;
}