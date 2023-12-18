#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	if (x % y == 0) return y;
	else
		return gcd(y, x % y);
}

bool result(int a, int b, int x, int y) {
	if (a == x) x = 0;
	if (b == y) y = 0;
	int k = gcd(a, b);
	int max = a * b / k;

	for (int i = x; i <= max; i += a) {
		if (i == 0) continue;
		if (i % b == y) {
			cout << i << '\n';
			return true;
		}
	}

	return false;
}

int main(void) {

	int n;
	cin >> n;
	while (n--) {
		bool flag = false;
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		if (!result(a, b, x, y)) {
			cout << -1 << '\n';
		}
	}
}