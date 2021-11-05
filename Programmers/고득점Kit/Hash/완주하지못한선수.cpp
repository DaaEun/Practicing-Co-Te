/*
	���� ����
	������ ������ �������� �����濡 �����Ͽ����ϴ�. �� �� ���� ������ �����ϰ�� ��� ������ �������� �����Ͽ����ϴ�.

	�����濡 ������ �������� �̸��� ��� �迭 participant�� ������ �������� �̸��� ��� �迭 completion�� �־��� ��, 
	�������� ���� ������ �̸��� return �ϵ��� solution �Լ��� �ۼ����ּ���.


	���ѻ���
	- ������ ��⿡ ������ ������ ���� 1�� �̻� 100,000�� �����Դϴ�.
	- completion�� ���̴� participant�� ���̺��� 1 �۽��ϴ�.
	- �������� �̸��� 1�� �̻� 20�� ������ ���ĺ� �ҹ��ڷ� �̷���� �ֽ��ϴ�.
	- ������ �߿��� ���������� ���� �� �ֽ��ϴ�.
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// map�� �ε����� ���ڿ��� ���� �� �ִ� �迭�̶�� ��������.
string solution(vector<string> participant, vector<string> completion) {

	string answer = "";

	map<string, int> map;
	int i;
	for (i = 0; i < completion.size(); i++) {
		map[completion[i]]++;
		map[participant[i]]++;
	}
	map[participant[i]]++;

	for (auto m : map) {	// �迭 ��ҿ� ���� �ڷ����� ������ �ϹǷ�, auto Ű���带 ����ؼ� �߷��ϵ��� �ϴ� ���� �̻���.
		if (m.second % 2 != 0)	//map�� second : value
			answer = m.first;	//map�� first : key
	}
	return answer;
}