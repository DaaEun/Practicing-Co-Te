/*
	���� ����
	��ȭ��ȣ�ο� ���� ��ȭ��ȣ ��, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ���Ϸ� �մϴ�.
	��ȭ��ȣ�� ������ ���� ���, ������ ��ȭ��ȣ�� �������� ��ȭ��ȣ�� ���λ��Դϴ�.


	������ : 119
	���ؿ� : 97 674 223
	������ : 11 9552 4421
	��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭 phone_book �� solution �Լ��� �Ű������� �־��� ��, 
	� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ������ false�� �׷��� ������ true�� return �ϵ��� solution �Լ��� �ۼ����ּ���.


	���� ����
	- phone_book�� ���̴� 1 �̻� 1,000,000 �����Դϴ�.
	- �� ��ȭ��ȣ�� ���̴� 1 �̻� 20 �����Դϴ�.
	- ���� ��ȭ��ȣ�� �ߺ��ؼ� ������� �ʽ��ϴ�.
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool solution(vector<string> phone_book) {
	
	bool answer = true;
	map<string, int> map;

	for (int i = 0; i < phone_book.size(); i++) {
		map[phone_book[i]] = 1;
	}
	for (int i = 0; i < phone_book.size(); i++) {
		string phone_num = "";
		for (int j = 0; j < phone_book[i].length() - 1; j++) {	//length() : ���ڿ��� ����
			phone_num += phone_book[i][j];
			//cout << phone_num << endl;
			if (map[phone_num]) {	//map[phone_num]�� �ش� phone_num�� �����ϸ� 1 -> true
				//cout << "IF "<< map[phone_num] << endl;
				return false;
			}
		}
	}

	return answer;
}