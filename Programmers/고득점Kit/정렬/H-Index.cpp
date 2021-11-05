/*
	문제 설명
	H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 
	어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 
	위키백과1에 따르면, H-Index는 다음과 같이 구합니다.

	어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 
	나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index입니다.

	어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 
	이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.


	제한사항
	- 과학자가 발표한 논문의 수는 1편 이상 1,000편 이하입니다.
	- 논문별 인용 횟수는 0회 이상 10,000회 이하입니다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(),greater<int>());	//sort(start, end, grearter<>()) : 인자 내림차순 정렬
	//제일 큰값이 0인 경우 answer = 0;
	
	if (!citations[0]) return answer;	//citations이 존재하지 않으면 바로 0 출력.

	for (int i = 0; i < citations.size(); i++) {
		if (citations[i] > i) answer++;
		else break;
	}
	return answer;
	//for (int i = 0; i <= citations[citations.size() - 1]; i++) {
	//	
	//	int start = 0;
	//	for (; start < citations.size(); start++) {
	//		if (citations[start] >= i)	break;
	//	}

	//	//cout << i << "번 이상" << start << citations.size() - start << endl;
	//	cout << i << "번 이상 인용된 논문이 " << start + 1 << "편 이상이고, 나머지 논문이 "
	//		<< citations.size() - (start + 1) << "이하 인용" << endl;

	//	if (citations.size() - start >= i) {
	//		answer = i;
	//	}
	//}//for-end
	//
	//return answer;
}