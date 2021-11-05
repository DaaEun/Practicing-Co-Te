/*
	문제 설명
	n명이 입국심사를 위해 줄을 서서 기다리고 있습니다. 각 입국심사대에 있는 심사관마다 심사하는데 걸리는 시간은 다릅니다.
	처음에 모든 심사대는 비어있습니다. 한 심사대에서는 동시에 한 명만 심사를 할 수 있습니다. 
	가장 앞에 서 있는 사람은 비어 있는 심사대로 가서 심사를 받을 수 있습니다. 
	하지만 더 빨리 끝나는 심사대가 있으면 기다렸다가 그곳으로 가서 심사를 받을 수도 있습니다.
	모든 사람이 심사를 받는데 걸리는 시간을 최소로 하고 싶습니다.

	입국심사를 기다리는 사람 수 n, 각 심사관이 한 명을 심사하는데 걸리는 시간이 담긴 배열 times가 매개변수로 주어질 때, 
	모든 사람이 심사를 받는데 걸리는 시간의 최솟값을 return 하도록 solution 함수를 작성해주세요.

	제한사항
	- 입국심사를 기다리는 사람은 1명 이상 1,000,000,000명 이하입니다.
	- 각 심사관이 한 명을 심사하는데 걸리는 시간은 1분 이상 1,000,000,000분 이하입니다.
	- 심사관은 1명 이상 100,000명 이하입니다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long answer;

bool check(unsigned long long mid, unsigned long long n, vector<int>& times) {
	
	unsigned long long cnt = 0;
	for (int i = 0; i < times.size(); i++) {
		cnt += mid / times[i];
	}
	return cnt >= n ? true : false;
}

void paSearch(unsigned long long start, unsigned long long end, unsigned long long n, vector<int>& times) {

	if (start >= end) {
		return;
	}
	unsigned long long mid = (start + end) / 2;

	if (check(mid, n, times)) {
		answer = min(answer, mid);
		paSearch(start, mid, n, times);
	}
	else {
		paSearch(mid + 1, end, n, times);
	}
}

long long solution(int n, vector<int> times) {

	sort(times.begin(), times.end());

	unsigned long long start = 1;	//제일 적게 걸릴 시간
	unsigned long long end = times[times.size() - 1] * n + 1;	//제일 많이 걸릴 시간
	answer = end;
	paSearch(start, end, n, times);

	return answer;
}

/*
	# 파라메트릭 서치(Parametric Search)
	1. 최적화 문제(문제의 상황을 만족하는 특정 변수의 최솟값, 최댓값을 구하는 문제)를 결정 문제(decision problem)로 바꾸어 푸는 것이다.
	2. 예를 들어 범위 내에서 조건을 만족하는 가장 큰 값을 찾는 최적화 문제라면 이분 탐색으로 결정 문제를 해결하면서 범위를 좁혀갈 수 있다.
	[출처] : https://velog.io/@lake/%EC%9D%B4%EB%B6%84%ED%83%90%EC%83%89-%ED%8C%8C%EB%9D%BC%EB%A9%94%ED%8A%B8%EB%A6%AD-%EC%84%9C%EC%B9%98Parametric-Search

	쉽게 말하면 파라메트릭 서치는 이분 탐색을 응용한 것이며 기본적인 탐색 과정은 동일하고,
	내가 원하는 중앙값(mid)이 배열의 특정한 값을 찾는 것이 아닌, 내가 원하는 조건에 맞는지 검사해야 한다.

	
	### 해당 문제에서 나오는 수의 범위는 unsigned long long 범위 내에서 해결된다.
	### 해당 시간(mid)가 조건에 맞는지(n명 이상을 심사할 수 있는지)를 확인하려면 
	시간(mid)를 각 심사위원이 심사에 걸리는 시간으로 나누어서 더하여 n과 비교하면 된다.
*/


