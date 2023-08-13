#include <bits/stdc++.h>
using namespace std;

int val[130][130];

int blue = 0; // 1의 개수
int red = 0; // 0의 개수
int pivot = -1;

bool isPaper(int x, int y, int n) {
	pivot = val[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (pivot != val[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void solve(int x, int y, int n) {
	if (!isPaper(x, y, n)) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				solve(x+ n/2 * i, y + n/2 *j, n / 2);
			}
		}
	}

	else {
		if (pivot == 0) red++;
		else blue++;
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> val[i][j];
		}
	}
	
	solve(0, 0, n);
	cout << red << '\n' << blue;
}