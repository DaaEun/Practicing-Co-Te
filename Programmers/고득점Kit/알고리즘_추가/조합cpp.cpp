// 조합예제 - 가장 큰 두 수의 합 구하기
#include <iostream>
#include <algorithm>
using namespace std;
int N = 4;
int Nums[] = { 1,2,3,4 };

int solve(int pos, int cnt, int val) {
	if (cnt == 2) return val;
	if (pos == N) return -1;

	int ret = 0;
	ret = max(ret, solve(pos + 1, cnt + 1, val + Nums[pos]));
	ret = max(ret, solve(pos + 1, cnt, val));
	
	return ret;
}

int main() {
	cout << solve(0, 0, 0) << endl;
	return 0;
}