function solution(dartResult) {
    var answer = 0;
    
    // 1. 다트게임 3번의 기회 문자열(점수,보너스,옵션 포함) 나누기
    var turns = dartResult.match(/\d{1,2}[SDT]\W?/g);
    console.log(turns);
    
    var num = [];       //점수
    var bonus = [];     //보너스
    var option = [];    //옵션
    var score = [];     //기회 당 총점
    
    for(var i = 0; i < 3; i++){
        
        //2. 각 기회에서 점수, 보너스, 옵션 값 받기
        num[i] = turns[i].match(/\d{1,2}/g);
        bonus[i] = turns[i].match(/[SDT]/g);
        option[i] = turns[i].match(/\W/gi);
        
        //3. 점수X보너스
        if(bonus[i] == 'S'){
            score[i] = Number(num[i]);
        }
        else if(bonus[i] == 'D'){
            score[i] = Math.pow(num[i],2);
        }
        else if(bonus[i] == 'T'){
            score[i] = Math.pow(num[i],3);
        }
        
        //4. 옵션 추가
        if(option[i] == '#'){
            score[i] *= (-1);
        }
        else if(option[i] == '*'){
            // i가 1과 2인 경우만
            if(i != 0){
                score[i-1] *= 2;
            }
            score[i] *= 2;
        }
        
    } //for문 end
    
    //5. score 합산
    answer = score.reduce((a,b) => (a+b));
    return answer;
}