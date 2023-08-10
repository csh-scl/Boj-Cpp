#include <bits/stdc++.h>
using namespace std;

// 그냥 n번 순회하면서 n회 비교하면 시간 복잡도 (n^2) 실패 but stack 을 이용하면 O(N) 풀이가능

// a 출발 1번 b 도착 3번

int hanoi(int n, int b, int c) {
	if (n == 0) {
		return 0;
	}
	int half = 1 << (n - 1);
	if (b < half && c < half) return hanoi(n - 1, b, c);
	if (b < half && c >= half) return half * half + hanoi(n - 1, b, c - half);
	if (b >= half && c < half) return 2 * half * half + hanoi(n - 1, b - half, c);
	return 3 * half * half + hanoi(n - 1, b - half, c - half);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	cout << hanoi(a, b, c);
}