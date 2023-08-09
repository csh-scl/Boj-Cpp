#include <bits/stdc++.h>
using namespace std;

// 그냥 n번 순회하면서 n회 비교하면 시간 복잡도 (n^2) 실패 but stack 을 이용하면 O(N) 풀이가능

// a 출발 1번 b 도착 3번

// 하노이탑 재귀문제 핵심은 종료 조건과 일반적인 규칙을 찾기만 하면 된다!!.
void hanoi(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}
	else {
		hanoi(a, 6 - a - b, n - 1);
		cout << a << ' ' << b << '\n';
		hanoi(6 - a - b, b, n - 1);
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	int result = 1;
	for (int i = 1; i <= num; i++) {
		result *= 2;
	}
	cout << result - 1 << '\n';
	hanoi(1, 3, num);
}