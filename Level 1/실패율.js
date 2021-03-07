function solution(N, stages) {
    var answer = [];
    var failRates = [];
    
    for(var j = 0; j < N; j++){
        
        var child = 0;
        var mom = 0;
        for(var i = 0; i < stages.length; i++){
            
            if(stages[i] == j+1){
                child++;
            }
            if(stages[i] >= j+1){
                mom++;
            }
        }
        // 스테이지에 도달한 경우가 없을 경우 > mom = 0 인 경우 > 실패율 0
        if(mom == 0){
            failRates[j] = 0;
        }
        else{
        failRates[j] = parseFloat(child / mom);
        }
    }
    
    // console.log(failRates);
    
    for(var n = 0; n < N; n++){
        
        var maxRate = Math.max.apply(null, failRates);
        for(var j = 0; j < N; j++){
            if(failRates[j] == maxRate){
                answer.push(j+1);
                failRates[j] = -1;
                break;
            }
        }
         // console.log(failRates);
    }
    return answer;
}
