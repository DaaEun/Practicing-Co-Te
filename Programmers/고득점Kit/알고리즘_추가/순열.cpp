// 순열예제 - 가장 큰 두 자리 수 구하기
#include <iostream>
#include <algorithm>
using namespace std;
int N = 4;
int Nums[] = { 1,2,3,4 };

int solve(int cnt, int used, int val) {
	if (cnt == 2) return val;

	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (used & (1 << i)) continue;
		ret = max(ret, solve(cnt + 1, used | (1 << i), val * 10 + Nums[i]));
	}
	return ret;
}

int main() {
	cout << solve(0, 0, 0) << endl;
	return 0;
}