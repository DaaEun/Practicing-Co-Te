function solution(N, stages) {
    var answer = [];
    var failRates = []; // 실패율
    
    // 1. 각 스테이지의 실패율 계산
    for(var j = 0; j < N; j++){
        var child = 0;  // 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수
        var mom = 0;    // 스테이지에 도달한 플레이어 수

        for(var i = 0; i < stages.length; i++){
            if(stages[i] == j+1)    child++;
            if(stages[i] >= j+1)    mom++;
        }

        // 제한사항 5.
        // 스테이지에 도달한 플레이어가 없을 경우 > mom = 0 인 경우 > 실패율 0
        if(mom == 0)    
            failRates[j] = 0;
        else
            failRates[j] = parseFloat(child / mom);

    }// j-for문 종료 
        
    // 2. 실패율이 높은 스테이지부터 내림차순 정렬
    for(var n = 0; n < N; n++){
        var maxRate = Math.max.apply(null, failRates);  // 가장 높은 실패율

        for(var m = 0; m < N; m++){
            if(failRates[m] == maxRate){
                answer.push(m+1);   // maxRate과 같은 실패율의 스테이지 번호 출력
                failRates[m] = null;  // 해당 실패율 값 제거 
                break;
            }
        }
    }
    return answer;
}
