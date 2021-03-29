// row 계산함수
function cal_quotient(num){
    num = parseInt((num-1)/3);
    return num;
}
// col 계산함수
function cal_remainder(num){
    num = (num-1)%3;
    return num;
}

function solution(numbers, hand) {
    var answer = '';
    
    var leftPoint = '*';    // 처음 왼손 엄지손가락 위치
    var rightPoint = '#';   // 처음 오른손 엄지손가락 위치

    for(var num of numbers){
        switch(num) {

            // 2. 숫자 1, 4, 7을 입력할 때, leftPoint 사용
            case 1 :    case 4 :    case 7 :
                answer += 'L';
                leftPoint = num;    // 변경된 leftPoint
                break;

            // 3. 숫자 3, 6, 9를 입력할 때, rightPoint 사용    
            case 3 :    case 6 :    case 9 :
                answer += 'R';
                rightPoint = num;   // 변경된 rightPoint
                break;

            // 4. 숫자 2, 5, 8, 0을 입력할 때,
            case 2 :    case 5 :    case 8 :    case 0 : 
                
                // num 위치 표현 [numRow, numCol(=1)] 
                var numCol = 1;
                var numRow;
                if(num == 0) numRow = 3;
                else    numRow = cal_quotient(num);
                
                // leftPoint 위치 표현 [LPRow, LPCol]
                var LPRow, LPCol, RPRow, RPCol;
                if(leftPoint == '*'){   // 예외 1. leftPoint가 *인 경우
                    LPRow = 3;
                    LPCol = 0;
                }
                else if(leftPoint == 0){    // 예외 1. leftPoint가 0인 경우
                    LPRow = 3;
                    LPCol = 1;
                } 
                else{
                    LPRow = cal_quotient(leftPoint);
                    LPCol = cal_remainder(leftPoint);
                }
                
                // rightPoint 위치 표현 [RPRow, RPCol]
                if(rightPoint == '#'){  // 예외 1. rightPoint가 #인 경우
                    RPRow = 3;
                    RPCol = 2;
                }
                else if(rightPoint == 0){   // 예외 2. rightPoint가 0인 경우
                    RPRow = 3;
                    RPCol = 1;
                } 
                else{
                    RPRow = cal_quotient(rightPoint);
                    RPCol = cal_remainder(rightPoint);
                }
                
                // num과 엄지손가락 사이의 거리 구하기
                var leftDis = Math.abs(LPRow-numRow) + Math.abs(LPCol-numCol);
                var rightDis = Math.abs(RPRow-numRow) + Math.abs(RPCol-numCol);
                
                // 4. 두 엄지손가락의 위치에서 더 가까운 엄지손가락 사용
                if(leftDis < rightDis){
                    answer += 'L';
                    leftPoint = num;
                }
                else if(leftDis > rightDis){
                    answer += 'R';
                    rightPoint = num;
                }
                else{   // leftDis == rightDis -> hand로 결정
                    if(hand == "right"){
                        answer += 'R';
                        rightPoint = num;
                    }
                    else{
                        answer += 'L';
                        leftPoint = num;
                    }
                }
                break;
        }// switch 문 종료
    } // for 문 종료
    return answer;
}