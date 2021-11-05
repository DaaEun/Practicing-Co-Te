/*
	���� ����
	n���� �Ա��ɻ縦 ���� ���� ���� ��ٸ��� �ֽ��ϴ�. �� �Ա��ɻ�뿡 �ִ� �ɻ������ �ɻ��ϴµ� �ɸ��� �ð��� �ٸ��ϴ�.
	ó���� ��� �ɻ��� ����ֽ��ϴ�. �� �ɻ�뿡���� ���ÿ� �� �� �ɻ縦 �� �� �ֽ��ϴ�. 
	���� �տ� �� �ִ� ����� ��� �ִ� �ɻ��� ���� �ɻ縦 ���� �� �ֽ��ϴ�. 
	������ �� ���� ������ �ɻ�밡 ������ ��ٷȴٰ� �װ����� ���� �ɻ縦 ���� ���� �ֽ��ϴ�.
	��� ����� �ɻ縦 �޴µ� �ɸ��� �ð��� �ּҷ� �ϰ� �ͽ��ϴ�.

	�Ա��ɻ縦 ��ٸ��� ��� �� n, �� �ɻ���� �� ���� �ɻ��ϴµ� �ɸ��� �ð��� ��� �迭 times�� �Ű������� �־��� ��, 
	��� ����� �ɻ縦 �޴µ� �ɸ��� �ð��� �ּڰ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

	���ѻ���
	- �Ա��ɻ縦 ��ٸ��� ����� 1�� �̻� 1,000,000,000�� �����Դϴ�.
	- �� �ɻ���� �� ���� �ɻ��ϴµ� �ɸ��� �ð��� 1�� �̻� 1,000,000,000�� �����Դϴ�.
	- �ɻ���� 1�� �̻� 100,000�� �����Դϴ�.
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

	unsigned long long start = 1;	//���� ���� �ɸ� �ð�
	unsigned long long end = times[times.size() - 1] * n + 1;	//���� ���� �ɸ� �ð�
	answer = end;
	paSearch(start, end, n, times);

	return answer;
}

/*
	# �Ķ��Ʈ�� ��ġ(Parametric Search)
	1. ����ȭ ����(������ ��Ȳ�� �����ϴ� Ư�� ������ �ּڰ�, �ִ��� ���ϴ� ����)�� ���� ����(decision problem)�� �ٲپ� Ǫ�� ���̴�.
	2. ���� ��� ���� ������ ������ �����ϴ� ���� ū ���� ã�� ����ȭ ������� �̺� Ž������ ���� ������ �ذ��ϸ鼭 ������ ������ �� �ִ�.
	[��ó] : https://velog.io/@lake/%EC%9D%B4%EB%B6%84%ED%83%90%EC%83%89-%ED%8C%8C%EB%9D%BC%EB%A9%94%ED%8A%B8%EB%A6%AD-%EC%84%9C%EC%B9%98Parametric-Search

	���� ���ϸ� �Ķ��Ʈ�� ��ġ�� �̺� Ž���� ������ ���̸� �⺻���� Ž�� ������ �����ϰ�,
	���� ���ϴ� �߾Ӱ�(mid)�� �迭�� Ư���� ���� ã�� ���� �ƴ�, ���� ���ϴ� ���ǿ� �´��� �˻��ؾ� �Ѵ�.

	
	### �ش� �������� ������ ���� ������ unsigned long long ���� ������ �ذ�ȴ�.
	### �ش� �ð�(mid)�� ���ǿ� �´���(n�� �̻��� �ɻ��� �� �ִ���)�� Ȯ���Ϸ��� 
	�ð�(mid)�� �� �ɻ������� �ɻ翡 �ɸ��� �ð����� ����� ���Ͽ� n�� ���ϸ� �ȴ�.
*/


