/*
	문제 설명
	수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

	마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 
	완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.


	제한사항
	- 마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
	- completion의 길이는 participant의 길이보다 1 작습니다.
	- 참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
	- 참가자 중에는 동명이인이 있을 수 있습니다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// map은 인덱스를 문자열로 받을 수 있는 배열이라고 생각하자.
string solution(vector<string> participant, vector<string> completion) {

	string answer = "";

	map<string, int> map;
	int i;
	for (i = 0; i < completion.size(); i++) {
		map[completion[i]]++;
		map[participant[i]]++;
	}
	map[participant[i]]++;

	for (auto m : map) {	// 배열 요소와 같은 자료형을 가져야 하므로, auto 키워드를 사용해서 추론하도록 하는 것이 이상적.
		if (m.second % 2 != 0)	//map의 second : value
			answer = m.first;	//map의 first : key
	}
	return answer;
}