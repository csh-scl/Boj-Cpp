#include <bits/stdc++.h>
using namespace std;

char val[64][64];
vector<char> result;

bool complete(int x, int y, int n) {
	char pivot = val[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (pivot != val[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void check(int x, int y, int n) {
	if (!complete(x, y, n)) {
		result.push_back('(');
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				check(x + n / 2 * i, y + n / 2 * j, n / 2);
			}
		}
		result.push_back(')');
	}

	else {
		result.push_back(val[x][y]);
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			val[i][j] = s[j];
		}
	} // 배열의 값 저장받기
	check(0, 0, n);
	for (auto k : result) cout << k;
}