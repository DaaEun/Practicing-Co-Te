/*
	문제 설명
	어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.
	예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.

	문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다. 
	number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.


	제한 조건
	- number는 1자리 이상, 1,000,000자리 이하인 숫자입니다.
	- k는 1 이상 number의 자릿수 미만인 자연수입니다.
*/
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	int len = number.length() - k;

	for (int i = 0, idx = -1; i < len; i++) {
		char max = '0';
		for (int j = idx + 1; j <= k + i; j++) {	
		//idx + 1 한 이유는 자기자신에 대한 탐색을 막기위함.
		//효율성 안따지면 idx=0, j=idx 가능

		//j <= k + i 에서 +i 한 이유는 answer에 문자를 하나씩 추가하니까.

			if (max < number[j]) {
				max = number[j];
				idx = j;
			}
		}
		answer += max;
	}//for-end
	return answer;
}